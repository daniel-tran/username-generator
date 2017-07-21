/*
 * Main.cpp
 *
 *  Created on: 24 Jun 2017
 *      Author: Daniel Tran
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Wordtypes.h"
#include "datatypes/Random.h"
#include "UnitTests.h"

int main(int argc, char* argv[]){

	/*
	Unit unit;
	unit.testAll();
	//*/

	randomSeed();

	char* data;
	if (argc == 1){
		data = "wW1#";
	}else{
		data = argv[1];
	}

	const int wordCount = strlen(data);
	word* words = wordtypeInitialise(data);

	wordtypePrint(words, wordCount);
	wordtypeFree(words, wordCount);

	return 0;
}
