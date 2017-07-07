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
using namespace std;

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
	char* output;
	int index = rand() % 100;

	switch (index){
	case 0: output = "anchor"; break;
	default: output = "zabaglione";
	}

	return output;
}



char* construct(char type){

	char* output;

	switch (type){
	case 'w': return provideWord();
	case 'l': return provideLowercaseWord();

	default: return "Solosis";
	}

	return output;
}
