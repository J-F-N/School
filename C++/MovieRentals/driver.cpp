//
//  driver.cpp
//
//
//  Created by Geoffrey Powell-Isom on 8/16/19.
//

#include <iostream>
#include <fstream>
#include <iostream>
#include "ProductDB.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
#include "Business.h"
#include "customer.h"
#include "CustomerHash.h"
#include "Transaction.h"


int main()
{
    cout << "Welcome to the Movie Management Machine!" << endl;

    cout << "Testing the Movie Management Machine" << endl;

    //Start a business
    Business MMMachine;

    //FILES: (Open + Run + Close) * 3
    ifstream data4customers("data4customers.txt");
    MMMachine.loadCustomers(data4customers);
    data4customers.close();
    ifstream data4movies("data4movies.txt");
    MMMachine.loadMovies(data4movies);
    data4movies.close();
    ifstream data4commands("data4commands.txt");
    MMMachine.loadCommands(data4commands);
    data4commands.close();

    //Display the business
    MMMachine.displayBusiness();

    return 0; // :-)
}
