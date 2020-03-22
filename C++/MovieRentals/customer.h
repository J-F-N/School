//
// Created by John Neigel on 08/06/2019
//

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<string>
#include<iostream>
#include<vector>
#include<sstream>

#include "Transaction.h"

using namespace std;

//STUB Transaction CLASS
//class Transaction{
//public:
//    Transaction(){}
//    virtual ~Transaction(){}
//};

/*
Descriptioin:
This file is the interface for the Customer class. Each object of this class
represents a current customer of the business. The objects are hashed into the
hash table. Each object stores it's own transaction history in a vector, which
is updated as transactions are processed.
*/

// represents a customer
class Customer
{
    friend std::ostream& operator<<(std::ostream& output, Customer& c);
public:

	//default constructor.
	Customer();

	//parameterized constructor.
	//string param is parsed to initialize instance data fields.
	//preconditions: a string with valid data format is passed in.
	//postconditions: a new instance of customer is created.
	Customer(string customerLine);

	//Description: destructor.
	//preconditions: None
	//postconditions: *this is destroyed.
	~Customer();

	//returns calling objects customerID.
	//preconditions: must be called on a valid instance of customer.
	//postconditions: instance values remain unchanged.
	int getID() const;

	//returns calling objects firstName.
	//preconditions: must be called on a valid instance of customer.
	//postconditions: instance values remain unchanged.
	string getFirstName() const;

	//returns calling objects lastName.
	//preconditions: must be called on a valid instance of customer.
	//postconditions: instance values remain unchanged.
	string getLastName() const;

	//prints the customers transaction history.
	void printHistory() const;
	// Prints the transactions one by one.

	//stores the passed Transaction param in this objects history
	//by inserting it into the vector
	//preconditions: proper param passed
	//postconditions: the objects tranHistory contains the param Transaction
    void storeTransaction(Transaction* trans);
	// psuedo-code:
	// use push_bach to put transaction at the end of the vector.

private:

	int customerID;						//customer's ID.
	string firstName;					//cutomer's first name.
	string lastName;					//customer's last name.
    vector<Transaction*> transHistory;  //vector to store this customer's transaction history.
};

std::ostream& operator<<(std::ostream& output, Customer& c)
{
    if(c.getID() < 1000) output << "0";
    if(c.getID() <  100) output << "0";
    if(c.getID() <   10) output << "0";
    output << c.getID() << ' ' << c.getLastName() << ' ' << c.getFirstName();
    return output;
}

#include "customer.cpp"

#endif // CUSTOMER_H
