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

	char* source[] = {
			"asparagus", "axe",
			"bacon", "bear",
			"carrot", "celery",
			"dog", "dynamite",
			"eagle", "egg",
			"fire", "fox",
			"gas", "goat",
			"ham", "head",
			"ice", "incense",
			"jelly", "jumper",
			"zoo"
	};

	int index = randomIndex();
	char* data = source[index];
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

	char* source[] = {
			"act", "add",
			"belch", "burp",
			"chop", "cut",
			"dash", "dig",
			"eat", "excel",
			"feast", "floss",
			"glow", "go",
			"hit", "hover",
			"implore", "invest",
			"joust", "judge",
			"zap"
	};

	int index = randomIndex();
	char* data = source[index];
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

	//TODO Make this a const to fix deprecation error, but also needs percolation to other areas too
	char* source[] = {
			"angular", "awkward"
			"best", "bored",
			"curly", "cute",
			"dangerous", "dark",
			"eerie", "exotic",
			"fancy", "filthy",
			"great", "greedy",
			"handy", "hateful",
			"instant", "intricate",
			"jaunty", "jolly",
			"zealous"
	};

	int index = randomIndex();
	char* data = source[index];
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

	//TODO Make this a const to fix deprecation error, but also needs percolation to other areas too
	char* source[] = {
			"andrew", "andy",
			"ben", "blake",
			"carl", "cyrus",
			"dave", "doug",
			"eric", "eve",
			"finn", "fred",
			"gary", "gaz",
			"harry", "henry",
			"iggy", "igor",
			"jake", "jenny",
			"kaz", "ken",
			"larry", "lenny",
			"max", "mike",
			"nick", "nicole",
			"oscar", "otto",
			"patrick", "peter",
			"queen", "quentin",
			"robert", "rose",
			"sam", "sandy",
			"tim", "tom",
			"ulysses", "uppity",
			"vance", "victor",
			"wendy", "william",
			"xavier", "xeno",
			"yolande", "yuri",
			"zack", "zippy"
	};

	int index = randomIndex() % 50;
	char* data = source[index];
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
