/*
 * PoliticianSocialRepublican.cpp
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#include "PoliticianSocialRepublican.h"

PoliticianSocialRepublican::~PoliticianSocialRepublican() {

}

void PoliticianSocialRepublican::print() const{
	cout<< "Republican ";
	Social::print();
}
void PoliticianSocialRepublican::addMeToRepublican(Party* partyto){
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
