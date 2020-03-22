#ifndef TRANSACTION_H
#define TRANSACTION_H

// Author Name: Design Group 8

// Description: a Transaction Class header. Transaction is an abstract class
// functioning as a base class for Transaction style classes
//
// Current derived classes include Borrow, Return, History, and Inventory


#include "Product.h"


#include <iostream>
using namespace std;

//
class Transaction
{

public:

    friend ostream& operator<<(std::ostream& output, Transaction& t);



	// Description: this is the defualt constructor.
	// preconditions: None.
	// postconditions: a transaction is constructed.
	Transaction();


	// Description: this is the deconstructor.
	// preconditions: None.
	// postconditions: a transaction deconstructed.
    virtual ~Transaction();

	// Description: this method displays the transactions to
	// os.
	// This is a pure virtual function.
	// preconditions: None.
	// postconditions: None
//	virtual void display(ostream& os) const = 0;

	//getters

	// Description: accesses actionType.
	// preconditions: None.
	// postconditions: actionType is returned.
	virtual char getActionType();

protected:
	char actionType; // the action will be able to identify itself


	// Description: this is the copy constructor.
	// preconditions: Transaction to copy.
	// postconditions: a transaction is copied.
	Transaction(char actionType);

};

ostream& operator<<(std::ostream& output, Transaction& t)
{
//    t.display(output);

    output << t.getActionType();
    return output;
}



#include "Borrow.h"
#include "Return.h"
#include "Inventory.h"
#include "History.h"

#include "Transaction.cpp"

#endif //TESTDESIGN_Transaction_H
