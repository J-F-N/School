// -------------------------------- Business.h ---------------------------------
// Program Name: Program 3 : Business Paths

// Student: Geoffrey Powell-Isom

// Course: CSS 343 Data Structure and Algorithms 2
// Section Number: A

// Creation Date: 07/16/2019

// Date of Last Modification: 07/29/2019, Monday

// -----------------------------------------------------------------------------
// Purpose - a brief statement of the program's function
// This tests the libraryies of Program 3, by running their functions, and using
// demo input files.

// -----------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// * This needs files:  Business.cpp, CustomerHash.h, CustomerHash.cpp, Movie.h,
//                      Movie.cpp, Transaction.h, and Transaction.cpp
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
#include <vector>
#include <sstream>

#include "CustomerHash.h"
//#include "Movie.h"
#include "Transaction.h"
//#include "AVLTree.h"

class Business
{
    public:
        // ------------------------------Business-------------------------------
        // Description: this creates a new Business
        // preconditions: *this is a totally un-initialized Business
        // postconditions: The fields of *this will be initialized, and the
        //                 Business will contain default values for its data
        // ---------------------------------------------------------------------
        Business();

        // ------------------------------~Business------------------------------
        // Description: destroys and decomposes Business memory, as-needed
        // preconditions: *this is in any valid state
        // postconditions: all dynamically allocated memory is freed, and the
        //                 Business is in a deletable state
        // ---------------------------------------------------------------------
        virtual ~Business();

        // ---------------------------loadCustomers-----------------------------
        // Description: loads Customer into CustomerHash table
        // preconditions: *this has already been initialized, and is valid
        // postconditions: The file will have been read, &
		//                 The customers will be in the CustomerHash table
        //@param custFile is the ifstream object of the file
        // ---------------------------------------------------------------------
        void loadCustomers(std::ifstream& custFile);

        // -----------------------------loadMovies------------------------------
        // Description: loads the movies from movieFile into the Movie database
        // preconditions: *this has already been initialized, and is valid
        // postconditions: The file will have been read, &
		//                 The Movies will be in the database
        //@param movieFile is the ifstream object of the file
        // ---------------------------------------------------------------------
        void loadMovies(std::ifstream& movieFile);

        // -----------------------------loadMovies------------------------------
        // Description: helps loadMovies()
        // preconditions: Only use from loadMovies()
        // postconditions: The input line is used or rejected
        //@param inputLine is the input line from the ifstream
        // ---------------------------------------------------------------------
        void loadMoviesHelper(string inputString);

        // ----------------------------loadCommands-----------------------------
        // Description: loads the commmands from comFile into a Queue
        // preconditions: *this has already been initialized
        // postconditions: The file will have been read, and the commands stored
		//                 in the comQueue
        //@param comFile is the ifstream object of the file
        // ---------------------------------------------------------------------
        void loadCommands(std::ifstream& comFile);

        // --------------------------displayBusiness----------------------------
        // Description: uses couts to output business information
        // preconditions: *this has already been initialized, and is valid
        // postconditions: data from the Business will have been put to cout
        // ---------------------------------------------------------------------
        void displayBusiness();

        void loadCommandsHelper(string inputLine);

    protected:

    private:

        CustomerHash custTable; //CustomerHash table of the customers
        ProductDB      productDB; // database of products
};

#include "Business.cpp"

#endif // BUSINESS_H
