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

int Unit::testAll(){

	testBasicData();

	testSemanticData();

	testEdgeCaseData();

	printf("\n");

	return 0;
}


