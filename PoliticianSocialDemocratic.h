/*
 * PoliticianSocialDemocratic.h
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#ifndef POLITICIANSOCIALDEMOCRATIC_H_
#define POLITICIANSOCIALDEMOCRATIC_H_

#include "Social.h"

class PoliticianSocialDemocratic: public Social {
public:
	PoliticianSocialDemocratic(string Firstname, string Lastname, string Id, int Power):Social(Firstname, Lastname, Id, Power){}
	virtual ~PoliticianSocialDemocratic();
	virtual void print() const;
	virtual void addMeToDemocratic(Party* partyto);
	virtual void addMeToRepublican(Party* partyto){}
};

#endif /* POLITICIANSOCIALDEMOCRATIC_H_ */
