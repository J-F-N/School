// -------------------------- CustomerCustomerHash.h ---------------------------
// Program Name: Program 4 : Finite State Machine

// Student: Geoffrey Powell-Isom

// Course: CSS 343 Data Structure and Algorithms 2
// Section Number: A

// Creation Date: 08/05/2019, Monday

// Date of Last Modification: 08/06/2019, Tuesday

// Description: 
// This creates, stores, and manages the CustomerHash table for the Finite State
// Machine's Customers.


#ifndef CUSTOMERHASH_H
#define CUSTOMERHASH_H

#include <iostream>
#include <fstream>

#include "Customer.h"

#define MAXNODES 97

class CustomerHash
{
    public:
        // Description: this creates an unfilled CustomerHash
        // preconditions: *this is a totally un-initialized CustomerHash
        // postconditions: The fields of *this will be initialized, and the
        //                 CustomerHash will contain default values for its data
        CustomerHash();

        // Description: destroys and decomposes CustomerHash memory, as-needed
        // preconditions: *this is in any valid state
        // postconditions: all dynamically allocated memory is freed, and the
        //                 CustomerHash is in a deletable state
        virtual ~CustomerHash();

        // Description: gets the Customer with the key
        // preconditions: *this has already been initialized
        // postconditions: nothing; just grants access to the Customer object
		// @return a pointer to THE Customer object in the CustomerHash table
        Customer* getCustomer(int key);

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
		// psuedo-code:
		// builds the customers line by line.

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
        struct CustomerHashNode
        {
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

        CustomerHashNode H[MAXNODES];      // array of CustomerHashNodes

        //HELPER FUNCTIONS: HELPER FUNCTIONS: HELPER FUNCTIONS: HELPER FUNCTIONS

        // ------------------------CustomerHashGenerator------------------------
        // Description: generate CustomerHash value to use as a storage address
        // preconditions: *this is initialized, & Customer* is valid
        // postconditions: nothing is changed
		// @param CustomerHashCust is the Customer to generate has for
		// @return int of CustomerHash address to store at in the CustomerHash
		//             table array H
        // ---------------------------------------------------------------------
        int CustomerHashGenerator(const Customer* CustomerHashCust) const;
};

#include "CustomerHash.cpp"

#endif // CUSTOMERHASH_H