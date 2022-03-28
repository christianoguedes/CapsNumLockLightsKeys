// SDKSample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"

#include "C:\Program Files\Alienware\Alienware Command Center\AlienFX SDK\includes\LFX2.h"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <tchar.h>
#include <list>


//LFX2INITIALIZE initFunction;
//LFX2RELEASE releaseFunction;
//LFX2SETLIGHTCOL setLightColor;
//LFX2UPDATE updateFunction;
//HINSTANCE hLibrary;
//
//LFX_COLOR COLOR_RED = { 0xFF ,  0x00, 0x00, 0xFF };

//void ligthsColor(std::list<int> regions, LFX_COLOR color) {
//	for (int region : regions) {
//		setLightColor(0, region, &color);
//		updateFunction();
//		Sleep(50);
//	}
//}
//
//void initializeLightFx() {
//	initFunction = (LFX2INITIALIZE)GetProcAddress(hLibrary, LFX_DLL_INITIALIZE);
//	releaseFunction = (LFX2RELEASE)GetProcAddress(hLibrary, LFX_DLL_RELEASE);
//
//	setLightColor = (LFX2SETLIGHTCOL)GetProcAddress(hLibrary, LFX_DLL_SETLIGHTCOL);
//	updateFunction = (LFX2UPDATE)GetProcAddress(hLibrary, LFX_DLL_UPDATE);
//}
//
//int main()
//{
//
//	HINSTANCE hLibrary = LoadLibrary(_T(LFX_DLL_NAME));
//	initializeLightFx();
//	if (hLibrary)
//	{
//
//
//		LFX_RESULT result = initFunction();
//		if (result == LFX_SUCCESS)
//		{
//			ligthsColor({ 1 }, COLOR_RED);
//
//
//			std::cout << "Done.\r\n\r\nPress any key to finish ..." << std::endl;
//			_gettch();
//			result = releaseFunction();
//		}
//		else
//		{
//			switch (result)
//			{
//			case LFX_ERROR_NODEVS:
//				std::cout << "There is not AlienFX device available." << std::endl;
//				break;
//			default:
//				std::cout << "There was an error initializing the AlienFX device." << std::endl;
//				break;
//			}
//		}
//
//		FreeLibrary(hLibrary);
//	}
//	else
//		std::cout << "Failed to load LightFX.dll." << std::endl;
//
//	return 0;
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
