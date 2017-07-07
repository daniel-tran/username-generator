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

int main(){
	char* data = "lwl";

	const int wordCount = strlen(data);
	word* words = (word*) malloc(wordCount * sizeof(word));

	for (int i = 0; i < wordCount; i++){
		words[i].data = construct(data[i]);
	}

	for (int c = 0; c < wordCount; c++){
		printf("%s", words[c].data);
	}

	free(words);

	return 0;
}
