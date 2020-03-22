#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

// Author Name: Design Group 8

// Description: a Transaction Class header. Transaction is an abstract class
// functioning as a base class for Transaction style classes
//
// Current derived classes include Borrow, Return, History, and Inventory


#include "Rentables.h"


#include <iostream>
using namespace std;

//
class Transaction
{

public:

	// Description: this is the defualt constructor.
	// preconditions: None.
	// postconditions: a transaction is constructed.
	Transaction();


	// Description: this is the copy constructor.
	// preconditions: Transaction to copy.
	// postconditions: a transaction is copied.
	Transaction(char actionType);


	// Description: this is the deconstructor.
	// preconditions: None.
	// postconditions: a transaction deconstructed.
	virtual ~Transaction();

	// Description: this method displays the transactions to 
	// os.
	// This is a pure virtual function.
	// preconditions: None.
	// postconditions: None
	virtual void display(ostream os) const = 0;

	//getters

	// Description: accesses actionType.
	// preconditions: None.
	// postconditions: actionType is returned.
	char getActionType();

protected:
	char actionType; // the action will be able to identify itself

};

// Description: a Borrow Class header.
// Borrow is a derived class from the Transaction class
class Borrow : public Transaction
{

public:

	// Description: this is the a constructor with parameters.
	// preconditions: None.
	// postconditions: a Borrow copy is constructed.
	Borrow(char actionType, Rentable item) : Transaction(actionType)
	{
		this->item = item;
	}


	// Description: this is the deconstructor.
	// preconditions: None.
	// postconditions: a Borrow is deconstructed
	virtual ~Borrow();

	// Description: displays private variable values.
	// preconditions: None.
	// postconditions: private variable values are displayed.
	virtual void display(ostream os) const;
	// prints borrow and then prints the item.

protected:

	char mediaType; // the media type i.e. D for DVD

	Rentable* item; // Item class is base class of derived Movies class

};


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
	Return(char actionType, Rentable item) : Borrow(actionType, item) {}

	// Description: this is the deconstructor.
	// preconditions: None.
	// postconditions: a Return is deconstructed
	virtual ~Return();

	// Description: displays private variable values.
	// preconditions: None.
	// postconditions: private variable values are displayed.
	virtual void display(ostream os) const;
};


// Author Name: Design Group 8

// Description: a History Class header.
// History is a derived class from the Transaction class
//
// calls Customer class to print out history vector

class Customer; //forward reference

class History : public Transaction
{

public:

	// Description: this is the a constructor.
	// preconditions: None.
	// postconditions: a Histoyr is made.
	History(char c) : Transaction(c) {}

	// Description: this is the deconstructor.
	// preconditions: None.
	// postconditions: a History is deconstructed
	virtual ~History();



	// Description: displays the transaction.
	// preconditions: None.
	// postconditions: 'H' is displayed.
	virtual void display(ostream os) const;
};



// Description: a Inventory Class header.
// Inventory is a derived class from the Transaction class
class Inventory : public Transaction
{

	
public:

	// Description: this is the a constructor.
	// preconditions: None.
	// postconditions: an Inventory is made.
	Inventory(char c) : Transaction(c) {}

	// Description: this is the deconstructor.
	// preconditions: None.
	// postconditions: an Inventory is deconstructed
	virtual ~Inventory();

	
	// Description: displays the transaction.
	// preconditions: None.
	// postconditions: 'I' is printed to os.
	virtual void display(ostream os);

};

#endif //TESTDESIGN_Transaction_H
