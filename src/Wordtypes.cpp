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

struct word;

char* provideWord(){

	char* output;
	int index = rand() % 100;

	switch (index){
	case 0: output = "Axiom"; break;
	default: output = "Zanguard";
	}

	return output;
}

char* provideLowercaseWord(){
	char* rawWord = provideWord();

	for (unsigned int i = 0; i < strlen(rawWord); i++){
		rawWord[i] = tolower(rawWord[i]);
	}

	return rawWord;
}



char* construct(char type){

	char* output;

	switch (type){
	case 'w': return provideWord();

	default: return "Solosis";
	}

	return output;
}
