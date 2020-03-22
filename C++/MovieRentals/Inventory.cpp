//
// Created by jneigel1 on 8/16/19.
//

#include "Inventory.h"


// Description: this is the a constructor.
// preconditions: None.
// postconditions: an Inventory is made.
Inventory::Inventory() : Transaction('I')
{
    //NOTHING GOES HERE
    //Inventory is just used to move a command through, to have the inventory of the Products reported.
}

// Description: this is the deconstructor.
// preconditions: None.
// postconditions: an Inventory is deconstructed
Inventory::~Inventory()
{
    //NOTHING GOES HERE
    //Inventory objects have NO dynamically allocated memory.
}


// Description: displays the transaction.
// preconditions: None.
// postconditions: 'I' is printed to os.
//void Inventory::display(ostream& os) const
//{
//    os << actionType;
//}
//getters

// Description: accesses actionType.
// preconditions: None.
// postconditions: actionType is returned.
char Inventory::getActionType()
{
    return actionType;
}
