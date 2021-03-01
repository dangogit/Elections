/*
 * Error.h
 *
 *  Created on: Jan 13, 2020
 *      Author: ise
 */
#pragma once

#include <iostream>
using namespace std;

class Error {
public:
	virtual ~Error(){}
	virtual void Handle()const = 0;
};


class IDError: public Error{
public:
	virtual ~IDError(){}
	virtual void Handle()const { cout<<"Please enter valid id"<<endl;}
};

class NameError: public Error{
public:
	virtual ~NameError(){}
	virtual void Handle()const{ cout<<"Please enter valid name"<<endl;}
};

class DataError: public Error{
public:
	virtual ~DataError(){}
	virtual void Handle()const{ cout<<"Please enter valid details"<<endl;}
};
