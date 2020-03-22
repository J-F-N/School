//
// Created by jneigel1 on 8/16/19.
//

#ifndef PROGRAM4_HISTORY_H
#define PROGRAM4_HISTORY_H


#include "Transaction.h"

// Author Name: Design Group 8

// Description: a History Class header.
// History is a derived class from the Transaction class
//
// calls Customer class to print out history vector

class Customer; //forward reference

class History : public Transaction
{
//friend ostream& operator<<(std::ostream& output, History& t);

public:

	// Description: this is the a constructor.
	// preconditions: None.
	// postconditions: a Histoyr is made.
	History();

	// Description: this is the deconstructor.
	// preconditions: None.
	// postconditions: a History is deconstructed
	virtual ~History();



	// Description: displays the transaction.
	// preconditions: None.
	// postconditions: 'H' is displayed.
//	virtual void display(ostream& os) const;

	//getters

	// Description: accesses actionType.
	// preconditions: None.
	// postconditions: actionType is returned.
	char getActionType();
};

//ostream& operator<<(std::ostream& output, History& t)
//{
////    t.display(output);
//    output << "We're running in History! ";
//    output << t.getActionType();
//    return output;
//}


#include "History.cpp"

#endif //PROGRAM4_HISTORY_H
