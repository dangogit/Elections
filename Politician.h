/*
 * Politician.h
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#ifndef POLITICIAN_H_
#define POLITICIAN_H_
#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Error.h"
using namespace std;
enum status {BAD_ID, BAD_NAME, BAD_DATA, SUCCES, FAILED};
#include "Party.h"
class Party;

class Politician {


protected:
	string firstname;
	string lastname;
	string id;
	Party* party;
	int power;
	Politician* chairman;
	static int counter;
	int seniority;

public:
	Politician(string Firstname, string Lastname, string Id, int Power);
	virtual ~Politician();
	Politician(const Politician &other);
	virtual void print()const=0;
	void printChairman() const;
	string getName();
	string getId();
	int getPower();
	Party* getParty();
	void setParty(Party* partyto);
	virtual bool isGoodForPrimeriz() = 0;
	void update_chairman(Politician* newchair);
	Politician& operator=(const Politician &other);
	status checkEntryToParty(Party* partyto);
	virtual void addMeToDemocratic(Party* partyto) = 0;
	virtual void addMeToRepublican(Party* partyto) = 0;

};



#endif /* POLITICIAN_H_ */
