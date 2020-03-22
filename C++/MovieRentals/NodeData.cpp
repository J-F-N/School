//
//  NodeData.cpp
//  
//
//  Created by Geoffrey Powell-Isom on 8/16/19.
//

#include "NodeData.h"


    
//Description: This creates a new NodeData object
//Preconditions: This object is un-initialized
//Postconditions: This Object is initialized
NodeData::NodeData()
{
    
}

//Description: This creates a new NodeData object using a string
//Preconditions: This object is un-initialized
//Postconditions: This Object is initialized
NodeData::NodeData(string)
{
    
}

//Description: This destroys this NodeData object
//Preconditions: This object is initialized
//Postconditions: This Object is destroyed
virtual NodeData::~NodeData()
{
    
}

//Description: This creates a new NodeData object using a Rentable object
//Preconditions: This object is un-initialized
//Postconditions: This Object is initialized
NodeData::NodeData(const Rentable&)
{
    
}

//Description: This creates a new NodeData object using another NodeData object (deep copy)
//Preconditions: This object is un-initialized
//Postconditions: This Object is initialized using the data from the passed in NodeData object
NodeData::NodeData(const NodeData &)
{
    
}

//Description: This NodeData object copies the Rentable data from another NodeData object
//Preconditions: This object is initialized
//Postconditions: This object made a deep copy of the passed in NodeData object
NodeData& NodeData::operator=(const NodeData &)
{
    
}

//Description: This creates a new Rentable Object using the string, and sets it to the RentableData
//Preconditions: This Object is initialized
//Postconditions: RentableData will contain a pointer to a Rentable
bool NodeData::setData(string )
{
    
}

// Description: this is the equality operator
// preconditions: the parameter is already  initialized
// postconditions: returns True if the rentables are equal.
bool NodeData::operator==(const NodeData &) const
{
    
}

// Description: this is the inequality operator
// preconditions: the parameter is already  initialized
// postconditions: returns True if the rentables are not equal.
bool NodeData::operator!=(const NodeData &) const
{
    
}

// Description: this is the less than operator
// preconditions: the parameter is already  initialized
// postconditions: returns True if the *this is less than the parameter.
bool NodeData::operator<(const NodeData &) const
{
    
}

// Description: this is the less than operator
// preconditions: the parameter is already  initialized
// postconditions: returns True if *this is more than the parameter.
bool NodeData::operator>(const NodeData &) const
{
    
}

// Description: this is the less than or equal operator
// preconditions: the parameter is already  initialized
// postconditions: returns True if the *this is less than or equal to the parameter.
bool NodeData::operator<=(const NodeData &) const
{
    
}

// Description: this is the more than or equal operator
// preconditions: the parameter is already  initialized
// postconditions: returns True if *this is more than the parameter.
bool NodeData::operator>=(const NodeData &) const
{
    
}

