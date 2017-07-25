/*
 * DatatypesSingleChar.cpp
 *
 *  Created on: 12 Jul 2017
 *      Author: Administrator
 *
 *  This file contains methods for producing data containing a single
 *  character in the ASCII table, as well as the associated null character.
 */

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../Wordtypes.h"
#include "Random.h"
#include "DatatypesSingleChar.h"

/*
 * Returns a random lower case character between 'a' and 'z' inclusive.
 */
char* provideLowercaseLetter(){

	char letter = 'a' + randomLetterIndex();

	//Just return the original input as a dynamic character.
	return provideException(letter);
}

/*
 * Returns a random upper case character between 'A' and 'Z' inclusive.
 */
char* provideUppercaseLetter(){

	//Character is made dynamic with memory allocation, so toupper() is usable.
	char* out = provideLowercaseLetter();
	out[0] = toupper(out[0]);

	return out;
}

/*
 * Returns a string of numeric characters with length ranging from
 * 2 to 12 characters inclusive (null terminator included).
 */
char* provideNumber(){

	//Get a length for the output. +2 ensures at least 1 character and \0.
	int index = randomSingleDigit() + 2;

	//Allocate memory according to the aforementioned size.
	char* out = (char*) malloc(sizeof(int) * index);

	//Each character in the data string ranges from '0' to '9' inclusive.
	for (int i = 0; i < index; i++){
		out[i] = '0' + randomSingleDigit();
	}

	//Add in the necessary null terminator.
	out[index] = '\0';

	return out;
}

/*
 * Returns a string consisting only of the space character.
 */
char* provideSpace(){
	return " ";
}

/*
 * Returns a random character used for separating purposes.
 */
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

/*
 * Returns a random character used for punctuation purposes.
 */
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

/*
 * Returns a random letter in the printable range of ASCII characters.
 */
char* provideRandomLetter(){

	return provideException(randomLetter());
}


