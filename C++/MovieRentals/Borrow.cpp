//
// Created by jneigel1 on 8/16/19.
//

#include "Borrow.h"

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/


// Description: this is the a constructor with parameters.
// preconditions: None.
// postconditions: a Borrow copy is constructed.
Borrow::Borrow(Product* i) : Transaction('B')
{
    item = i;
}


// preconditions: None.
// postconditions: a Borrow copy is constructed.

Borrow::Borrow(char actionType, Product* i) : Transaction(actionType)
{
    this->item = i;
}


// Description: this is the deconstructor.
// preconditions: None.
// postconditions: a Borrow is deconstructed
Borrow::~Borrow()
{
    delete item;
}


//getters

// Description: accesses actionType.
// preconditions: None.
// postconditions: actionType is returned.
char Borrow::getActionType()
{
    return actionType;
}
