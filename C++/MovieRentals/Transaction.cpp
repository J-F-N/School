//
//  Transaction.cpp
//
//
//  Created by Geoffrey Powell-Isom on 8/16/19.
//


#include "Transaction.h"

// Description: this is the defualt constructor.
// preconditions: None.
// postconditions: a transaction is constructed.
Transaction::Transaction()
{
    actionType = 0; //There is NO action for the plain Transaction
}


// Description: this is the copy constructor.
// preconditions: Transaction to copy.
// postconditions: a transaction is copied.
Transaction::Transaction(char a)
{
    this->actionType = a;
}


// Description: this is the deconstructor.
// preconditions: None.
// postconditions: a transaction deconstructed.
Transaction::~Transaction()
{
    //nothing to do here; All is stack-based.
}


//getters

// Description: accesses actionType.
// preconditions: None.
// postconditions: actionType is returned.
char Transaction::getActionType()
{
    return actionType;
}

// Description: this method displays the transactions to
// os.
// This is a pure virtual function.
// preconditions: None.
// postconditions: None
//Transaction::void display(ostream os) const = 0;

//getters

// Description: accesses actionType.
// preconditions: None.
// postconditions: actionType is returned.
//char Transaction::getActionType() = 0;


