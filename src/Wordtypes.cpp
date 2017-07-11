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
#include "Random.h"
#include "DatatypesSingleChar.h"
#include "DatatypesMultiChar.h"

struct word;

char* provideUppercase(char* output){
	//char* output = provideLowercaseNoun();

	for (int i = 0; i < strlen(output); i++){
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
