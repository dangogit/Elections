/*
 * Party.cpp
 *
 *  Created on: Jan 9, 2020
 *      Author: ise
 */

#include "Party.h"
int Party::counter = 0;

Party::Party(string partyname){
	counter++;
	this->name = partyname;
	this->id = counter;
	this->current_max_power = 0;
	this->p_chairman = NULL;
}

Party::~Party() {
	politicians.clear();
}

Party::Party(const Party &other) {
	this->name = other.name;
	this->id = other.id;
	this->current_max_power = other.current_max_power;
	this->p_chairman = other.p_chairman;
	this->politicians = other.politicians;

}

void Party::print()const {
	cout<<"Party: ";
	cout<< name << ", ";
	cout << "chairman:";
	if (p_chairman)
		cout << p_chairman->getName();
	else
		cout << "None";
	cout<<", Size:";
	int p = politicians.size();
	cout<<p<<endl;

	for (int i = 0; i< p; i++)
	{
		cout<<"\t";
		politicians[i]->print();
	}
}


status Party::RemovePolitician(Politician* person){
	if (person == NULL)
		return BAD_DATA;
	else if (person == p_chairman)
	{
		p_chairman = NULL;
		notify();
	}
	int s = politicians.size();
	int p = person->getPower();
	for (int i = 0; i<s; i++){
		if (politicians[i]->getId() == person->getId()){
			politicians.erase(politicians.begin()+i);
			break;
		}
	}
	s = politicians.size();
	if (p == current_max_power)
	{
		current_max_power = 0;
		for (int i = 0; i<s; i++){
			if 	(politicians[i] == NULL){
				politicians.erase(politicians.begin()+i);
				continue;
			}
			if ((politicians[i]->getPower()>current_max_power) && (politicians[i]->isGoodForPrimeriz()))
				current_max_power = politicians[i]->getPower();
		}
	}
	return SUCCES;

}
status Party::Primeriz(){
	int s = politicians.size();
	for (int i = 0; i<s; i++)
			if ((politicians[i]->getPower()==current_max_power) && (politicians[i]->isGoodForPrimeriz()))
			{
				p_chairman = politicians[i];
				notify();
				cout<< p_chairman->getName();
				cout<<" is the chairman of ";
				cout<< name << endl;
				return SUCCES;
			}
	cout<<"None is the chairman of ";
	cout<< name << endl;
	return FAILED;
}
int Party::PartyPower(){
	int total = 0;
	int s = politicians.size();
	for (int j = 0;j<s;j++)
	{
		if (!(politicians[j]->isGoodForPrimeriz()))
			total +=politicians[j]->getPower();
		total +=politicians[j]->getPower();
	}
	return total;

}

int Party::PartySize()
{
	return politicians.size();
}
string Party::PartyName()
{
	return name;
}
Politician* Party::PartyChariman(){
	return p_chairman;
}

Politician* Party::getPoliticianById(string id)
{
		int s = politicians.size();
		for (int i = 0; i<s; i++)
			if (politicians[i]->getId() == id)
				return politicians[i];
		return NULL;
}
void Party::notify()
{
		int s = politicians.size();
		for (int i = 0; i<s; i++)
			politicians[i]->update_chairman(p_chairman);
}

vector<Politician*> Party::deleteMe()
{
	int s = politicians.size();
	for (int i = 0; i<s; i++){
		p_chairman = NULL;
		notify();
		politicians[i]->setParty(NULL);
	}


	return politicians;
}

