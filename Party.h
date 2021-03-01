/*
 * Party.h
 *
 *  Created on: Jan 9, 2020
 *      Author: ise
 */

#ifndef PARTY_H_
#define PARTY_H_
#pragma once
#include "Politician.h"

class Politician;
class Party {

protected:
	string name;
	static int counter;
	int current_max_power;
	vector<Politician*> politicians;

public:
	Politician* p_chairman;
	int id;
	Party(string partyname);
	virtual ~Party();
	Party(const Party &other);
	virtual status AddDemocraticPolitician(Politician* person)=0;
	virtual status AddRepublicanPolitician(Politician* person)=0;
	status RemovePolitician(Politician* person);
	status Primeriz();
    int PartyPower();
    virtual int DemocraticPartySize()=0;
    virtual int RepublicanPartySize()=0;
    string PartyName();
    int PartySize();
    Politician* PartyChariman();
	virtual void print() const=0;
	Politician* getPoliticianById(string id);
	void notify();
	vector<Politician*> deleteMe();


};

#endif /* PARTY_H_ */
