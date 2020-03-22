// -------------------------- CustomerCustomerHash.h ---------------------------
// Program Name: Program 4 : Finite State Machine

// Student: Geoffrey Powell-Isom

// Course: CSS 343 Data Structure and Algorithms 2
// Section Number: A

// Creation Date: 08/05/2019, Monday

// Date of Last Modification: 08/06/2019, Tuesday

// -----------------------------------------------------------------------------
// Purpose - a brief statement of the program's function
// This creates, stores, and manages the CustomerHash table for the Finite State
// Machine's Customers.

// -----------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// * This file requires the Customer.h, Customer.cpp, and CustomerHash.cpp files
// * Standard libraries:
//   - iostream
//   - fstream

// -----------------------------------------------------------------------------

#ifndef CUSTOMERHASH_H
#define CUSTOMERHASH_H

#include <iostream>
#include <fstream>
#include <sstream>

#include "customer.h"

#define MAXNODES 97

class CustomerHash
{

//    friend std::ostream& operator<<(std::ostream& output, const CustomerHash c);

    public:
        // ----------------------------CustomerHash-----------------------------
        // Description: this creates an unfilled CustomerHash
        // preconditions: *this is a totally un-initialized CustomerHash
        // postconditions: The fields of *this will be initialized, and the
        //                 CustomerHash will contain default values for its data
        // ---------------------------------------------------------------------
        CustomerHash();

        // ----------------------------~CustomerHash----------------------------
        // Description: destroys and decomposes CustomerHash memory, as-needed
        // preconditions: *this is in any valid state
        // postconditions: all dynamically allocated memory is freed, and the
        //                 CustomerHash is in a deletable state
        // ---------------------------------------------------------------------
        virtual ~CustomerHash();

        // -----------------------------getCustomer-----------------------------
        // Description: gets the Customer with the key
        // preconditions: *this has already been initialized
        // postconditions: nothing; just grants access to the Customer object
		// @return a pointer to THE Customer object in the CustomerHash table
        // ---------------------------------------------------------------------
        Customer* getCustomer(const int& key) const;

        // -----------------------------addCustomer-----------------------------
        // Description: adds a customer object into the CustomerHash table
        // preconditions: *this has already been initialized
        // postconditions: a pointer to THE Customer object will be stored
        // @param newCustomer is the new Customer
        // ---------------------------------------------------------------------
        void addCustomer(Customer* newCustomer);

        // --------------------------displayCustomers---------------------------
        // Description: builds up CustomerHash by reading from a data file.
        // preconditions: *this has already been initialized
        // postconditions: The file will have been read, and the CustomerHash
		//                 built in memory
        //@param input is the ifstream object of the file
        // ---------------------------------------------------------------------
        void loadCustomers(std::ifstream&);

        // --------------------------outputCustomers---------------------------
        // Description: uses ostream to output the Customers
        // preconditions: *this has already been initialized, & has valid state
        // postconditions: data of the CustomerHash will have been put to output
        // ---------------------------------------------------------------------
//        std::ostream& CustomerHash::outputCustomers(std::ostream& output) const;

        // --------------------------displayCustomers---------------------------
        // Description: uses couts to display the Customers
        // preconditions: *this has already been initialized, & has valid state
        // postconditions: data of the CustomerHash will have been put to cout
        // ---------------------------------------------------------------------
        void displayCustomers();

    protected:

    private:

		// -------------------------CustomerHashNode----------------------------
		// Description: These CustomerHashNodes are used to create linked-lists
		//              of CustomerHashNodes to act as the buckets in the
		//              CustomerHash table.
		//              We can therefore gracefully handle collisions.
        class CustomerHashNode
        {
        public:
            Customer* cust;     // Customer information in each node
            CustomerHashNode* next; // next in the list of Customers

            // -----------------------CustomerHashNode--------------------------
            // Description: constructor, so the heap can mange these
            // preconditions: *this is a totally un-initialized CustomerHashNode
            // postconditions: The fields of *this will be initialized, and
            //                 will contain:
            //                 * cust = nullptr
            //                 * next = nullptr
            // -----------------------------------------------------------------
            CustomerHashNode();

            // -----------------------~CustomerHashNode-------------------------
            // Description: destructor, so the heap can mange these
            // preconditions: *this is a CustomerHashNode of any valid state
            // postconditions: all dynamically allocated memory is freed, and
            //                 the CustomerHashNode is in a deletable state
            // -----------------------------------------------------------------
            ~CustomerHashNode();
        };

        CustomerHashNode* H[MAXNODES];      // array of CustomerHashNodes

        //HELPER FUNCTIONS: HELPER FUNCTIONS: HELPER FUNCTIONS: HELPER FUNCTIONS

        // ------------------------CustomerHashGenerator------------------------
        // Description: generate CustomerHash value to use as a storage address
        // preconditions: *this is initialized, & Customer* is valid
        // postconditions: nothing is changed
		// @param CustomerHashCust is the Customer or key to generate hash for
		// @return int of CustomerHash address to store at in the CustomerHash
		//             table array H
        // ---------------------------------------------------------------------
        int CustomerHashGenerator(const int& CustomerHashCust) const;
        int CustomerHashGenerator(const Customer* CustomerHashCust) const;
};

//std::ostream& operator<<(std::ostream& output, const CustomerHash& c)
//{
//    return output;
//}

#include "CustomerHash.cpp"

#endif // CUSTOMERHASH_H
