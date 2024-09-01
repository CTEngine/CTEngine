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

	// BIT WISE OPERATORS
	// STRAIGHT FORWARD LOGICAL OPERATORS
	// REGULAR LOGICAL OPERATORS
	// LOGICAL OPERATORS, or and
	// OPERATORS FOR VALUES THAT ARE ZERO OR NOT
	// CONDITIONALS - CHANGE WHAT CODE IS EXE BY THE VALUE OF THINGS. (CONTROL FLOW)(LOGICAL OPERATORS CONTROL THIS)

	int x = 5;
	int y = 10;
	int z = 12;

	// AND/OR (|, &)
	x = 0;
	x = x | (1 << 4); // OR - SETS BITS IN THE VALUE IF EITHER OF ITS TWO OPERANDS HAPPEN TO HAVE THAT BITS SET.
	x = x | (1 << 8); // 
	x = x & (1 << 4); // AND - REQUIRES BOTH - USED TO DO SOME MASKING

	// NOT (~) = INVERTS THE VALUE
	x = 0;
	x = (1 << 4) | (1 << 8) | (1 << 16) | (1 << 20);
	x = ~x; // Gives Exact Opposite of above in (HEX).

	// EXCLUSIVE OR (XOR) (^) = INVERTS - RUNS AND/OR CONCEPT BUT LEAVES OUT THE AND CONCEPT AND JUST RUNS THE OR PART OF THE STATEMENT.
	x = (1 << 4) | (1 << 8);
	y = (1 << 8) | (1 << 16);
	x = x^y;
	x = x^y;
	// x = x ^ (1 << 8);
	// CRYPTOGRAPHY USES XOR COMMANDS (^) A LOT FOR ENCRYPTION ETC.




	// SHIFTING VISUAL (HEX).
	/*
	
	    8421
	00000001
	00000010
	00000100
	00001000
	
	*/

	x = -y + z + x*z + y/z - z;  // Not able to use Powers, z^2 / Use C-runtime Library for (pow).


	// HEXIDECIMAL NOTES CONT.

	x = 0xA; // HEX for #10.
	
	// SHIFT OPERATOR
	x = x << 4;
	x = x >> 4;
	x = x << 4;
	x = x >> 4;
	x = x << 4;

	// SHIFT BY 1 TO THE LEFT = * 2
	// SHIFT BY 1 TO THE RIGHT = / 2

	// BARREL SHIFT OPERATOR

	// SHIFT TO CARRY 


	// "BOOLEAN" - Boolean Value, Is something (True); or (False); "on or off", "set or not".
	int x = 0; // FALSE - (False); (off); (notset);
	int y = 1; // TRUE - (True); (on); (set);
	int z = 19423042; // TRUE - (True); (on); (set);
	int w = -349; // TRUE - (True); (on); (set);

	// IN (C) THINGS ARE EITHER ZERO OR THEY ARE NOT.
	// A VALUE OF ZERO (0) IS APPLIED IF (NOT TRUE, FALSE) IF (1) | (NON-ZERO, TRUE) IF TRUE



	// int notequal = (z != w);
	// int xor = (less ^^ greater);

	// CONTROL FLOW
	/* Build Control Flows Using OutputDebugStringA:
	* 
	OutputDebugStringA("Z is less than W\n");
	OutputDebugStringA("W is less than Z\n");
	OutputDebugStringA("W is equal to Z\n");

	*/

	// CONTROL FLOW STATEMENT
	// how to fill in if() - (z < w)

	//RAW FORMAT 4
	int less = (z < w);
	int greater = (z > w);
	int equal = (z == w);
	int notequal = (z != w);
	// int and = (less && greater);
	// int xor = (less != greater);
	// int xor = (less ^^ greater); // switch to xor for future finishing notes // not done here.

	if(less)
	{
		OutputDebugStringA("Z is less than W\n"); // LESS THAN
	}
	else if (greater)
	{
		OutputDebugStringA("Z is greater than W\n"); // GREATER THAN
	}
	else if (equal)
	{
		OutputDebugStringA("Z is equal to W\n"); // EQUAL
	}
	else
	{
		OutputDebugStringA("WHAT??? Z is not equal to W\n"); // NOT EQUAL
	}

	// RAW FORMAT 3
	int less = (z < w);
	int greater = (z > w);
	int equal = (z == w);
	int notequal = (z != w);

	if(less)
	{
		OutputDebugStringA("Z is less than W\n"); // LESS THAN
	}
	else if(greater)
	{
		OutputDebugStringA("Z is greater than W\n"); // GREATER THAN
	}
	else if(equal)
	{
		OutputDebugStringA("Z is equal to W\n"); // EQUAL
	}
	else // NOT EQUAL
	{
		OutputDebugStringA("WHAT??? Z is not equal to W\n"); // NOT EQUAL
	}

	// RAW FORMAT 2 + IF STACKING | ALLOWS A RUSSIAN NESTING DOLL CONCEPT | THAT ALLOWS THE PROGRAM TO CHECK THEM ALL, THE SPIT OUT THE RIGHT ONE.
	// Combining statements:
	// || (means or) && (means and)
	// if(less || greater)
	// {
	// 
	// }
	// else if
	// {
	// 
	// }
	if(less)
	{
		OutputDebugStringA("Z is less than W\n"); // LESS THAN
	}

	else if(greater)
	{
		OutputDebugStringA("Z is greater than W\n"); // GREATER THAN
	}

	else if(equal)
	{
		OutputDebugStringA("Z is equal to W\n"); // EQUAL
	}
	else
	{
		OutputDebugStringA("WHAT??? Z is not equal to W\n"); // NOT EQUAL
	}

	// RAW FORMAT 1:
	// Nesting is not possible here, due to the if/else statement closing, and not allowing anymore else statements. Even with else if applied.
	// We break this up, above, to nest all OutputDebutStringAs all into (1) if/else statement.
	// AS SOON AS IT FINDS ONE THAT IS TRUE IT STOPS THE IF/ELSE LOOP
	if(less)
	{
		OutputDebugStringA("Z is less than W\n");
	}
	else
	{
		OutputDebugStringA("W is greater than Z\n");
	}
	else // Error will occur here, because we cannot list multiple else statements back to back like this.  Use method above to fix this.
	{
		OutputDebugStringA("W is equal to Z\n");
	}
	else
	{
		OutputDebugStringA("W is not equal to Z\n");
	}

	// Creating a INT|WHILE|LOOP:
	// Does the shift operator, x = x << 4; and repeats it as long as the value isn't "True".
	int x = 0;

	x = 0xa;

	while (x != 0)
	{
		x = x << 4;
	}

	int condition = (x != 0);
	while(condition)
	{
		x = x << 4;
		condition = (x != 0);
	}

	/*

	// Create an Infinite Loop:
	int x = 0;

	x = 0xa;
	while(1)
	{
		x = x << 4;
		// add BREAK OUT POINT here.
	}

	// If you want to BREAK OUT of this loop, add this statement.
	// BREAK OUT POINT:
	if(x == 0)
	{
		break;
	}

	*/

	// LOOPS:
	
	// do-WHILE LOOP - MOVE THE TEST UNTIL AFTER THE FIRST ONE.

	// FOR LOOP: These are generally used "over" while loops because makes it easier to see what the main sorta reason for the loop is.
	int x = 0;

	for (x = 0xa; // Once at the beginning.
		(x != 0); // This is the condition for the loop.
		x = x << 4) // The thing to do every iteration.
	{
		// More stuff happens here!
		OutputDebugStringA("We are in the loop. \n");
	}

	// THIS LOOP TRANSLATES INTO THE BELOW:

	x = 0xa;
	while (x != 0)
	{
		OutputDebugStringA("We are in the loop. \n");
		x = x << 4;
	}


	// SWITCHES


}