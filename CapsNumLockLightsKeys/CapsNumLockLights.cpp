#include "LFX2.h"
#include <windows.h>
#include <winuser.h>
#include <tchar.h>
#include <list>

LFX2UPDATE updateFunction;
LFX2SETLIGHTCOL setLightColor;
LFX2LIGHT lightFunction;
HINSTANCE alienFXLib;

LFX_COLOR COLOR_RED = { 0xFF ,  0x00, 0x00, 0xFF };
LFX_COLOR COLOR_YELLOW = { 0xFF , 0xFF, 0x00, 0xFF };
LFX_COLOR COLOR_DEFAULT = { 0x28 , 0xA0, 0xF0, 0xFF };
int colorDefault = 0x0028A0F0;

bool currentCapitalKey = false;
bool currentNumLockKey = false;

bool oldCapitalKey = false;
bool oldNumLockKey = false;


void initializeLightFX()
{
	Sleep(60000); //startup windows loading alienfx libs
	while (true)
	{
		alienFXLib = LoadLibrary(_T(LFX_DLL_NAME));
		if (alienFXLib) {
			break;
		}
		Sleep(500); //waiting alienfx libs
	}

	LFX2INITIALIZE initFunction = (LFX2INITIALIZE)GetProcAddress(alienFXLib, LFX_DLL_INITIALIZE);
	updateFunction = (LFX2UPDATE)GetProcAddress(alienFXLib, LFX_DLL_UPDATE);
	setLightColor = (LFX2SETLIGHTCOL)GetProcAddress(alienFXLib, LFX_DLL_SETLIGHTCOL);
	lightFunction = (LFX2LIGHT)GetProcAddress(alienFXLib, LFX_DLL_LIGHT);

	while (initFunction() != LFX_SUCCESS);
}

bool isKeyActive(unsigned int key) 
{
	return (GetKeyState(key) & 0x0001) != 0;
}

void forceUpdateLights() 
{
	oldNumLockKey = !isKeyActive(VK_NUMLOCK);
	oldCapitalKey = !isKeyActive(VK_CAPITAL);
}

int main()
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	initializeLightFX();
	forceUpdateLights();

	while (true)
	{
		currentCapitalKey = isKeyActive(VK_CAPITAL);
		currentNumLockKey = isKeyActive(VK_NUMLOCK);
		int colorAll = currentCapitalKey ? LFX_YELLOW : colorDefault;
		LFX_COLOR color = currentNumLockKey ? COLOR_DEFAULT : COLOR_RED;

		if (currentCapitalKey ^ oldCapitalKey) {
			lightFunction(LFX_ALL, colorAll | LFX_FULL_BRIGHTNESS);
			setLightColor(0, 3, &color);
		}
		if (currentNumLockKey ^ oldNumLockKey) {
			setLightColor(0, 3, &color);
		}

		oldNumLockKey = currentNumLockKey;
		oldCapitalKey = currentCapitalKey;

		updateFunction();
	}
	FreeLibrary(alienFXLib);
	return 0;
}
