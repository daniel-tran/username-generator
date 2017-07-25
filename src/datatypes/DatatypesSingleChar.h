/*
 * DatatypesSingleChar.h
 *
 *  Created on: 12 Jul 2017
 *      Author: Daniel Tran
 *
 *  This is the header file for the library of methods used to provide
 *  single character words.
 */

#ifndef DATATYPESSINGLECHAR_H_
#define DATATYPESSINGLECHAR_H_

//These methods provide alphabetic data, in both cases.
char* provideLowercaseLetter();
char* provideUppercaseLetter();

//These methods provide characters without case variants.
char* provideNumber();
char* provideSpace();
char* provideSeparator();
char* providePunctuation();
char* provideRandomLetter();



#endif /* DATATYPESSINGLECHAR_H_ */
