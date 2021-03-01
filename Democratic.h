/*
 * Democratic.h
 *
 *  Created on: Jan 10, 2020
 *      Author: ise
 */

#ifndef DEMOCRATIC_H_
#define DEMOCRATIC_H_

#include "Party.h"

class Democratic: public Party {
public:
	Democratic(string partyname);
	virtual ~Democratic();
	virtual status AddDemocraticPolitician(Politician* person);
	virtual status AddRepublicanPolitician(Politician* person) { return FAILED; }
    virtual int DemocraticPartySize() { return politicians.size();}
    virtual int RepublicanPartySize() { return -1; }
	virtual void print() const;
};



#endif /* DEMOCRATIC_H_ */
