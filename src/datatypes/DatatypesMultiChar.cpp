/*
 * DatatypesMultiChar.cpp
 *
 *  Created on: 12 Jul 2017
 *      Author: Administrator
 */

#include "stdlib.h"
#include "ctype.h"
#include "string.h"

#include "../Wordtypes.h"
#include "Random.h"
#include "DatatypesMultiChar.h"

char* provideLowercaseNoun(){
	char* data;
	int index = randomIndex();

	switch(index){
	case 1: data = "asparagus"; break;
	case 2: data = "axe"; break;
	case 3: data = "bacon"; break;
	case 4: data = "bear"; break;
	case 5: data = "carrot"; break;
	case 6: data = "celery"; break;
	case 7: data = "dog"; break;
	case 8: data = "dynamite"; break;
	case 9: data = "eagle"; break;
	case 10: data = "egg"; break;
	case 11: data = "fire"; break;
	case 12: data = "fox"; break;
	case 13: data = "gas"; break;
	case 14: data = "goat"; break;
	case 15: data = "ham"; break;
	case 16: data = "head"; break;
	case 17: data = "ice"; break;
	case 18: data = "incense"; break;
	case 19: data = "jelly"; break;
	case 20: data = "jumper"; break;

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
	case 2: data = "add"; break;
	case 3: data = "belch"; break;
	case 4: data = "burp"; break;
	case 5: data = "chop"; break;
	case 6: data = "cut"; break;
	case 7: data = "dash"; break;
	case 8: data = "dig"; break;
	case 9: data = "eat"; break;
	case 10: data = "excel"; break;
	case 11: data = "feast"; break;
	case 12: data = "floss"; break;
	case 13: data = "glow"; break;
	case 14: data = "go"; break;
	case 15: data = "hit"; break;
	case 16: data = "hover"; break;
	case 17: data = "implore"; break;
	case 18: data = "invest"; break;
	case 19: data = "joust"; break;
	case 20: data = "judge"; break;
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
	case 2: data = "awkward"; break;
	case 3: data = "best"; break;
	case 4: data = "bored"; break;
	case 5: data = "curly"; break;
	case 6: data = "cute"; break;
	case 7: data = "dangerous"; break;
	case 8: data = "dark"; break;
	case 9: data = "eerie"; break;
	case 10: data = "exotic"; break;
	case 11: data = "fancy"; break;
	case 12: data = "filthy"; break;
	case 13: data = "great"; break;
	case 14: data = "greedy"; break;
	case 15: data = "handy"; break;
	case 16: data = "hateful"; break;
	case 17: data = "instant"; break;
	case 18: data = "intricate"; break;
	case 19: data = "jaunty"; break;
	case 20: data = "jolly"; break;
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

	int index = randomIndex() % 3;

	switch (index){
	case 0: return provideLowercaseNoun();
	case 1: return provideLowercaseVerb();
	case 2: return provideLowercaseAdjective();
	default: return provideData("soap");
	}
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

char* provideCapitalisedWord(){

	char* output = provideLowercaseWord();

	output[0] = toupper(output[0]);

	return output;
}
