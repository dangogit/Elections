/*
 * Politician.cpp
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#include "Politician.h"
int Politician::counter = 0;


Politician::Politician(string Firstname, string Lastname, string Id, int Power) {

	counter++;
	this->firstname = Firstname;
	this->lastname = Lastname;
	this->id = Id;
	this->power = Power;
	this->seniority = counter;
	this->party = NULL;
	this->chairman = NULL;
}


Politician::~Politician() {
}

Politician::Politician(const Politician &other) {
	this->firstname = other.firstname;
	this->lastname = other.lastname;
	this->id = other.id;
	this->power = other.power;
	this->party = other.party;
	this->chairman = other.chairman;
	this->seniority = other.seniority;

}
void Politician::print() const {
	cout << "Person:";
	cout << firstname << " ";
	cout << lastname << ", ";
	cout << "Id:" << id << ", ";
	cout << "Power:" << power << ", ";

}
void Politician::printChairman() const {
	cout << "Chairman: ";
	if (chairman)
		cout << chairman->getName() << endl;
	else
		cout << "None" << endl;
}

string Politician::getName() {
	return this->firstname;
}
string Politician::getId() {
	return this->id;
}


int Politician::getPower() {
	return this->power;
}
Party* Politician::getParty() {
	return this->party;
}

void Politician::setParty(Party* partyto)
{
	this->party = partyto;
}
status Politician::checkEntryToParty(Party *partyto) {

	int D_s = partyto->DemocraticPartySize();
	int R_s = partyto->RepublicanPartySize();

	if ((D_s != -1) && (D_s < (this->party->DemocraticPartySize()))) {
		partyto->AddDemocraticPolitician(this);
		cout<<this->getName()<<" entered "<<partyto->PartyName()<<endl;
		return SUCCES;
	}
	if (D_s == 0)
	{
		partyto->AddDemocraticPolitician(this);
		cout<<this->getName()<<" entered "<<partyto->PartyName()<<endl;
		return SUCCES;
	}
	if ((R_s != -1) && (R_s < (this->party->RepublicanPartySize()))) {
		partyto->AddRepublicanPolitician(this);
		cout<<this->getName()<<" entered "<<partyto->PartyName()<<endl;
		return SUCCES;
	}
	if (R_s == 0)
	{
		partyto->AddRepublicanPolitician(this);
		cout<<this->getName()<<" entered "<<partyto->PartyName()<<endl;
		return SUCCES;
	}
	cout<<this->getName()<<" failed to enter "<<partyto->PartyName()<<endl;
	return FAILED;
}


Politician& Politician::operator=(const Politician &other) {

	this->firstname = other.firstname;
	this->lastname = other.lastname;
	this->id = other.id;
	this->power = other.power;
	this->seniority = other.counter;
	return *this;

}
void Politician::update_chairman(Politician* newchair)
{
	chairman  = newchair;
}

