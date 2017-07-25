/*
 * DatatypesMultiChar.cpp
 *
 *  Created on: 12 Jul 2017
 *      Author: Daniel Tran
 *
 *  This file contains methods used to produce data composed of multiple
 *  characters. Some methods aim to provide words with semantic value,
 *  namely those that produce nouns, verbs and adjectives.
 */

#include "stdlib.h"
#include "ctype.h"
#include "string.h"

#include "../Wordtypes.h"
#include "Random.h"
#include "DatatypesMultiChar.h"

/*
 * Returns a lower case noun, with allocated memory.
 */
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

/*
 * Returns a upper case noun, with allocated memory.
 */
char* provideUppercaseNoun(){

	char* output = provideLowercaseNoun();

	//Word has allocated memory, so it can be upper cased.
	output = provideUppercase(output);

	return output;
}

/*
 * Returns a lower case verb, with allocated memory.
 */
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

/*
 * Returns a upper case verb, with allocated memory.
 */
char* provideUppercaseVerb(){

	char* output = provideLowercaseVerb();

	//Word has allocated memory, so it can be upper cased.
	output = provideUppercase(output);

	return output;
}

/*
 * Returns a lower case adjective, with allocated memory.
 */
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

/*
 * Returns a upper case adjective, with allocated memory.
 */
char* provideUppercaseAdjective(){

	char* output = provideLowercaseAdjective();

	//Word has allocated memory, so it can be upper cased.
	output = provideUppercase(output);

	return output;
}

/*
 * Returns a lower case general word, with allocated memory.
 */
char* provideLowercaseWord(){

	char* data;
	int index = randomIndex();

	switch (index){
	case 1: data = "amadeus"; break;
	case 2: data = "andy"; break;
	case 3: data = "ben"; break;
	case 4: data = "blake"; break;
	case 5: data = "carl"; break;
	case 6: data = "cyrus"; break;
	case 7: data = "dave"; break;
	case 8: data = "doug"; break;
	case 9: data = "eric"; break;
	case 10: data = "eve"; break;
	case 11: data = "finn"; break;
	case 12: data = "fred"; break;
	case 13: data = "gary"; break;
	case 14: data = "gaz"; break;
	case 15: data = "harry"; break;
	case 16: data = "henry"; break;
	case 17: data = "iggy"; break;
	case 18: data = "igor"; break;
	case 19: data = "jake"; break;
	case 20: data = "jenny"; break;
	default: data = "zack";
	}

	return provideData(data);
}

/*
 * Returns a upper case general word, with allocated memory.
 */
char* provideUppercaseWord(){
	char* output = provideLowercaseWord();

	//Word has allocated memory, so it can be upper cased.
	output = provideUppercase(output);

	return output;
}

/*
 * Returns a string of random printable characters from the ASCII table.
 * The string's length ranges from 1 to 101 inclusive (with null terminator).
 */
char* provideRandomWord(){

	//Determine the length of the data to produce.
	int length = randomIndex();

	//Allocate memory accordingly. +1 is for the null character.
	char* output = (char*) malloc(sizeof(char)*length + 1);

	//Allocate each character with some contents.
	for (int i = 0; i < length; i++){
		output[i] = randomLetter();
	}

	//Add null character at the end of the string.
	output[length] = '\0';

	return output;
}

/*
 * Returns a general word with a capitalised letter.
 * Initially implemented, since general words are usually names and such.
 */
char* provideCapitalisedWord(){

	char* output = provideLowercaseWord();

	//Only make the first character upper case.
	output[0] = toupper(output[0]);

	return output;
}
