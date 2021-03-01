/*
 * Democratic.cpp
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#include "Democratic.h"

Democratic::Democratic(string partyname): Party(partyname){

}

Democratic::~Democratic() {
}


void Democratic::print() const{
	cout<< "Democrat ";
	Party::print();

}

status Democratic::AddDemocraticPolitician(Politician* person){
	if (person == NULL)
		return BAD_DATA;
	else if ((person->getPower()>current_max_power) && (person->isGoodForPrimeriz()))
		current_max_power = person->getPower();
	politicians.push_back(person);
	return SUCCES;


}
