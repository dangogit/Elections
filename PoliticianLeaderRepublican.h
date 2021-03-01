/*
 * PoliticianLeaderRepublican.h
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#ifndef PoliticianLeaderRepublican_H_
#define PoliticianLeaderRepublican_H_

#include "Leader.h"

class PoliticianLeaderRepublican: public Leader {
public:
	PoliticianLeaderRepublican(string Firstname, string Lastname, string Id, int Power):Leader(Firstname, Lastname, Id, Power){}
	virtual ~PoliticianLeaderRepublican();
	virtual void print() const;
	virtual void addMeToDemocratic(Party* partyto){}
	virtual void addMeToRepublican(Party* partyto);
};

#endif /* PoliticianLeaderRepublican_H_ */
