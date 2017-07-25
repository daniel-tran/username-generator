/*
 * Random.h
 *
 *  Created on: 12 Jul 2017
 *      Author: Administrator
 *
 *  This is the header file for the library of methods used to
 *  provide randomised data.
 */

#ifndef RANDOM_H_
#define RANDOM_H_

//Randomises the seed for calculating values.
int randomSeed();

//These methods provide randomised data.
int randomIndex();
int randomLetterIndex();
int randomSingleDigit();
char randomLetter();

#endif /* RANDOM_H_ */
