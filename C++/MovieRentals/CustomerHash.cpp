// ------------------------- CustomerCustomerHash.cpp --------------------------
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

#include "CustomerHash.h"

// ----------------------------CustomerHash-----------------------------
// Description: this creates an unfilled CustomerHash
// preconditions: *this is a totally un-initialized CustomerHash
// postconditions: The fields of *this will be initialized, and the
//                 CustomerHash will contain default values for its data
// ---------------------------------------------------------------------
CustomerHash::CustomerHash()
{
    for(int i = 0; i < MAXNODES; ++i)
    {
        H[i] = nullptr;
    }
}

// ----------------------------~CustomerHash----------------------------
// Description: destroys and decomposes CustomerHash memory, as-needed
// preconditions: *this is in any valid state
// postconditions: all dynamically allocated memory is freed, and the
//                 CustomerHash is in a deletable state
// ---------------------------------------------------------------------
CustomerHash::~CustomerHash()
{
    for(int i = 0; i < MAXNODES; ++i)
    {
        delete H[i];
        H[i] = nullptr;
    }
}

// -----------------------------addCustomer-----------------------------
// Description: adds a customer object into the CustomerHash table
// preconditions: *this has already been initialized
// postconditions: a pointer to THE Customer object will be stored
// @param newCustomer is the new Customer
// ---------------------------------------------------------------------
void CustomerHash::addCustomer(Customer* newCustomer)
{
    //get hash and make newNode
    int custHash              = CustomerHashGenerator(newCustomer);
    CustomerHashNode* newNode = new CustomerHashNode();

    //put newNode in the hash table
    newNode->cust             = newCustomer; //link newCustomer
    newNode->next             = H[custHash]; //link next to old front
    H[custHash]               = newNode;     //put newNode at front
}

// -----------------------------getCustomer-----------------------------
// Description: gets the Customer with the key
// preconditions: *this has already been initialized
// postconditions: nothing; just grants access to the Customer object
// @return a pointer to THE Customer object in the CustomerHash table
//         a nullptr will be returned, if the customer is not found
// ---------------------------------------------------------------------
Customer* CustomerHash::getCustomer(const int& key) const
{
    CustomerHashNode* node = H[CustomerHashGenerator(key)];
    Customer* theCustomer = nullptr;

    while(node != nullptr && node->cust->getID() != key)
    {
        node = node->next;
    }

    if(node != nullptr)
    {
        theCustomer = node->cust;
    }

    //nullptr is returned when Customer not found
    return theCustomer;
}

// --------------------------loadCustomers---------------------------
// Description: builds up CustomerHash by reading from a data file.
// preconditions: *this has already been initialized
// postconditions: The file will have been read, and the CustomerHash
//                 built in memory
//@param input is the ifstream object of the file
// ---------------------------------------------------------------------
void CustomerHash::loadCustomers(std::ifstream& input)
{
    // psuedo-code:
    // builds the customers line by line.

    while(!input.eof())
    {
        string tmpStr;
        getline(input, tmpStr);
        stringstream inputProcessing(tmpStr);

        int custIDNum;
        string custFirstName;
        string custLastName;

        inputProcessing >> custIDNum >> custLastName >> custFirstName;
    }
}

// --------------------------outputCustomers---------------------------
// Description: uses ostream to output the Customers
// preconditions: *this has already been initialized, & has valid state
// postconditions: data of the CustomerHash will have been put to output
// ---------------------------------------------------------------------
//std::ostream& CustomerHash::outputCustomers(std::ostream& output) const
//{
//    for(int i = 0; i < MAXNODES; ++i)
//    {
//        CustomerHashNode* current = H[i];
//
//        while(current != nullptr)
//        {
//            output << *current->cust << endl;
//            current = current->next;
//        }
//    }
//
//    return output;
//}

// --------------------------displayCustomers---------------------------
// Description: uses couts to display the Customers
// preconditions: *this has already been initialized, & has valid state
// postconditions: data of the CustomerHash will have been put to cout
// ---------------------------------------------------------------------
void CustomerHash::displayCustomers()
{
    for(int i = 0; i < MAXNODES; ++i)
    {
        CustomerHashNode* current = H[i];

        while(current != nullptr)
        {
            cout << *current->cust << endl;
            current = current->next;
        }
    }
}


// -----------------------CustomerHashNode--------------------------
// Description: constructor, so the heap can mange these
// preconditions: *this is a totally un-initialized CustomerHashNode
// postconditions: The fields of *this will be initialized, and
//                 will contain:
//                 * cust = nullptr
//                 * next = nullptr
// -----------------------------------------------------------------
CustomerHash::CustomerHashNode::CustomerHashNode()
{
    cust = nullptr;
    next = nullptr;
}

// -----------------------~CustomerHashNode-------------------------
// Description: destructor, so the heap can mange these
// preconditions: *this is a CustomerHashNode of any valid state
// postconditions: all dynamically allocated memory is freed, and
//                 the CustomerHashNode is in a deletable state
// -----------------------------------------------------------------
CustomerHash::CustomerHashNode::~CustomerHashNode()
{
    delete cust;
    cust = nullptr;
    delete next;
    next = nullptr;
}

//HELPER FUNCTIONS: HELPER FUNCTIONS: HELPER FUNCTIONS: HELPER FUNCTIONS

// ------------------------CustomerHashGenerator------------------------
// Description: generate CustomerHash value to use as a storage address
// preconditions: *this is initialized, & Customer* is valid
// postconditions: nothing is changed
// @param CustomerHashCust is the Customer to generate has for
// @return int of CustomerHash address to store at in the CustomerHash
//             table array H
// ---------------------------------------------------------------------
int CustomerHash::CustomerHashGenerator(const int& CustomerHashCust) const
{
    return CustomerHashCust          % MAXNODES;
}

int CustomerHash::CustomerHashGenerator(const Customer* CustomerHashCust) const
{
    return CustomerHashCust->getID() % MAXNODES;
}
