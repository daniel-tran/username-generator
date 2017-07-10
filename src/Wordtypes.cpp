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
	default: output = "zabaglione";
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

	int index = (rand() % 10) + 2;
	char* out = (char*)malloc(sizeof(int) * index);

	for (int i = 0; i < index; i++){
		out[i] = 48 + (rand() % 10);
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
	case 0: out = "-";
	case 1: out = "_";
	case 2: out = provideSpace();
	case 3: out = "~";
	case 4: out = "|";
	case 5: out = "*";
	default: out = ".";
	}

	return out;
}

char* providePunctuation(){

	char* out;
	int index = rand() % 7;
	switch(index){
	case 0: out = ",";
	case 1: out = ";";
	case 2: out = ":";
	case 3: out = "'";
	case 4: out = "\"";
	case 5: out = "?";
	default: out = "!";
	}

	return out;

}



char* construct(char type){

	char* output;

	switch (type){
	case 'w': return provideLowercaseWord();
	case 'W': return provideUppercaseWord();
	case 'l': return provideLowercaseLetter();
	case 'L': return provideUppercaseLetter();
	case '#': return provideNumber();
	case 's': return provideSpace();
	case 'S': return provideSeparator();
	case 'p': return providePunctuation();

	default: return "Solosis";
	}

	return output;
}
