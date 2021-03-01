/*
 * PoliticianLeaderDemocratic.cpp
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#include "PoliticianLeaderDemocratic.h"


PoliticianLeaderDemocratic::~PoliticianLeaderDemocratic() {
}

void PoliticianLeaderDemocratic::print() const{
	cout<< "Democratic ";
	Leader::print();
}

void PoliticianLeaderDemocratic::addMeToDemocratic(Party* partyto){
	if (partyto->AddDemocraticPolitician(this) == FAILED)
		return;

	if (this->party != NULL)
	{
		Party* old = this->party;
		old->RemovePolitician(this);
	}
	this->party = partyto;
	this->chairman = partyto->PartyChariman();

}

