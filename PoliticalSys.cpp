/*
 * PoliticalSys.cpp
 *
 *  Created on: Jan 11, 2020
 *      Author: ise
 */

#include "PoliticalSys.h"


PoliticalSys::PoliticalSys(char *&filepath) {

	ifstream myfile;
	string line;
	bool polition = true;
	bool party = false;
	myfile.open(filepath);
	if (myfile.is_open()) {
		while (getline(myfile, line)) //loop through the lines
		{
			string word;
			if (line.rfind("Politicians:", 0) == 0)
				continue;
			if (line.rfind("Parties:", 0) == 0) {
				polition = false;
				party = true;
				continue;
			}
			list<string> currLine = convertStringToList(line);
			list<string>::iterator it = currLine.begin();

			if (polition) {
				string Firstname = (*it);
				++it;
				string Lastname = (*it);
				++it;
				string Id = (*it);
				++it;
				// cast power to int
				string powerS = (*it);
				stringstream s(powerS);
				int Power = 0;
				s >> Power;
				// cast power to int
				++it;
				string side = (*it);
				++it;
				string type = (*it);
				/*
				 * COMPLETE IF ARGUMENTS ARE WRONG !
				 */
				addthePolitician(Firstname, Lastname, Id, Power, side[0],
						type[0]);
			}
			if (party) {
				string partyName = (*it);
				++it;
				string partyType = (*it);
				/*
				 * COMPLETE IF ARGUMENTS ARE WRONG !
				 */
				Party *p;
				if (partyType[0] == 'D') {
					p = new Democratic(partyName);
					if (p == NULL)
						abort;
				} else if (partyType[0] == 'R') {
					p = new Republican(partyName);
					if (p == NULL)
						abort;
				}
				parties.push_back(p);
				sorted_parties.push_back(p);
				sort(sorted_parties.begin(), sorted_parties.end(),
						LowerParty());

				int s = all_politicians.size();
				for (int i = 0; i < s; i++) {
					if ((all_politicians[i]->getParty() == NULL)
							|| (all_politicians[i]->getParty()->PartySize()
									> p->PartySize())) {

						if (partyType[0] == 'D')
							all_politicians[i]->addMeToDemocratic(p);
						else
							all_politicians[i]->addMeToRepublican(p);

					}

				}

			}
		}
	}
	myfile.close();
}

list<string> PoliticalSys::convertStringToList(string str){
	list<string> res;
	stringstream ss(str);
	string tok;
	while (getline(ss, tok, ' ')) {
		res.push_back(tok);
	}
	return res;
}

PoliticalSys::~PoliticalSys() {


	int s = all_politicians.size();
	for (int i = 0; i< s; i++)
		delete(all_politicians[i]);
	int p = parties.size();
	for(int i =0; i<p ; i++)
		delete(parties[i]);
	all_politicians.clear();
	parties.clear();
	sorted_parties.clear();

}
status PoliticalSys::addPolitician() {


	cout << "---Create Politician---" << endl;
	bool flag = true;
	string Firstname, Lastname, Id;
	char side, type;
	int Power;
	while (flag) {
		cout << "First name:" << endl;
		cin >> Firstname;
		while (has_number(Firstname)) {
			try {
				if (has_number(Firstname))
					throw NameError();
			} catch (Error &e) {
				e.Handle();
				cout << "First name:" << endl;
				cin >> Firstname;
			}
		}
		cout << "Last name:" << endl;
		cin >> Lastname;
		try {
			if (has_number(Lastname))
				throw NameError();
		} catch (Error &e) {
			e.Handle();
			continue;
		}
		cout << "ID:" << endl;
		cin >> Id;
		try {
			if (is_number(Id))
				throw IDError();
		} catch (Error &e) {
			e.Handle();
			continue;
		}
		try {
			if (PoliticianExists(Id))
				throw DataError();
		} catch (Error &e) {
			e.Handle();
			continue;
		}
		cout << "Power:" << endl;
		cin >> Power;
		try {
			if (Power < 0)
				throw DataError();
		} catch (Error &e) {
			e.Handle();
			continue;
		}
		cout << "Republican or Democratic person" << endl;
		cin >> side;
		try {
			if (side != 'R' && side != 'D')
				throw DataError();
		} catch (Error &e) {
			e.Handle();
			continue;
		}
		cout << "Leader or Social" << endl;
		cin >> type;
		try {
			if (type != 'S' && type != 'L')
				throw DataError();
			else
				flag = false;
		} catch (Error &e) {
			e.Handle();
			continue;
		}
	}
	addthePolitician(Firstname, Lastname, Id, Power, side, type);

	return SUCCES;
}
status PoliticalSys::addthePolitician(string Firstname, string Lastname,
		string Id, int Power, char side, char type) {
	Politician *p;
	int s = parties.size();
	if (type == 'L') {
		if (side == 'D') {
			p = new PoliticianLeaderDemocratic(Firstname, Lastname, Id, Power);
			if (p == NULL)
				abort;

			for (int i = 0; i < s; i++) {
				if ((p->getParty() == NULL)
						|| (p->getParty()->PartySize() > parties[i]->PartySize())) {
					p->addMeToDemocratic(parties[i]);
				}
			}
		} else if (side == 'R') {
			p = new PoliticianLeaderRepublican(Firstname, Lastname, Id, Power);
			if (p == NULL)
				abort;
			for (int i = 0; i < s; i++) {
				if ((p->getParty() == NULL)
						|| (p->getParty()->PartySize() > parties[i]->PartySize())) {
					p->addMeToRepublican(parties[i]);
				}
			}
		}
	} else if (type == 'S') {
		if (side == 'D') {
			p = new PoliticianSocialDemocratic(Firstname, Lastname, Id, Power);
			if (p == NULL)
				abort;
			for (int i = 0; i < s; i++) {
				if ((p->getParty() == NULL)
						|| (p->getParty()->PartySize() > parties[i]->PartySize())) {
					p->addMeToDemocratic(parties[i]);
				}
			}
		} else if (side == 'R') {
			p = new PoliticianSocialRepublican(Firstname, Lastname, Id, Power);
			if (p == NULL)
				abort;
			for (int i = 0; i < s; i++) {
				if ((p->getParty() == NULL)
						|| (p->getParty()->PartySize() > parties[i]->PartySize())) {
					p->addMeToRepublican(parties[i]);
				}
			}
		}
	}

	all_politicians.push_back(p);
	sort(sorted_parties.begin(),sorted_parties.end(),LowerParty());
	return SUCCES;
}

status PoliticalSys::addParty() {
	//TODO: check input*

	cout << "---Create Party---" << endl;
	cout << "Name:" << endl;
	string partyname;
	char side;
	cin >> partyname;
	bool flag = true;
	while (flag) {
		while ((has_number(partyname)) || (PartyExists(partyname))) {
			try {
				if ((has_number(partyname)) || (PartyExists(partyname)))
					throw NameError();
			} catch (Error &e) {
				e.Handle();
				cout << "Name:" << endl;
				cin >> partyname;
			}
		}
		cout << "Republican or Democratic party" << endl;
		cin >> side;
		try {
			if (side != 'R' && side != 'D')
				throw DataError();
			else
				flag = false;
		} catch (Error &e) {
			e.Handle();
			continue;
		}
	}
	Party *p;
	int s = all_politicians.size();
	if (side == 'D') {
		p = new Democratic(partyname);
		if (p == NULL)
			abort;

	} else if (side == 'R') {
		p = new Republican(partyname);
		if (p == NULL)
			abort;

	}
	parties.push_back(p);




	for (int i = 0; i < s; i++) {
				if ((all_politicians[i]->getParty() == NULL) || (all_politicians[i]->getParty()->PartySize() > p->PartySize())) {

						if (side == 'D')
							all_politicians[i]->addMeToDemocratic(p);
						else
							all_politicians[i]->addMeToRepublican(p);

			}
	}
	sorted_parties.push_back(p);
	sort(sorted_parties.begin(),sorted_parties.end(),LowerParty());
	return SUCCES;

}
status PoliticalSys::removePolitician() {
	if (all_politicians.empty())
		return FAILED;
	cout << "---Remove Politician---"<<endl;
	cout << "Enter the ID:"<<endl;
	string Id;
	cin >> Id;
	while (is_number(Id)) {
		try {
			if (is_number(Id))
				throw IDError();
		} catch (Error &e) {
			e.Handle();
			cout << "Enter the ID:"<<endl;
			cin >> Id;
		}
	}
	while (!PoliticianExists(Id)) {
		try {
			if (!PoliticianExists(Id))
				throw IDError();
		} catch (Error &e) {
			e.Handle();
			cout << "Enter the ID:"<<endl;
			cin >> Id;
		}
	}
	int s = parties.size();

	Politician *p;
	for (int i = 0; i < s; i++) {
		p = parties[i]->getPoliticianById(Id);
		if (p != NULL) {
			parties[i]->RemovePolitician(p);
			break;
		}
	}
	int k = all_politicians.size();
	for (int j = 0; j < k; j++) {
		if (all_politicians[j]->getId() == Id) {
			delete all_politicians[j];
			all_politicians.erase(all_politicians.begin() + j);
			sort(sorted_parties.begin(), sorted_parties.end(), LowerParty());

			return SUCCES;
		}
	}

	return FAILED;
}

status PoliticalSys::removeParty() {
	if (parties.empty())
		return FAILED;
	cout << "---Remove Party---"<<endl;
	cout << "Enter party name:"<<endl;
	string partyname;
	cin >> partyname;
	while (has_number(partyname)) {
		try {
			if (has_number(partyname))
				throw NameError();
		} catch (Error &e) {
			e.Handle();
			cout << "Enter party name:"<<endl;
			cin >> partyname;
		}
	}
	while (!PartyExists(partyname)) {
		try {
			if (!PartyExists(partyname))
				throw NameError();
		} catch (Error &e) {
			e.Handle();
			cout << "Enter party name:"<<endl;
			cin >> partyname;
		}
	}
	int s = parties.size();
	vector<Politician*> non_party_all_politicians;
	int i,j;
	for (i = 0; i < s; i++) {
		if (parties[i]->PartyName() == partyname) {
			non_party_all_politicians = parties[i]->deleteMe();
			break;
			}
	}

	int m = sorted_parties.size();
	for (j =0; j<m ; j++){
		if (sorted_parties[j]->PartyName() == partyname) {
			sorted_parties.erase(sorted_parties.begin() + j);

			}
	}
	delete parties[i];
	parties.erase(parties.begin() + i);


	int k = non_party_all_politicians.size();
	s = parties.size();

		for (int j = 0; j <k; j++) {
			for (int i = 0; i < s; i++) {
			if ((non_party_all_politicians[j]->getParty() == NULL)||(non_party_all_politicians[j]->getParty()->PartySize() > parties[i]->PartySize())) {
				non_party_all_politicians[j]->addMeToDemocratic(parties[i]);
				non_party_all_politicians[j]->addMeToRepublican(parties[i]);
			}
		}
	}
	sort(sorted_parties.begin(),sorted_parties.end(),LowerParty());

	non_party_all_politicians.clear();
	return SUCCES;

}
void PoliticalSys::elections() {
	if ((parties.empty()) || (all_politicians.empty()))
		return;
	cout << "----Primaries----"<<endl;

	int s = parties.size();
	for (int j = 0; j < s; j++)
		parties[j]->Primeriz();

	cout << "----Elections----"<<endl;
	int max = 0, p = 0;
	Party *winner;
	for (int j = 0; j < s; j++) {
		cout << "Party: ";
		cout << parties[j]->PartyName();
		cout << ",Power: ";
		p = parties[j]->PartyPower();
		cout << p << endl;
		if (p > max) {
			max = p;
			winner = parties[j];
		}

	}

	cout << "----Elections Results----"<<endl;
	cout << winner->PartyName();
	cout << " party won the elections and ";
	if (winner->PartyChariman())
		cout << winner->PartyChariman()->getName();
	else
		cout << "None";
	cout << " is the prime minister" << endl;

}
void PoliticalSys::printPoliticians() {
	cout << "----Politicians----" << endl;
	int p = all_politicians.size();
	for (int i = 0; i < p; ++i) {
		all_politicians[i]->print();
	}

}
void PoliticalSys::printParties() {
	cout << "----Parties----" << endl;
	int s = parties.size();
	for (int j = 0; j < s; j++)
		parties[j]->print();

}
void PoliticalSys::BiggestParty() {
	cout << "----Biggest Party----" << endl;
	if ((sorted_parties.empty()) || (sorted_parties[0]->PartySize() == 0)){
		cout<<"[None,0]"<< endl;
		return;
	}
	cout<<"[" <<sorted_parties[0]->PartyName()<< ",";
	cout<<sorted_parties[0]->PartySize() << "]"<< endl;
}

bool PoliticalSys::has_number(const string &s) {
	return (s.find_first_of("0123456789") != string::npos);
}

bool PoliticalSys::is_number(const string &s) {
	return (s.find_first_not_of("0123456789") != string::npos);
}
bool PoliticalSys::PoliticianExists(const string &id)
{
	int s = all_politicians.size();
	for (int i =0; i<s; i++)
		if(all_politicians[i]->getId() == id)
			return true;
	return false;
}

bool PoliticalSys::PartyExists(const string &name)
{
	int s = parties.size();
	for (int i =0; i<s; i++)
		if(parties[i]->PartyName() == name)
			return true;
	return false;
}

