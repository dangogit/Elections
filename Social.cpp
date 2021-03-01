/*
 * Social.cpp
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#include "Social.h"



Social::~Social() {
}

void Social::print() const{
	Politician::print();
	cout<< "Type:S, ";
	Politician::printChairman();
}

