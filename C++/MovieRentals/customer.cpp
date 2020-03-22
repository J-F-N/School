//
//  customer.cpp
//
//

/*
 Descriptioin:
 This file is the interface for the Customer class. Each object of this class
 represents a current customer of the business. The objects are hashed into the
 hash table. Each object stores it's own transaction history in a vector, which
 is updated as transactions are processed.
 */
//  Created by Geoffrey Powell-Isom on 8/16/19.
//

#include "customer.h"

//default constructor.
Customer::Customer()
{
    customerID = 0;
    firstName  = "";
    lastName   = "";
    vector<Transaction> transHistory;
}

//parameterized constructor.
//string param is parsed to initialize instance data fields.
//preconditions: a string with valid data format is passed in.
//postconditions: a new instance of customer is created.
Customer::Customer(string customerLine)
{
    stringstream strin(customerLine);

    strin >> this->customerID >> this->lastName >> this->firstName;
}

//Description: destructor.
//preconditions: None
//postconditions: *this is destroyed.
Customer::~Customer()
{
    //customerID = 0;
    //firstName  = "";
    //lastName   = "";
    //vector<Transaction> transHistory;
}

//returns calling objects customerID.
//preconditions: must be called on a valid instance of customer.
//postconditions: instance values remain unchanged.
int Customer::getID() const
{
    return this->customerID;
}

//returns calling objects firstName.
//preconditions: must be called on a valid instance of customer.
//postconditions: instance values remain unchanged.
string Customer::getFirstName() const
{
    return this->firstName;
}

//returns calling objects lastName.
//preconditions: must be called on a valid instance of customer.
//postconditions: instance values remain unchanged.
string Customer::getLastName() const
{
    return this->lastName;
}

//prints the customers transaction history.
void Customer::printHistory() const
{
    // Prints the transactions one by one
    cout << "Printing customer History for ID " << getID() << ", " << lastName << ", " << firstName << endl;
    cout << "size of History is " << transHistory.size() << endl;
    for(int i = transHistory.size() - 1; i >= 0; --i)
    {
        cout << *transHistory[i] << endl;
    }

//    cout << transHistory << endl;
}

//stores the passed Transaction param in this objects history
//by inserting it into the vector
//preconditions: proper param passed
//postconditions: the objects tranHistory contains the param Transaction
void Customer::storeTransaction(Transaction* trans)
{
    // psuedo-code:
    // use push_bach to put transaction at the end of the vector.

    this->transHistory.push_back(trans);
}
