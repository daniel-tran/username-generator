/*
 * Random.cpp
 *
 *  Created on: 12 Jul 2017
 *      Author: Administrator
 */

#include <stdlib.h>

#include "Random.h"

int randomIndex(){
	return rand() % 100;
}

int randomLetterIndex(){
	return rand() % 26;
}

int randomSingleDigit(){
	return rand() % 10;
}

char randomLetter(){
	return (' ' + ( rand() % ('~' - ' ') ) );
}
