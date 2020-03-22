//
// Created by jneigel1 on 8/16/19.
//

#ifndef PROGRAM4_RETURN_H
#define PROGRAM4_RETURN_H


#include "Transaction.h"


// Description: a Return Class header.
// Return is a derived class from the Transaction class
//
// when Return class is called, if customer has the item, stock = (stock + 1)

class Return : public Borrow
{

public:

	// Description: this is the a constructor.
	// preconditions: None.
	// postconditions: a Return is made.
	Return(Product* item);

	// Description: this is the deconstructor.
	// preconditions: None.
	// postconditions: a Return is deconstructed
    virtual ~Return();

	// Description: displays private variable values.
	// preconditions: None.
	// postconditions: private variable values are displayed.
//	virtual void display(ostream& os) const;

	//getters

	// Description: accesses actionType.
	// preconditions: None.
	// postconditions: actionType is returned.
	char getActionType();
};


#include "Return.cpp"

#endif //PROGRAM4_RETURN_H
