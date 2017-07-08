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

	printf("Construct lowercase letter:       %s \n", construct('l'));

	printf("Construct uppercase word:         %s \n", construct('W'));

	printf("Construct uppercase letter:       %s \n", construct('L'));

	printf("Construct random letter:          %s \n", construct('r'));

	printf("Construct random word:            %s \n", construct('R'));

	printf("Construct number:                 %s \n", construct('#'));

	printf("Construct space:                  %s \n", construct('s'));

	printf("Construct basic separator:        %s \n", construct('S'));

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


