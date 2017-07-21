/*
 * Wordtypes.h
 *
 *  Created on: 7 Jul 2017
 *      Author: Daniel Tran
 */

#ifndef WORDTYPES_H_
#define WORDTYPES_H_

struct word {
	char* data;
	char type;
};

word* wordtypeInitialise(char* data);
int wordtypePrint(word* words, int wordCount);
int wordtypeFree(word* words, int wordCount);

char* provideUppercase(char* output);
char* provideData(char* data);
char* provideException(char input);

char* construct(char type);

#endif /* WORDTYPES_H_ */
