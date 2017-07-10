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

	printf("Construct lowercase word:         %s \n", construct('w'));

	char* test = construct('l');
	printf("Construct lowercase letter:       %s \n", test);
	free(test);

	printf("Construct uppercase word:         %s \n", construct('W'));

	test = construct('L');
	printf("Construct uppercase letter:       %s \n", test);
	free(test);

	test = construct('r');
	printf("Construct random letter:          %s \n", test);
	free(test);

	test = construct('R');
	printf("Construct random word:            %s \n", test);
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

	printf("Construct lowercase noun:         %s \n", construct('n'));

	printf("Construct uppercase noun:         %s \n", construct('N'));

	printf("Construct lowercase verb:         %s \n", construct('v'));

	printf("Construct uppercase verb:         %s \n", construct('V'));

	printf("Construct lowercase adjective:    %s \n", construct('a'));

	printf("Construct uppercase adjective:    %s \n", construct('A'));

	return 0;
}

int Unit::testEdgeCaseData(){

	printf("\n Test edge case data               \n");

	printf("Construct non-existent word type: %s \n", construct('@'));

	printf("Construct blank input (ASCII):    %s \n", construct(0));

	return 0;
}

int Unit::testAll(){

	testBasicData();

	testSemanticData();

	testEdgeCaseData();

	printf("\n");

	return 0;
}


