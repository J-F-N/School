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

void testCustomer();
void testCustomerHash();
void testBusiness();
void testTransaction();
void testMovies();
void loadMovies();

int main()
{
    cout << "Welcome to the Movie Management Machine!" << endl;

    testCustomer();
    testCustomerHash();
    testBusiness();
    testTransaction();
    testMovies();

    cout << "This is the second-to-last line of main(). Please don't move it." << endl;
    return 0; // :-)
}


void loadMovies()
{
//    Business movieCo;
//    movieCo
}

void testMovies() {

    ProductDB dB1;
    Product* PPtr;

    Classic* C1 = new Classic("C", 10 ,"Geoff the Man", "Best Movie Ever", "2077", "12", "John Neigel");

    Classic* C2 = new Classic("C", 10 ,"Alexis Neigel", "My Love", "2075", "10", "No One Else");

    Classic* C3 = new Classic("C", 10 ,"James Neigel", "Brother", "1999", "9", "John Neigel");

    Classic* C4 = new Classic("C", 10 ,"Martha Neigel", "Good Cooking", "1988", "5", "My Family");

    Classic* C5 = new Classic("C", 10 ,"Frank Neigel", "Gentle", "2075", "9", "Proud Son");
    Comedy* C6 = new Comedy("F", 10 ,"Frank Neigel", "Bloop Errs",        "2077");
    Drama*  D5 = new Drama("D", 10 ,"Frank Neigel", "Story of A Man, A", "2075");

    PPtr = C1;
    dB1.insertDB(PPtr);
    PPtr = C2;
    dB1.insertDB(PPtr);
    PPtr = C3;
    dB1.insertDB(PPtr);
    PPtr = C4;
    dB1.insertDB(PPtr);
    PPtr = C5;
    dB1.insertDB(PPtr);
    PPtr = C6;
    dB1.insertDB(PPtr);
    PPtr = D5;
    dB1.insertDB(PPtr);

    cout << "The Classic under C1 is: " << *C1 << endl;
    cout << "The Comedy under C6 is: " << *C6 << endl;
    cout << "The Drama under D5 is: " << *D5 << endl;
    dB1.displayProducts();
}

void testTransaction()
{
    cout << "Testing the Transactions class" << endl;
    cout << "creating non-specific Transaction" << endl;
//    Borrow doThing(new FunnyMovie('F', 500, "Sir John",
//		"Neigel", "Great Adventure of, The: Sir John Neigel", 2100));
    Comedy* testComedy1 = new Comedy();
    Classic* testClassic1 = new Classic();
    Drama* testDram1 = new Drama();
    Borrow doThing1(testComedy1);
    Borrow doThing9(testClassic1);
    Borrow doThing8(testDram1);

    Comedy* testComedy2 = new Comedy();
    Return doThing2(testComedy2);

    Comedy* testComedy3 = new Comedy();
    Borrow doThing3(testComedy3);

    History doThing4;
    Inventory doThing6;

    cout << "The Borrow command's actionType is '" << doThing1.getActionType() << "'." << endl;
    cout << "The Return command's actionType is '" << doThing2.getActionType() << "'." << endl;
    cout << "The History command's actionType is '" << doThing4.getActionType() << "'." << endl;
    cout << "The Inventory command's actionType is '" << doThing6.getActionType() << "'." << endl;

    cout << "This is the last line of the testTransaction() function." << endl;
}

void testBusiness()
{
    cout << "Testing the Business class" << endl;

    //Start a business
    Business blockBuster;

    //FILES: (Open + Run + Close) * 3
    ifstream data4customers("data4customers.txt");
    blockBuster.loadCustomers(data4customers);
    data4customers.close();
    ifstream data4movies("data4movies.txt");
    blockBuster.loadMovies(data4movies);
    data4movies.close();
    ifstream data4commands("data4commands.txt");
    blockBuster.loadCommands(data4commands);
    data4commands.close();

    //Display the business
    blockBuster.displayBusiness();
}

void testCustomerHash()
{
    cout << "Testing the CustomerHash class" << endl;
    cout << "Making a new CustomerHash" << endl;

    CustomerHash hash1;
    hash1.addCustomer(new Customer("0121 McDonald Ronald"));
    hash1.addCustomer(new Customer("9999 Doe John"));
    hash1.addCustomer(new Customer("0113 Smith Adam"));
    hash1.addCustomer(new Customer("0105 Ann Joe"));
    hash1.addCustomer(new Customer("1234 Doe John"));
    hash1.addCustomer(new Customer("5678 Doe Jane"));
    cout << "hash1 contains: " << endl;
//    cout << hash1 << endl;
    hash1.displayCustomers();
    cout << "getting record for customer 1234" << endl;
    Customer* customerJohnDoe = hash1.getCustomer(1234);
    cout << "got " << *customerJohnDoe << endl;
}

void testCustomer()
{
    cout << "Testing the Customer class..." << endl;
    cout << "Making a new Customer" << endl;

    Customer customer1;

    cout << "Making a new Customer based on: 1234 Doe John" << endl;

    Customer customerJohnDoe("1234 Doe John");

    cout << "customer1's customer ID is: " << customer1.getID() << endl;
    cout << "John Doe's customer ID is:  " << customerJohnDoe.getID() << endl;
    cout << "customer1's firstName is:   " << customer1.getFirstName() << endl;
    cout << "John Doe's firstName is:    " << customerJohnDoe.getFirstName() << endl;
    cout << "customer1's lastName is:    " << customer1.getLastName() << endl;
    cout << "John Doe's lastName is:     " << customerJohnDoe.getLastName() << endl;
    cout << "customer1's history is:" << endl;
    customer1.printHistory();
    cout << endl;
    cout << "John Doe's history is:" << endl;
    customerJohnDoe.printHistory();
    cout << endl;
}
