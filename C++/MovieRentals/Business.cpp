// ------------------------------- Business.cpp --------------------------------
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



#include "Business.h"
#include <string>
#include <iostream>
#include <queue>

// ------------------------------Business-------------------------------
// Description: this creates a new Business
// preconditions: *this is a totally un-initialized Business
// postconditions: The fields of *this will be initialized, and the
//                 Business will contain default values for its data
// ---------------------------------------------------------------------
Business::Business()
{
    //nothing to do here; Everything is on the local object stack.
}

// ------------------------------~Business------------------------------
// Description: destroys and decomposes Business memory, as-needed
// preconditions: *this is in any valid state
// postconditions: all dynamically allocated memory is freed, and the
//                 Business is in a deletable state
// ---------------------------------------------------------------------
Business::~Business()
{
    //nothing to do here; Everything is on the local object stack.
}

// ---------------------------loadCustomers-----------------------------
// Description: loads Customer into CustomerHash table
// preconditions: *this has already been initialized, and is valid
// postconditions: The file will have been read, &
//                 The customers will be in the CustomerHash table
//@param custFile is the ifstream object of the file
// ---------------------------------------------------------------------
void Business::loadCustomers(std::ifstream& custFile)
{
    // psuedo-code:
    // checks the file is open
    // loads customers by calling customerHash's loadCustomers.
    if(custFile.fail() || custFile.bad() || !custFile.is_open() || !custFile.good())
    {
        cout << "\aFile: Failed to open Customer input file!" << endl;
        return;
    }

    string inputString;
    while(!custFile.eof())
    {
        getline(custFile, inputString);
        if(inputString.size() == 0)
        {
            continue; //nothing in this line
        }
        custTable.addCustomer(new Customer(inputString));
    }
}

// -----------------------------loadMovies------------------------------
// Description: loads the movies from movieFile into the Movie database
// preconditions: *this has already been initialized, and is valid
// postconditions: The file will have been read, &
//                 The Movies will be in the database
//@param movieFile is the ifstream object of the file
// ---------------------------------------------------------------------
void Business::loadMovies(std::ifstream& movieFile)
{
    //psuedo-code:
    //
    // checks that the file is open.
    // loads movies by reading lines and calling AVLTree's insertNode function for each line
    //

    cout << "Loading Movies File...." << endl;

    if(movieFile.fail() || movieFile.bad() || !movieFile.is_open() || !movieFile.good())
    {
        cout << "\aFile: Failed to open Movie input file!" << endl;
        return;
    }
    string inputString = "";

        cout << endl ; //Yes, we really need this here.

    while(!movieFile.eof())
    {
//        cout << "" << endl; //Needed to nudge the later cout to actually work.
        getline(movieFile, inputString);


        loadMoviesHelper(inputString);
    }
}


void Business::loadMoviesHelper(string inputString)
{

        if(inputString.size() == 0)
        {
            return;
        }

        string tempStr = "";
        stringstream inputStringProcessor(inputString);
//        cout << inputString;
        getline(inputStringProcessor, tempStr, ',');

//        std::cout << endl << inputString;
//        cout << endl;
//        std::cout << endl << tempStr;

//        getline(inputStringProcessor, inputString, ',');
        char inChar = tempStr[0];
        switch(inChar) {
            case 'C':
            {

                string t(1, inChar);
//                cout << t;

                getline(inputStringProcessor, tempStr, ',');
                int s = stoi(tempStr);

                string dir = "";
                getline(inputStringProcessor, dir, ',');
                dir.erase(0,1);
//                cout << dir;

                string title = "";
                getline(inputStringProcessor, title, ',');
                title.erase(0,1);


                getline(inputStringProcessor, tempStr);

                string actor = tempStr;
                string month = tempStr;
                actor.erase(0,1);
                month.erase(month.size() - 5, 6);
                char sentry = actor[actor.size() - 7];
                if(sentry >= '0'  && sentry <= '9')
                {
                    actor.erase(actor.size() - 8, 8);
                    month.erase(0, month.size() - 3);
                }
                else
                {
                    actor.erase(actor.size() - 7, 7);
                    month.erase(0, month.size() - 2);
                }


                if(actor[actor.size()-1] == ' ')
                {
                    actor.erase(actor.size()-1, 1);
                }

                string year = tempStr;
                year.erase(0,year.size() - 5);

                int m = stoi(month);
                month = to_string(m);
                
                while(actor[0] < '!' || actor[0] > '~')
                {
                    actor.erase(0, 1);
                }
                
                while(actor[actor.size() -1] < '!' || actor[actor.size() -1] > '~')
                {
                    actor.erase(actor.size() -1, 1);
                }
                
                stringstream astream(actor);
                
                string afirst, alast;
                astream >> afirst >> alast;
                actor = afirst + " " + alast;
                    


                Classic* newClassic = new Classic(t, s, dir, title, year, month, actor);
//                cout << *newClassic;
//                cout << newClassic->getMonth() << "." << newClassic->getYear() << endl;
                this->productDB.insertDB(newClassic);
//                delete newClassic;
            }
                break;

            case 'D':
            {

                string t(1, inChar);
//                cout << t;

                getline(inputStringProcessor, tempStr, ',');
                int s = stoi(tempStr);

                string dir = "";
                getline(inputStringProcessor, dir, ',');
                dir.erase(0,1);
//                cout << dir;

                string title = "";
                getline(inputStringProcessor, title, ',');
                title.erase(0,1);

                string year = "";
                getline(inputStringProcessor, year);
                year.erase(0,1);


                Drama* newDrama = new Drama(t,  s, dir, title, year);
//                cout << *newDrama;
                this->productDB.insertDB(newDrama);
//                delete newDrama;
            }
                break;

            case 'F':
            {

                string t(1, inChar);
//                cout << t;

                getline(inputStringProcessor, tempStr, ',');
                int s = stoi(tempStr);

                string dir = "";
                getline(inputStringProcessor, dir, ',');
                dir.erase(0,1);
//                cout << dir;

                string title = "";
                getline(inputStringProcessor, title, ',');
                title.erase(0,1);

                string year = "";
                getline(inputStringProcessor, year);
                year.erase(0,1);


                Comedy* newComedy = new Comedy(t,  s, dir, title, year);
//                cout << *newComedy;
                this->productDB.insertDB(newComedy);
//                delete newComedy;
            }
                break;

            default:
                cout << inChar << " is not a valid Product type indicator key!" << endl;
                break;
        }
}

void Business::loadCommandsHelper(string inputString)
{

    if(inputString.size() == 0)
    {
        return;
    }

    char commandLetter = inputString[0];
    inputString.erase(0, 2);

    std::stringstream sstream(inputString);

    switch (commandLetter)
    {
        case 'B': {
            //temp variables for initialization
            char movType = 0;
            string title = "";
            int custNum = 0;
            char medType = '\0';
            string year = "";

            sstream >> custNum >> medType >> movType;

            //classic line format is different
            switch(movType)
            {
                case 'C': {
//                    cout << "Customer " << custNum
//                         << " wants to borrow a Classic Movie. :-)" << endl;
                    string month = "";
                    string actor = "";

                    sstream >> month >> year;
                    getline(sstream, actor);

                    
                    
                    stringstream astream(actor);
                    
                    string afirst, alast;
                    astream >> afirst >> alast;
                    actor = afirst + " " + alast;
                    
//                    cout << "\twith month of " << month << ", year of " << year << ", and actor of " << actor << endl;
                    Customer* cust = custTable.getCustomer(custNum);
                    if (cust) {
//                        cout << "Looking for product...." << endl;
                        Product *classic = new Classic(to_string(movType), 0,
                                                       "", title,
                                                       year,
                                                       month, actor);
//                        cout << *classic << endl;
                        if (productDB.getClassics().retrieve(classic)) {
//                            cout << "WAS found." << endl;
                            Transaction *trans = new Borrow(classic);
                            custTable.getCustomer(custNum)->storeTransaction(
                                    trans);
                        }
                        else {
                            cout << "ERROR: The Movie with " << actor << " from " << year << " is NOT AVAILABLE!" << endl;
                        }

                        delete classic;
                    }
                    else {
                        cout << "ERROR: Customer number " << custNum << " does NOT EXIST!" << endl;
                    }
                }
                    break;

                case 'F':
                {
                    cout << "Customer " << custNum
                         << " wants to borrow a Funny Movie. :-)" << endl;
                }
                    break;

                case 'D':
                {
                    cout << "Customer " << custNum
                         << " wants to borrow a Dramatic Movie. :-)" << endl;
                }
                    break;

                default:
                {
                    cout << "ERROR: " << movType << " is NOT a VALID Movie type!" << endl;
                }
            }
        }
        break;

        case 'R':
        {
            //temp variables for initialization
            char movType = 0;
            string title = "";
            int custNum = 0;
            char medType = '\0';
            string year = "";

            sstream >> custNum >> medType >> movType;

            //classic line format is different
            switch(movType)
            {
                case 'C': {
//                    cout << "Customer " << custNum
//                         << " wants to RETURN a Classic Movie. :-)" << endl;
                    string month = "";
                    string actor = "";

                    sstream >> month >> year;
                    getline(sstream, actor);
                    
                    


//                    cout << "\twith month of " << month << ", year of " << year << ", and actor of " << actor << "." << endl;
                    if (!custTable.getCustomer(custNum)) {

                        Product *classic = new Classic(to_string(movType), 0,
                                                       "", title,
                                                       year,
                                                       month, actor);

                        if (productDB.getClassics().retrieve(classic)) {
                            Transaction *trans = new Borrow(classic);
                            custTable.getCustomer(custNum)->storeTransaction(
                                    trans);
                        }
                        else {
                            cout << "Could not RETURN movie: " << title << endl;
                        }

                        delete classic;
                    }
                }
                    break;

                case 'F':
                {
//                    cout << "Customer " << custNum
//                         << " wants to RETURN a Funny Movie. :-)" << endl;
                }
                    break;

                case 'D':
                {
//                    cout << "Customer " << custNum
//                         << " wants to RETURN a Dramatic Movie. :-)" << endl;
                }
                    break;

                default:
                {
                    cout << "ERROR: " << movType << " is NOT a VALID Movie type!" << endl;
                }
            }
        }
            break;

        case 'I':

            productDB.displayProducts();
            break;

        case 'H': {
            int custNum = 0;
            sstream >> custNum;
            custTable.getCustomer(custNum)->printHistory();
        }
            break;

        default:
            cout << "ERROR: " << commandLetter << " is NOT a VALID command!" << endl;
            break;
    }
}

// ----------------------------loadCommands-----------------------------
// Description: loads the commmands from comFile into a Queue
// preconditions: *this has already been initialized
// postconditions: The file will have been read, and the commands stored
//                 in the comQueue
//@param comFile is the ifstream object of the file
// ---------------------------------------------------------------------
void Business::loadCommands(std::ifstream& comFile)
{
    // psuedo-code:
    //
    // check the file is open.
    // read line by line.
    //
    // if (the line's first character is 'I') call AVLTree's PrintInventory;
    // if (the line's first character is  'B' or 'R'){
    //        if (Check that get customer doesn't return a nullptr) print an error message;
    //        else{
    //            Call ChangeStock to increase or decrease the stock.
    //            if (changeStock doens't return NULL) Add the transaction to the customer's vector of transactions.
    //        }
    // }
    // if (the line's first character is 'H'){
    //        check that the customer exists
    //        print the customer's transactoins
    // }

    if(comFile.fail() || comFile.bad() || !comFile.is_open() || !comFile.good())
    {
        cout << "\aFile: Failed to open Command input file!" << endl;
        return;
    }

    string inputString = "";

    while(!comFile.eof())
    {
        getline(comFile, inputString);

        //stringstream sstream(inputString);

        loadCommandsHelper(inputString);
    }
}

// --------------------------displayBusiness----------------------------
// Description: uses couts to output business information
// preconditions: *this has already been initialized, and is valid
// postconditions: data from the Business will have been put to cout
// ---------------------------------------------------------------------
void Business::displayBusiness()
{
    // Displays the inventory by calling AVLTree's displayInventory.
    // Displays customers and their transactions.
    //cout << "----------CUSTOMER DATABASE:----------" << endl;
    //custTable.displayCustomers();
    //productDB.displayProducts();
}
