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

char* provideLowercaseWord();
char* provideUppercaseWord();
char* construct(char type);

#endif /* WORDTYPES_H_ */
