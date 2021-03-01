/*
 * Republican.cpp
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#include "Republican.h"


Republican::Republican(string partyname): Party(partyname){

}

Republican::~Republican() {
}


void Republican::print() const{
	cout<<"Republican ";
	Party::print();

}

status	Republican::AddRepublicanPolitician(Politician* person){
	if (person == NULL)
		return BAD_DATA;
	else if ((person->getPower()>current_max_power) && (person->isGoodForPrimeriz()))
		current_max_power = person->getPower();
	politicians.push_back(person);
	return SUCCES;

}
