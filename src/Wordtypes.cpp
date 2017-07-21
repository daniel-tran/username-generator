/*
 * Wordtypes.c
 *
 *  Created on: 7 Jul 2017
 *      Author: Daniel Tran
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Wordtypes.h"
#include "datatypes/Random.h"
#include "datatypes/DatatypesSingleChar.h"
#include "datatypes/DatatypesMultiChar.h"

struct word;

word* wordtypeInitialise(char* data){

	const int wordCount = strlen(data);
	word* words = (word*) malloc(wordCount * sizeof(word));

	for (int i = 0; i < wordCount; i++){
		words[i].data = construct(data[i]);
		words[i].type = data[i];
	}

	return words;
}

int wordtypePrint(word* words, int wordCount){
	for (int c = 0; c < wordCount; c++){
		printf("%s", words[c].data);
	}

	return 0;
}

int wordtypeFree(word* words, int wordCount){
	for (int k = 0; k < wordCount; k++){

		words[k].data = NULL;
		words[k].type = 0;

		free(words[k].data);
		free((char*)words[k].type);
	}
	free(words);

	return 0;
}

char* provideUppercase(char* output){

	const int length = strlen(output);

	for (int i = 0; i < length; i++){
		output[i] = toupper(output[i]);
	}

	return output;
}

char* provideData(char* data){
	char* output = (char*)malloc( (sizeof(char)*strlen(data)) +1);
	strcpy(output, data);

	output[strlen(data)] = '\0';

	return output;
}

char* provideException(char input){
	char* output = (char*)malloc(sizeof(char)*2);

	output[0] = input;
	output[1] = '\0';
	return output;
}


char* construct(char type){

	char* output;

	switch (type){
	case 'w': return provideLowercaseWord();
	case 'W': return provideUppercaseWord();
	case 'l': return provideLowercaseLetter();
	case 'L': return provideUppercaseLetter();
	case 'r': return provideRandomLetter();
	case 'R': return provideRandomWord();
	case '#': return provideNumber();
	case 's': return provideSpace();
	case 'S': return provideSeparator();
	case 'p': return providePunctuation();
	case 'P': return provideCapitalisedWord();

	case 'n': return provideLowercaseNoun();
	case 'N': return provideUppercaseNoun();
	case 'v': return provideLowercaseVerb();
	case 'V': return provideUppercaseVerb();
	case 'a': return provideLowercaseAdjective();
	case 'A': return provideUppercaseAdjective();


	default: return provideException(type);
	}

	return output;
}
