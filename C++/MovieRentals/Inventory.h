//
// Created by jneigel1 on 8/16/19.
//

#ifndef PROGRAM4_INVENTORY_H
#define PROGRAM4_INVENTORY_H


#include "Transaction.h"

// Description: a Inventory Class header.
// Inventory is a derived class from the Transaction class
class Inventory : public Transaction
{


public:

	// Description: this is the a constructor.
	// preconditions: None.
	// postconditions: an Inventory is made.
	Inventory();

	// Description: this is the deconstructor.
	// preconditions: None.
	// postconditions: an Inventory is deconstructed
	virtual ~Inventory();


	// Description: displays the transaction.
	// preconditions: None.
	// postconditions: 'I' is printed to os.
//	virtual void display(ostream& os) const;

	//getters

	// Description: accesses actionType.
	// preconditions: None.
	// postconditions: actionType is returned.
	char getActionType();

//protected:
//	char actionType; // the action will be able to identify itself
//
//
//	// Description: this is the copy constructor.
//	// preconditions: Transaction to copy.
//	// postconditions: a transaction is copied.
//	Transaction(char actionType);

};

#include "Inventory.cpp"

#endif //PROGRAM4_INVENTORY_H
