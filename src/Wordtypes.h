/*
 * Wordtypes.h
 *
 *  Created on: 7 Jul 2017
 *      Author: Daniel Tran
 *
 *  This is the header file for the library of methods used for general
 *  word creation.
 */

#ifndef WORDTYPES_H_
#define WORDTYPES_H_

//This is the struct for each word in a username.
struct word {
	char* data;
	char type;
};

//These methods are for managing username components.
word* wordtypeInitialise(char* data);
int wordtypePrint(word* words, int wordCount);
int wordtypeFree(word* words, int wordCount);

//These methods operate on word data.
char* provideUppercase(char* output);
char* provideData(char* data);
char* provideException(char input);

//This method is for word generation based on a given word category.
char* construct(char type);

#endif /* WORDTYPES_H_ */
