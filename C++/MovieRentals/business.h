// -------------------------------- Business.h ---------------------------------
// Program Name: Program 3 : Business Paths

// Team 8: Geoffrey Powell-Isom

// Course: CSS 343 Data Structure and Algorithms 2
// Section Number: A

// Creation Date: 07/16/2019

// Date of Last Modification: 07/29/2019, Monday


// Description:
// this is the main object that will be tested and built.

// -----------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// * This needs files:  Business.cpp, CustomerHash.h, CustomerHash.cpp, Rentables.h,
//                      Rentables.cpp, AVLTree.h, AVLTree.cpp Transaction.h, and Transaction.cpp
// * Standard libraries:
//   - iostream
//   - fstream
//   - queue

// -----------------------------------------------------------------------------

#ifndef BUSINESS_H
#define BUSINESS_H

#include <iostream>
#include <fstream>
#include <queue>

#include "CustomerHash.h"
#include "Movie.h"
#include "Transaction.h"
#include "AVLTree.h"

class Business
{
    public:
        // Description: this creates a new Business
        // preconditions: *this is a totally un-initialized Business
        // postconditions: The fields of *this will be initialized, and the
        // Business will contain default values for its data
        Business();

        // Description: destroys and decomposes Business memory, as-needed
        // preconditions: *this is in any valid state
        // postconditions: all dynamically allocated memory is freed, and the
        // Business is in a deletable state
        virtual ~Business();

        // Description: loads Customer into CustomerHash table
        // preconditions: *this has already been initialized, and is valid
        // postconditions: The file will have been read, &
		// The customers will be in the CustomerHash table
        //@param custFile is the ifstream object of the file
        void loadCustomers(std::ifstream& custFile);
		// psuedo-code:
		// checks the file is open
		// loads customers by calling customerHash's loadCustomers.


        // Description: loads the movies from movieFile into the Movie database
        // preconditions: *this has already been initialized, and is valid
        // postconditions: The file will have been read, &
		//                 The Movies will be in the database
        //@param movieFile is the ifstream object of the file
        void loadMovies(std::ifstream& movieFile);
		//psuedo-code:
		// 
		// checks that the file is open.
		// loads movies by reading lines and calling AVLTree's insertNode function for each line
		//


   
        // Description: loads the commmands from comFile into a Queue
        // preconditions: *this has already been initialized
        // postconditions: The file will have been read, and the commands stored
		// run.
        //@param comFile is the ifstream object of the file
        void loadCommands(std::ifstream& comFile);
		// psuedo-code:
		//
		// check the file is open.
		// read line by line.
		// 
		// if (the line's first character is 'I') call AVLTree's PrintInventory;
		// if (the line's first character is  'B' or 'R'){
		//		if (Check that get customer doesn't return a nullptr) print an error message;
		//		else{
		//			Call ChangeStock to increase or decrease the stock.
		//			if (changeStock doens't return NULL) Add the transaction to the customer's vector of transactions.
		//		}
		// }
		// if (the line's first character is 'H'){
		//		check that the customer exists
		//		print the customer's transactoins
		// }



        // --------------------------displayBusiness----------------------------
        // Description: uses couts to output business information
        // preconditions: *this has already been initialized, and is valid
        // postconditions: data from the Business will have been put to cout
        // ---------------------------------------------------------------------
        void displayBusiness();
		// Displays the inventory by calling AVLTree's displayInventory.
		// Displays customers and their transactions.

    protected:

    private:
	   
		CustomerHash       custTable;  //CustomerHash table of the customers
		AVLTree              rentablesDB;// database of rentables
};

#include "Business.cpp"

#endif // BUSINESS_H