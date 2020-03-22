#ifndef NODEDATA_H
#define NODEDATA_H

// Description:
// This file contains the interface for the NODEDATA that contains
// a pointer to rentables.

#include <string>
#include <iostream>
#include <fstream>
#include "Rentables.h"


using namespace std;

// This class contains data of an AVl NODE
class NodeData {

    friend ostream & operator<<(ostream &, const NodeData &);

    public:

		//Description: This creates a new NodeData object
		//Preconditions: This object is un-initialized
		//Postconditions: This Object is initialized
    	NodeData();

		//Description: This creates a new NodeData object using a string
		//Preconditions: This object is un-initialized
		//Postconditions: This Object is initialized
    	NodeData(string);

		//Description: This destroys this NodeData object
		//Preconditions: This object is initialized
		//Postconditions: This Object is destroyed
    	~NodeData();

		//Description: This creates a new NodeData object using a Rentable object
		//Preconditions: This object is un-initialized
		//Postconditions: This Object is initialized
    	NodeData(const Rentable&);

		//Description: This creates a new NodeData object using another NodeData object (deep copy)
		//Preconditions: This object is un-initialized
		//Postconditions: This Object is initialized using the data from the passed in NodeData object
    	NodeData(const NodeData &);

		//Description: This NodeData object copies the Rentable data from another NodeData object
		//Preconditions: This object is initialized
		//Postconditions: This object made a deep copy of the passed in NodeData object
    	NodeData& operator=(const NodeData &);

		//Description: This creates a new Rentable Object using the string, and sets it to the RentableData
		//Preconditions: This Object is initialized
		//Postconditions: RentableData will contain a pointer to a Rentable
    	bool setData(string );

		// Description: this is the equality operator
		// preconditions: the parameter is already  initialized
		// postconditions: returns True if the rentables are equal.
    	bool operator==(const NodeData &) const;

		// Description: this is the inequality operator
		// preconditions: the parameter is already  initialized
		// postconditions: returns True if the rentables are not equal.
    	bool operator!=(const NodeData &) const;

		// Description: this is the less than operator
		// preconditions: the parameter is already  initialized
		// postconditions: returns True if the *this is less than the parameter.
    	bool operator<(const NodeData &) const;

		// Description: this is the less than operator
		// preconditions: the parameter is already  initialized
		// postconditions: returns True if *this is more than the parameter.
    	bool operator>(const NodeData &) const;

		// Description: this is the less than or equal operator
		// preconditions: the parameter is already  initialized
		// postconditions: returns True if the *this is less than or equal to the parameter.
    	bool operator<=(const NodeData &) const;

		// Description: this is the more than or equal operator
		// preconditions: the parameter is already  initialized
		// postconditions: returns True if *this is more than the parameter.
    	bool operator>=(const NodeData &) const;

private:

    Rentable* rentable;
};

#endif