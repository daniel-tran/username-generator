/*
 * DatatypesMultiChar.h
 *
 *  Created on: 12 Jul 2017
 *      Author: Daniel Tran
 *
 *  This is the header file for the library of methods used to provide
 *  words composed of multiple characters.
 */

#ifndef DATATYPESMULTICHAR_H_
#define DATATYPESMULTICHAR_H_

//These methods are used to provide noun data.
char* provideLowercaseNoun();
char* provideUppercaseNoun();

//These methods are used to provide verb data.
char* provideLowercaseVerb();
char* provideUppercaseVerb();

//These methods are used to provide adjective data.
char* provideLowercaseAdjective();
char* provideUppercaseAdjective();

//These methods are used to provide general word data.
char* provideLowercaseWord();
char* provideUppercaseWord();

//These methods are used to provide miscellaneous word data.
char* provideRandomWord();
char* provideCapitalisedWord();

#endif /* DATATYPESMULTICHAR_H_ */
