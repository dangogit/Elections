/*
 * PoliticianSocialRepublican.h
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#ifndef POLITICIANSOCIALREPUBLICAN_H_
#define POLITICIANSOCIALREPUBLICAN_H_

#include "Social.h"

class PoliticianSocialRepublican: public Social {
public:
	PoliticianSocialRepublican(string Firstname, string Lastname, string Id, int Power):Social(Firstname, Lastname, Id, Power){}
	virtual ~PoliticianSocialRepublican();
	virtual void print() const;
	virtual void addMeToDemocratic(Party* partyto) {}
	virtual void addMeToRepublican(Party* partyto);
};

#endif /* POLITICIANSOCIALREPUBLICAN_H_ */
