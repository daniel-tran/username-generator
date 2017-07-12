/*
 * DatatypesSingleChar.cpp
 *
 *  Created on: 12 Jul 2017
 *      Author: Administrator
 */

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../Wordtypes.h"
#include "Random.h"
#include "DatatypesSingleChar.h"

char* provideLowercaseLetter(){

	char letter = 'a'+randomLetterIndex();
	return provideException(letter);
}

char* provideUppercaseLetter(){
	char* out = provideLowercaseLetter();
	out[0] = toupper(out[0]);

	return out;
}

char* provideNumber(){

	int index = randomSingleDigit() + 2; //+2 ensures at least 1 character and \0
	char* out = (char*)malloc(sizeof(int) * index);

	for (int i = 0; i < index; i++){
		out[i] = '0' + randomSingleDigit();
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

char* provideRandomLetter(){

	return provideException(randomLetter());
}


