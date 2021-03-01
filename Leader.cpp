/*
 * Leader.cpp
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#include "Leader.h"


Leader::~Leader() {

}


void Leader::print() const{
	Politician::print();
	cout<< "Type:L, ";
	Politician::printChairman();
}
