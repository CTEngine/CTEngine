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

struct projectile
{
	// NOTE(ARM&): These are the members, or "fields", of this structure!

	char unsigned IsThisOnFire; // NOTE(ARM&): 1 if it's on fire, 0 of it's not
	int Damage; // NOTE(ARM&): This is how much damage it does on impact.
	int ParticlesPerSecond; // NOTE(ARM&): For special effects.
	short HowManyCooks; // NOTE(ARM&): Too many cooks?
	
	// Char(Un)			Int(DMG)		 Int(Part)		   Short(Cooks)		 Total
	// 1 byte     +     4 bytes     +    4 bytes     +     2 bytes     =     11 bytes

};

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

	/*
	// This returns 256 (Correct Value) *OVERFLOW*
	char unsigned Test;
	char unsigned *TestPointer;  // * infront turns TestPointer into assigned memory?

	TestPointer = &Test; // & infront of Test means, where is this in memory?
	*/

	/*
		When a char/int etc gets called it gets put into Memory.
		This is called the Stack.
		No need to microwrite the code yourself to get it from the memory stack.  The Compiler is doing that for you.
		Assembly Code (Would Need to get the stack manually) In the further down the rabbit hole concept.

		This stacks grows as you add to it.  But once the functions complete it gets smaller.  Call/Return
	
	*/

	/*
	Test = 255;
	Test = Test + 1;
	*/

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

	/*
	
		//HEXADECIMAL NOTES:

		0	 -	0
		1	 -	1
		2	 -	2
		3	 -	3
		4	 -	4
		5	 -	5
		6	 -	6
		7	 -	7
		8	 -	8
		9	 -	9
		10	 -	A
		11	 -	B
		12	 -	C
		13	 -	D
		14	 -	E
		15	 -	F

		pre-fix 0x
		0xA = 10
		0xAA = 16*10 + 10 = 170
		0xAAA = 16*16*10 + 16*10 + 10

		444 = 4*100 + 4*10 + 4

	*/

	// To make Test more complicated we can make it have a projectile.
	// int Test;
	projectile Test;

	// Compile time, to tell you the size of something.
	// Example:  int Size = sizeof(Test);
	int SizeOfChar = sizeof(char unsigned);
	int SizeOfInt = sizeof(int);
	int SizeOfProjectile = sizeof(projectile);
	int SizeOfTest = sizeof(Test);

	// These are all order dependent.
	Test.IsThisOnFire = 1;
	Test.Damage = 3249839 + Test.IsThisOnFire;
	Test.ParticlesPerSecond = 23490830;
	Test.HowManyCooks = 50;

	// Shorts:
	projectile *ProjectilePointer = &Test;
	short *MrPointerMan = (short*)&Test; // Signed
	unsigned short *MrPointerMan = (unsigned short*)&Test; // Unsigned

	// Make (1 or 40) Projectiles.
	projectile Projectiles[40];
	projectile Projectile0;
	projectile Projectile1;

	// Method 1
	int WhichProjectile;
	WhichProjectile = 1;

	// Method 2
	int WhichProjectile = 1;
	if (WhichProjectile == 1)
	{
		// do something projectile 1.
	}
	else
	{
		// do something to projectile 0 instead.
	};

	Projectiles[4];

	int WhichProjectile = 4;
	Projectiles[WhichProjectile];

	projectile* ProjectilePointer = Projectiles;

	int SizeOfProjectiles = sizeof(Projectiles); // Expect it to be 16*40.
	int SizeOfProjectilePointer = sizeof(ProjectilePointer); // Expect it to be 4.

	Projectiles[30].Damage = 60;
	(ProjectilePointer + 30)->Damage = 100;

	char  *BytePointer = (char *)ProjectilePointer;
	BytePointer = BytePointer + 30*sizeof(projectile);
	// Correct Infor relating to below.
	projectile *Thirty = (projectile *)BytePointer;
	Thirty->Damage = 200;

	((projectile*)((char*)ProjectilePointer + 30 * sizeof(projectile)))->Damage = 200;

	// (->) or (.) = 
	//projectile Test;
	//Test.Damage;

	// projectile *Test;
	// Test->Damage

	// Turn into above
	// BytePointer->Damage = 200; // Not possible, need to turn this back into a projectile pointer.

	// unsigned char Test;

	// Test = 200;

	// unsigned short Test;
	
	/*
	endianness
		// The Term below we did is technically a little endian layout.
		little endian	// If the low order byte comes first in memory. - x86, arm, x64
		big endian		// If the high order byte comes first in memory. - powerpc, xbox360, PS3 (photoshop perhaps)
	*/

	// Test = 500;

	/* Binary (Machine) Translation.
	

	Test =	500;

			52 1
			15 2631 8421
			26 8426
	 0000 0001 1111 0100

	*/

}