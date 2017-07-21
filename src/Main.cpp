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

int main(){

	//*
	Unit unit;
	unit.testAll();
	//*/

	randomSeed();

	char* data = "wWl#";

	const int wordCount = strlen(data);
	word* words = wordtypeInitialise(data);

	wordtypePrint(words, wordCount);
	wordtypeFree(words, wordCount);

	return 0;
}
