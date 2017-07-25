/*
 * UnitsTests.h
 *
 *  Created on: 8 Jul 2017
 *      Author: Daniel Tran
 *
 *  This header file is for the library of methods used for testing the
 *  program. The methods are implemented as a class, partly as an exercise
 *  to implement objects in C/C++.
 */

#ifndef UNITTESTS_H_
#define UNITTESTS_H_

class Unit{
public:
	int testBasicData();
	int testSemanticData();
	int testEdgeCaseData();
	int testMainData();
	int testMainDataStressTest();
	int testAll();
};

#endif /* UNITTESTS_H_ */
