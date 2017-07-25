/*
 * Main.cpp
 *
 *  Created on: 24 Jun 2017
 *      Author: Daniel Tran
 *
 *  This file acts as the main interface for users when the program is run.
 *
 *  Currently, the program is run by accessing it through the command line,
 *  and prints a username based on the specified format.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Wordtypes.h"
#include "datatypes/Random.h"
#include "UnitTests.h"

/*
 * This method is the logical structure of the program.
 * The program name and a format string are taken as inputs, and
 * result in a printed username based on said format.
 */
int main(int argc, char* argv[]){

	/*
	//Unit tests are run from main; look into proper unit testing suites?
	//This runs before randomSeed() to ensure consistent results when testing.
	Unit unit;
	unit.testAll();
	return 0;
	//*/

	//Ensure the printed output is not cached.
	randomSeed();

	const int idealArgs = 2;
	char* data;

	//Test if the correct number of arguments have been supplied.
	if (argc == idealArgs){

		//Accept input when just 2 parameters are given.
		data = argv[1];
	}else if (argc < idealArgs){

		//Use a preset string format when too few parameters are given.
		data = "wW1#";
	}else{

		//Exit when too many parameters are given.
		printf("ERROR: Too many arguments supplied. Only 2 arguments are allowed. \n");
		return 0;
	}

	//Initialise the username as an array of words with a head pointer.
	const int wordCount = strlen(data);
	word* words = wordtypeInitialise(data);

	//Print the username and free up any memory used.
	wordtypePrint(words, wordCount);
	wordtypeFree(words, wordCount);

	return 0;
}
