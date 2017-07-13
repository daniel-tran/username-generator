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
	word* words = (word*) malloc(wordCount * sizeof(word));

	for (int i = 0; i < wordCount; i++){
		words[i].data = construct(data[i]);
		words[i].type = data[i];
	}

	for (int c = 0; c < wordCount; c++){
		printf("%s", words[c].data);
	}

	//Free up the stored strings and their primary memory allocations
	for (int k = 0; k < wordCount; k++){
		free(words[k].data);
	}
	free(words);

	return 0;
}
