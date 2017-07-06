/*
 * Main.cpp
 *
 *  Created on: 24 Jun 2017
 *      Author: Administrator
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
using namespace std;

struct word {
	char* data;
	word* next;
	bool isTail;
};

char* provideWord(){

	char* output;
	int index = rand() % 100;

	switch (index){
	case 0: output = "Axiom";
	default: output = "Zanguard";
	}

	return output;
}

char* provideLowercaseWord(){
	char* rawWord = provideWord();

	for (int i = 0; i < strlen(rawWord); i++){
		rawWord[i] = tolower(rawWord[i]);
	}

	return rawWord;
}



char* construct(char type){

	char* output;

	switch (type){
	case 'w': return provideWord();

	default: return "Solosis";
	}

	return output;
}

int main(){

	char* data = "lwl";
	const int wordCount = strlen(data);
	word* words = (word*) malloc(wordCount * sizeof(word));

	for (int i = 0; i < wordCount; i++){
		words[i].data = construct(data[i]);
	}

	for (int c = 0; c < wordCount; c++){
		printf("%s", words[c].data);
	}

	free(words);

	return 0;
}
