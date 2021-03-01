/*
 * PoliticianSocialDemocratic.cpp
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#include "PoliticianSocialDemocratic.h"

PoliticianSocialDemocratic::~PoliticianSocialDemocratic() {

}


void PoliticianSocialDemocratic::print() const{
	cout<< "Democratic ";
	Social::print();
}


void PoliticianSocialDemocratic::addMeToDemocratic(Party* partyto){
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
