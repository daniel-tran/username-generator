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

char* provideLowercaseNoun(){
	char* data;
	int index = randomIndex();

	switch(index){
	case 1: data = "asparagus"; break;
	default: data = "zoo";
	}

	return provideData(data);
}

char* provideUppercaseNoun(){
	char* output = provideLowercaseNoun();

	output = provideUppercase(output);

	return output;
}

char* provideLowercaseVerb(){
	char* data;
	int index = randomIndex();

	switch(index){
	case 1: data = "act"; break;
	default: data = "zap";
	}

	return provideData(data);
}

char* provideUppercaseVerb(){
	char* output = provideLowercaseVerb();

	output = provideUppercase(output);

	return output;
}

char* provideLowercaseAdjective(){
	char* data;
	int index = randomIndex();

	switch(index){
	case 1: data = "angular"; break;
	default: data = "zealous";
	}

	return provideData(data);
}

char* provideUppercaseAdjective(){
	char* output = provideLowercaseAdjective();

	output = provideUppercase(output);

	return output;
}




//An unofficial method, it *might* be included eventually.
char* provideCapitalisedWord(){

	char* output;
	int index = randomIndex();

	switch (index){
	case 0: output = "Axiom"; break;
	default: output = "Zanguard";
	}

	return output;
}

char* provideLowercaseWord(){
	char* output;
	int index = randomIndex();

	switch (index){
	case 0: output = "anchor"; break;
	default: output = "zucchini";
	}

	return output;
}

char* provideUppercaseWord(){
	char* output;
	int index = randomIndex();

	switch (index){
	case 0: output = "ASCOT"; break;
	default: output = "ZOOM";
	}

	return output;
}



char* provideRandomWord(){

	int length = randomIndex();
	char* output = (char*)malloc(sizeof(char)*length + 1);

	for (int i = 0; i < length; i++){
		output[i] = randomLetter();
	}
	output[length] = '\0';

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
