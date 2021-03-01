/*
 * PoliticalSys.h
 *
 *  Created on: Jan 11, 2020
 *      Author: ise
 */

#ifndef POLITICALSYS_H_
#define POLITICALSYS_H_
#include "Party.h"
#include "PoliticianLeaderDemocratic.h"
#include "PoliticianLeaderRepublican.h"
#include "PoliticianSocialDemocratic.h"
#include "PoliticianSocialRepublican.h"
#include "Democratic.h"
#include "Republican.h"
#include "Error.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <list>

class LowerParty{
public:
	bool operator()(Party* a, Party* b){
		if (a->PartySize() == b->PartySize())
			return a->PartyName() > b->PartyName();
		return a->PartySize() > b->PartySize();

	}
};

class PoliticalSys {
private:
	vector<Politician*> all_politicians;
	vector<Party*> parties;
	vector<Party*> sorted_parties;

public:
	PoliticalSys(char* &filepath);
	virtual ~PoliticalSys();
	status addPolitician();
	status addthePolitician(string Firstname, string Lastname, string Id, int Power, char side,  char type);
	status addParty();
	status removePolitician();
	status removeParty();
	void elections();
	void printPoliticians();
	void printParties();
	void BiggestParty();
	list<string> convertStringToList(string str);
	bool has_number(const string& s);
	bool is_number(const string& s);
	bool PoliticianExists(const string &id);
	bool PartyExists(const string &name);
};

#endif /* POLITICALSYS_H_ */
