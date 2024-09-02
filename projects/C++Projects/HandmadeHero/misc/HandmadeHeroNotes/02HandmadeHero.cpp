//==============================================================================================================//
//																												//
//																												//
//											Welcome to Handmade Hero											//
//																												//
//																												//
//==============================================================================================================//

/*

	Author:		Armond Domina (ARM&)(ARM& - x64)
	Date:		8/30/2024

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

#include <windows.h>
#include <stdio.h>
// #include <winbase.h>
// #include <iostream>

// Function definition

void bar(void)
{
	int BarVariable;

	BarVariable = 100;
}


void foo(void)
{

	/*
	// char *Foo = "This is the first thing we have actually printed.\n";
	OutputDebugStringA(
		"Handmade Hero \r\n");

	// WINDOWS - \r\n
	// UNIX - \n
	// (printf) = Mostly used by Console C++ not C Engine Building.  C uses the above OutputDebugStringA method instead.
	// printf("This is a thing. \n");
	*/

	int FooVariable;

	FooVariable = 200;

	bar();
}

// int WINAPI WinMain(_In_ HINSTANCE p_hinstance, _In_opt_ HINSTANCE p_hprev_instance, _In_ LPSTR p_cmd_line, _In_ int p_show_cmd) {

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	// LPSTR p_cmd_line,
	// int p_show_cmd)
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)

{

	// unsigned & char can be interchangeable in order of operations.
	// Example: unsigned char SmallU; vs char unsigned SmallU;

	/*
	char SmallS; // 8 bits - 256 different values [-128,127].
	char unsigned SmallU; // 8 bits unsigned - 256 different values [0,255].

	short MediumS; // 16 bits - 65536
	short unsigned MediumU;

	int LargeS; // 32bits - Roughly 4 Billion
	int unsigned LargeU;
	*/

	// This returns 256 (Correct Value) *OVERFLOW*
	char unsigned Test;
	char unsigned* TestPointer;  // * infront turns TestPointer into assigned memory?

	TestPointer = &Test; // & infront of Test means, where is this in memory?

	/*
		When a char/int etc gets called it gets put into Memory.
		This is called the Stack.
		No need to microwrite the code yourself to get it from the memory stack.  The Compiler is doing that for you.
		Assembly Code (Would Need to get the stack manually) In the further down the rabbit hole concept.

		This stacks grows as you add to it.  But once the functions complete it gets smaller.  Call/Return

	*/

	Test = 255;
	Test = Test + 1;

	/* This returns 0 (Wrong Value) *OVERFLOW*
	int Test2;
	char unsigned Test2;

	Test2 = 255;
	Test2 = Test2 + 1;
	*/

	/*
	int Integer;

	Integer = 5;
	Integer = 5 + 2;
	Integer = Integer + 7;
	*/

	foo();
}