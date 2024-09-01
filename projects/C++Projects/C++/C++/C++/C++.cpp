//  THIS IS AN INTRODUCTION TO C++ CREATED BY ARMOND DOMINA.
//
//
//  IT WILL FOLLOW ALONG WITH THIS LINK:
//	https://pisaucer.github.io/book-c-plus-plus/Beginning_Cpp_Through_Game_Programming.pdf
//  
//  EACH CHAPTERS "FILE" WILL BE LISTED IN THE SOURCE FILES.  ALLOWING FULL VIEW OF THE 
//  COMPLETED PROJECT FOR THAT CHAPTER, ALONG WITH NOTES TAKEN FROM READING.
//
//  AS EACH CHAPTER IS UN-FINISHED, THE CODE, SHOULD BE PERFORMED RIGHT HERE,
//  "ON THIS MAIN C++.CPP" FILE FOR NOW.
// 
// 
// 
// 
// 
// 
// 
//
//  PLEASE ENJOY THIS COURSE, AS I PAINSTAKINGLY AM JUST NOW TEACHING MYSELF HOW TO CODE!
//  HERE WE GO!  THE FUN BEGINS AT INT MAIN()
//=========================================================================================


//=========================================================================================
// Chapter 1 Default Typed Code:

/*

// Game Over
// A first C++ program

#include <iostream>

int main()
{
	std::cout << "Game Over!" << std::endl;
	return 0;
}

*/

/*

// Game Over 2.0
// Demonstrates a using directive

#include <iostream>
using namespace std;

int main()
{
	cout << "Game Over!" << endl;
	return 0;
}

*/

/*

// Game Over 3.0
// Demonstrates using declarations

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	cout << "Game Over!" << endl;
	return 0;
}

*/

// END of Chapter 1 Code.
//=========================================================================================

//=========================================================================================
//     BEGIN.
//
// Title:       Game Over
// Creator:     Armond Domina
//
// This is a reverse engineering versions of a joke on Hello World.  However, you get the point!.
//=========================================================================================


// These items are termed preprocessor, they runs before the compiler does its thing.
// It tells the preprocessor to include the contents of another file.
// including the "iostream", which is starndard library, and is a good "header file" used
// to "display output".  The <>S tell the compiler to find the file where it keeps all
// the file that came with the compiler.
#include <iostream>


// Functions:  A function is a group of programming code that can do some work and return
// a value. In this case, int indicates that the function will return an "integer value".
// All function headers have a pair of parentheses after the function name.


int main()
{
	// "Game Over!" - is a String, anything "between" the quotes is a string literal.
	// "cout" - is an object, defined in the file iostream, that's used to send data to the
	// standard output stream.
	// "output operator (<<)" - think of this like a funnel; it takes whatever's on the open
	// side and funnels it to the the pointy side. So the string is funneled to the standard 
	// output -- the screen.
	// "std" - is used to prefix cout, to tell the compiler cout from within the system <iostream>
	// "::" - You prefix a namespace using the scope resolution operator (::).
	// ""std::endl" - endl is from <iostream> and also an obj in the std namespace.
	// Sending endl to the standard output acts like pressing the Enter Key in the Console Window.
	//
	// ";" - semicolon.  Ending a line that is a "statement" needs a ;
	// *** WARNING *** "ALL of your "statements" must end with a semicolon--otherwise, your compiler
	// will complain with an error message and your program won't compile.
	//
	// "return 0;" - The last statement in the function returns 0 to the OS (Operating System)
	// Returning 0 from main() is a way to indicate that the program ended without a problem.
	// The OS doesn't have to do anything with the return value.  In general, you can simply
	// return 0 like done here.
	// TRICK - You can create .bat (batch files, in Windows), to allow you to hold your code
	// open if the window closes to fast for you. Implement the below.
	// "game_over.exe"
	// "pause"
	// Put these without quotes in a filename.bat file to keep window from closing to fast.
	//
	// Next!!!  I hope you've made it this far!!  
	//
	// STD Namespace - Not to be confused with STD OnFace, LOL :).
	// Because it's so common to use elements from the std namespace, there are two methods
	// we can use for directly accessing these elements.  This saves us the effort of spamming
	// std:: prefix all the time throughout our code.
	//
	// another quick output command that does the same thing, sorta. "printf("Hello World\n");"



	std::cout << "Game Over!" << std::endl;
	return 0;
}

/* THIS BLEW MY MIND, BEING ABLE TO RUN MY PROGRAM AND OPEN ANOTHER WINDOW AND RUN A PHYSICAL PROGRAM.
* 
* 

#include <cstdlib>
int main() 
{
	std::cout << "Game Over!" << std::endl;
	std::system("start cmd /k notepad.exe");
	return 0;
}

*/