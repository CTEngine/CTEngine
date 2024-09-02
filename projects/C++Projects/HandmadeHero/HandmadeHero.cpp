//==============================================================================================================//
//																												//
//																												//
//											Welcome to Handmade Hero											//
//																												//
//																												//
//==============================================================================================================//

/*

	Author:		Armond Domina (ARM&)(ARM& - x64)
	Date:		9/01/2024

*/

/*

	STRUCTURAL TEMPLATE FOR CREATING OWN ENGINE/PROJECTS
	THIS WILL CHANGE 01, to 02 etc but this information is just placement, and not the actual build yet.
	This ensure that functions will work, and instances will create and actual code can be processed first before building.

	In Order for this program to function.  It has to be created right via using "Windows" rather than "Console"
	In Order to do so, Right Click on Project - > Go To Properties - > Left Pane "Linker" - > System - > SubSystem.
	Set this to Windows instead of Console, on a new project so this code will function properly.  Until We Figure out how to build
	It all via a Console App instead.

*/


// 30 mins in work with .bat files.
// almond milk power up.

#include <windows.h>
#include <stdio.h>
#include <iostream>

// Function definition

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
    // This is creation of the main window.
    std::cout << "CTEngines: Handmade Hero " << std::endl;
    MessageBoxA(0, "Handmade Hero ", "CTEngines: Handmade Hero ", MB_OK|MB_ICONINFORMATION );
    return 0;
}