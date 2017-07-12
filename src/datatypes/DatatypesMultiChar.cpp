/*
 * DatatypesMultiChar.cpp
 *
 *  Created on: 12 Jul 2017
 *      Author: Administrator
 */

#include "stdlib.h"
#include "string.h"

#include "../Wordtypes.h"
#include "Random.h"
#include "DatatypesMultiChar.h"

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

char* provideLowercaseWord(){
	char* data;
	int index = randomIndex();

	switch (index){
	case 0: data = "anchor"; break;
	default: data = "zucchini";
	}

	return provideData(data);
}

char* provideUppercaseWord(){
	char* output = provideLowercaseWord();

	output = provideUppercase(output);

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
