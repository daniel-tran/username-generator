/*
 * UnitTests.cpp
 *
 *  Created on: 8 Jul 2017
 *      Author: Daniel Tran
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "UnitTests.h"
#include "Wordtypes.h"

int Unit::testBasicData(){

	printf("\n Testing construction of basic data \n");

	char* test = construct('w');
	printf("Construct lowercase word:         %s \n", test);
	free(test);

	test = construct('l');
	printf("Construct lowercase letter:       %s \n", test);
	free(test);

	test = construct('W');
	printf("Construct uppercase word:         %s \n", test);
	free(test);

	test = construct('L');
	printf("Construct uppercase letter:       %s \n", test);
	free(test);

	test = construct('r');
	printf("Construct random letter:          %s \n", test);
	free(test);

	test = construct('R');
	printf("Construct random word:            %s \n", test);
	free(test);

	test = construct('P');
	printf("Construct capitalized word:       %s \n", test);
	free(test);

	test = construct('#');
	printf("Construct number:                 %s \n", test);
	free(test);

	printf("Construct space:                  %s \n", construct('s'));

	test = construct('S');
	printf("Construct basic separator:        %s \n", test);
	free(test);

	test = construct('p');
	printf("Construct punctuation character:  %s \n", test);
	free(test);

	return 0;
}

int Unit::testSemanticData(){

	printf("\n Testing construction of semantic data \n");

	char* test = construct('n');
	printf("Construct lowercase noun:         %s \n", test);
	free(test);

	test = construct('N');
	printf("Construct uppercase noun:         %s \n", test);
	free(test);

	test = construct('v');
	printf("Construct lowercase verb:         %s \n", test);
	free(test);

	test = construct('V');
	printf("Construct uppercase verb:         %s \n", test);
	free(test);

	test = construct('a');
	printf("Construct lowercase adjective:    %s \n", test);
	free(test);

	test = construct('A');
	printf("Construct uppercase adjective:    %s \n", test);
	free(test);

	return 0;
}

int Unit::testEdgeCaseData(){

	printf("\n Test edge case data               \n");

	char* test = construct('@');
	printf("Construct non-existent word type: %s \n", test);
	free(test);

	test = construct(0);
	printf("Construct blank input (ASCII):    %s \n", test);
	free(test);

	return 0;
}

int Unit::testMainData(){

	printf("\n Test main methods in the generator \n");

	word* test;

	test = wordtypeInitialise("l");
	printf("Construct data from input string: %s \n", test[0].data);
	printf("Construct type from input string: %c \n", test[0].type);

	printf("Print using the custom print method for word structures: ");
	wordtypePrint(test, 1);
	printf("\n");

	wordtypeFree(test, 1);
	printf("Free memory occupied by data:     %s \n", test[0].data);
	printf("Free memory occupied by type:     %c \n", test[0].type);

	return 0;
}

int Unit::testMainDataStressTest(){

	printf("\n Test main methods with input of 100 items \n");

	word* test;
	char* input = "##############################################################################################################";
	const int length = strlen(input);

	test = wordtypeInitialise(input);

	printf("Print using the custom print method for word structures: ");
	wordtypePrint(test, length);
	printf("\n");

	printf("Print using the custom print method for 4 words: ");
	wordtypePrint(test, 4);
	printf("\n");

	printf("Print using the custom print method for 0 words: ");
	wordtypePrint(test, 0);
	printf("\n");

	printf("Print using the custom print method for -1 words: ");
	wordtypePrint(test, -1);
	printf("\n");

	wordtypeFree(test, length);
	for (int i = 0; i < length; i++){
		printf("Free memory occupied by data:     %s \n", test[i].data);
		printf("Free memory occupied by type:     %c \n", test[i].type);
	}

	return 0;
}

int Unit::testAll(){

	testBasicData();

	testSemanticData();

	testEdgeCaseData();

	testMainData();

	testMainDataStressTest();

	printf("\n");

	return 0;
}


