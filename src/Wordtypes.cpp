/*
 * Wordtypes.c
 *
 *  Created on: 7 Jul 2017
 *      Author: Daniel Tran
 *
 *  This file contains methods and logical links between Main.cpp and the
 *  other libraries involved in the program.
 *  In a sense, this file acts as the Controller in an MVC architecture.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//When a new library of word types is added, add a #include here as well.
#include "Wordtypes.h"
#include "datatypes/Random.h"
#include "datatypes/DatatypesSingleChar.h"
#include "datatypes/DatatypesMultiChar.h"

struct word;

/*
 * Given a string of characters, this method creates an array of
 * words and establishes the contents of each word based on the original
 * input data.
 */
word* wordtypeInitialise(char* data){

	//Allocate memory based on the given data
	const int wordCount = strlen(data);
	word* words = (word*) malloc(wordCount * sizeof(word));

	//Establish contents of each word using the construct() method
	for (int i = 0; i < wordCount; i++){
		words[i].data = construct(data[i]);
		words[i].type = data[i];
	}

	return words;
}

/*
 * Prints the data for each word in a username.
 * Since wordCount and words are independent, this method can result in a
 * crash (if wordCount > total items in words) or a partial output
 * (if wordCount < total items in words).
 */
int wordtypePrint(word* words, int wordCount){

	//Print data all on the same line.
	for (int c = 0; c < wordCount; c++){
		printf("%s", words[c].data);
	}

	return 0;
}

/*
 * Frees any memory allocated by the username.
 * Since wordCount and words are independent, this method can result in a
 * crash (if wordCount > total items in words) or a memory leak
 * (if wordCount < total items in words).
 */
int wordtypeFree(word* words, int wordCount){

	for (int k = 0; k < wordCount; k++){

		//Reset the contents of each word (if free() fails).
		words[k].data = NULL;
		words[k].type = 0;

		//Proper freeing of allocated memory.
		free(words[k].data);
		free((char*) words[k].type);
	}

	//Free entire pointer to the array
	free(words);

	return 0;
}

/*
 * Converts a string of characters to upper case.
 * Fails if output is a string of constants, so malloc() or realloc()
 * should have been called on output prior to this method call.
 */
char* provideUppercase(char* output){

	const int length = strlen(output);

	//Turn each character to its upper case equivalent.
	for (int i = 0; i < length; i++){
		output[i] = toupper(output[i]);
	}

	return output;
}

/*
 * Converts a an array of constant characters to a memory-allocated
 * dynamic array of characters ending with the null character.
 * This allows data to be changed as needed, but requires memory
 * freeing to prevent memory leaks.
 */
char* provideData(char* data){

	//Allocate memory and copy in input contents. +1 is for the null character.
	char* output = (char*) malloc( (sizeof(char)*strlen(data)) +1);
	strcpy(output, data);

	//Manually add ending null terminator.
	output[strlen(data)] = '\0';

	return output;
}

/*
 * Converts a constant character to a memory-allocated dynamic array
 * of characters ending with the null character.
 * This allows data to be changed as needed, but requires memory
 * freeing to prevent memory leaks.
 */
char* provideException(char input){

	//Allocate memory for 2 characters (includes null terminator).
	char* output = (char*)malloc(sizeof(char)*2);

	//Manually copy in data with said null character.
	output[0] = input;
	output[1] = '\0';

	return output;
}

/*
 * Returns a string of characters based on the type variable.
 */
char* construct(char type){

	char* output;

	switch (type){
	//Provide simple syntactical data such as characters and simple words.
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

	//Provide simple semantical data, like nouns, verbs and adjectives.
	case 'n': return provideLowercaseNoun();
	case 'N': return provideUppercaseNoun();
	case 'v': return provideLowercaseVerb();
	case 'V': return provideUppercaseVerb();
	case 'a': return provideLowercaseAdjective();
	case 'A': return provideUppercaseAdjective();

	//Provide the input character if no match was found.
	default: return provideException(type);
	}

	return output;
}
