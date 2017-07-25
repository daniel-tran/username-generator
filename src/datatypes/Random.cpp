/*
 * Random.cpp
 *
 *  Created on: 12 Jul 2017
 *      Author: Administrator
 *
 *  This file contains methods for producing randomised data for a wide
 *  range of purposes.
 */

#include <stdlib.h>
#include <unistd.h>

#include "Random.h"

/*
 * Randomises the calculation seed for different values.
 * Do not call if you need random data to be consistent (e.g. testing).
 */
int randomSeed(){

	//Program will mostly be a different process, ensuring better randomness.
	srand(getpid());

	return 0;
}

/*
 * Returns a random number between 0 and 99 inclusive.
 */
int randomIndex(){
	return rand() % 100;
}

/*
 * Returns a random number between 0 and 25 inclusive.
 */
int randomLetterIndex(){
	return rand() % 26;
}

/*
 * Returns a random number between 0 and 9 inclusive.
 */
int randomSingleDigit(){
	return rand() % 10;
}

/*
 * Returns a random letter in the printable ASCII character range.
 */
char randomLetter(){

	/*
	 * In ASCII, spacebar is the lowest value printable character.
	 * ~ is the highest printable character, so everything in between
	 * ' ' and '~' could be produced from this method.
	 */
	return (' ' + ( rand() % ('~' - ' ') ) );
}
