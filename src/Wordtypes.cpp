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

char* provideUppercase(char* output){
	//char* output = provideLowercaseNoun();

	for (int i = 0; i < strlen(output); i++){
		output[i] = toupper(output[i]);
	}

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

	char* output = (char*)malloc( (sizeof(char)*strlen(data)) +1);
	strcpy(output, data);

	output[strlen(data)] = '\0';

	return output;
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

	char* output = (char*)malloc( (sizeof(char)*strlen(data)) +1);
	strcpy(output, data);

	output[strlen(data)] = '\0';

	return output;
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

	char* output = (char*)malloc( (sizeof(char)*strlen(data)) +1);
	strcpy(output, data);

	output[strlen(data)] = '\0';

	return output;
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

char* provideLowercaseLetter(){
	char* out = (char*)malloc(sizeof(char)*2);
	out[0] = 'a'+randomLetterIndex();
	out[1] = '\0';

	return out;
}

char* provideUppercaseLetter(){
	char* out = provideLowercaseLetter();
	out[0] = toupper(out[0]);

	return out;
}

char* provideNumber(){

	int index = randomSingleDigit() + 2; //+2 ensures at least 1 character and \0
	char* out = (char*)malloc(sizeof(int) * index);

	for (int i = 0; i < index; i++){
		out[i] = '0' + randomSingleDigit();
	}

	out[index] = '\0';

	return out;
}

char* provideSpace(){
	return " ";
}

char* provideSeparator(){

	char* out;
	int index = rand() % 7;

	switch(index){
	case 0: out = "-"; break;
	case 1: out = "_"; break;
	case 2: out = provideSpace(); break;
	case 3: out = "~"; break;
	case 4: out = "|"; break;
	case 5: out = "*"; break;
	default: out = ".";
	}

	return out;
}

char* providePunctuation(){

	char* out;
	int index = rand() % 7;
	switch(index){
	case 0: out = ","; break;
	case 1: out = ";"; break;
	case 2: out = ":"; break;
	case 3: out = "'"; break;
	case 4: out = "\""; break;
	case 5: out = "?"; break;
	default: out = "!";
	}

	return out;
}

char* provideRandomLetter(){
	char* output = (char*)malloc(sizeof(char)*2);
	output[0] = randomLetter();
	output[1] = '\0';

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
