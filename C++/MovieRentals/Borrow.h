//
// Created by jneigel1 on 8/16/19.
//

#ifndef PROGRAM4_BORROW_H
#define PROGRAM4_BORROW_H



#include "Transaction.h"


// Description: a Borrow Class header.
// Borrow is a derived class from the Transaction class
class Borrow : public Transaction
{

public:

	// Description: this is the defualt constructor.
	// preconditions: None.
	// postconditions: a transaction is constructed.
	Borrow(Product* i);


	// Description: this is the deconstructor.
	// preconditions: None.
	// postconditions: a Borrow is deconstructed
    virtual ~Borrow();

	// Description: displays private variable values.
	// preconditions: None.
	// postconditions: private variable values are displayed.
//	virtual void display(ostream& os) const;
	// prints borrow and then prints the item.
//getters

    // Description: accesses actionType.
    // preconditions: None.
    // postconditions: actionType is returned.
    virtual char getActionType();

protected:

	// Description: this is the a constructor with parameters.
	// preconditions: None.
	// postconditions: a Borrow copy is constructed.
	Borrow(char actionType, Product* i);

	Product* item; // Product class is base class of derived Movies class

};

#include "Borrow.cpp"

#endif //PROGRAM4_BORROW_H
