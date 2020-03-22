//
// Created by jneigel1 on 8/16/19.
//

#include "History.h"

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/



// Description: this is the a constructor.
// preconditions: None.
// postconditions: a Histoyr is made.
History::History() : Transaction('H')
{
    actionType = 'H';
    //NOTHING GOES HERE
    //Inventory is just used to move a command through, to have the inventory of the Products reported.
}

// Description: this is the deconstructor.
// preconditions: None.
// postconditions: a History is deconstructed
History::~History()
{
    //NOTHING GOES HERE
    //Inventory objects have NO dynamically allocated memory.
}

//getters

// Description: accesses actionType.
// preconditions: None.
// postconditions: actionType is returned.
char History::getActionType()
{
    return actionType;
}

// Description: displays the transaction.
// preconditions: None.
// postconditions: 'H' is displayed.
//void History::display(ostream& os) const
//{
//    os << actionType;
//}

