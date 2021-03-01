/*
 * PoliticianLeaderRepublican.cpp
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#include "PoliticianLeaderRepublican.h"

PoliticianLeaderRepublican::~PoliticianLeaderRepublican() {

}


void PoliticianLeaderRepublican::print() const{
	cout<< "Republican ";
	Leader::print();
}
void PoliticianLeaderRepublican::addMeToRepublican(Party* partyto){
	if (partyto->AddRepublicanPolitician(this) == FAILED)
		return;
	if (this->party != NULL)
	{
		Party* old = this->party;
		old->RemovePolitician(this);
	}

	this->party = partyto;
	this->chairman = partyto->PartyChariman();

}
