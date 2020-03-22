//
// Created by veteran on 8/18/2019.
//

#include "ProductDB.h"

bool ProductDB::insertDB(Product* product) {

    char letter = product->getType()[0];

    switch (letter) {

        case 'C':
            classics.insert(product);

            break;

        case 'F':
//        cout << "Fix Comedy Insert" << endl;
            comedies.insert(product);

            break;

        default:
//        cout << "Fix Drama Insert" << endl;
            dramas.insert(product);

            break;
    }
}

void ProductDB::displayProducts() {

    //each BinTree gets to display its own contents
    comedies.display();
    dramas.display();
    classics.display();

}

BinTree& ProductDB::getClassics()
{
    cout << "got the classic tree" << endl;
    return this->classics;
}

BinTree& ProductDB::getComedies()
{

    return this->comedies;
}

BinTree& ProductDB::getDramas()
{

    return this->dramas;
}
