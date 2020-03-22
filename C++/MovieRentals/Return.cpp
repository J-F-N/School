//
// Created by jneigel1 on 8/16/19.
//

#include "Return.h"



// Description: this is the a constructor.
// preconditions: None.
// postconditions: a Return is made.
Return::Return(Product* i) : Borrow('R', i)
{

}

// Description: this is the deconstructor.
// preconditions: None.
// postconditions: a Return is deconstructed
Return::~Return()
{

}

// Description: displays private variable values.
// preconditions: None.
// postconditions: private variable values are displayed.
//void Return::display(ostream& os) const
//{
//
//getters

// Description: accesses actionType.
// preconditions: None.
// postconditions: actionType is returned.
char Return::getActionType()
{
    return actionType;
}

