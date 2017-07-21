/*
 * UnitsTests.h
 *
 *  Created on: 8 Jul 2017
 *      Author: Daniel Tran
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
