//
// Created by veteran on 8/18/2019.
//

#ifndef PROGRAM4_PRODUCTDB_H
#define PROGRAM4_PRODUCTDB_H

#include "BinTree.h"
#include <string>

using std::string;

class ProductDB {

private:

    BinTree classics;
    BinTree dramas;
    BinTree comedies;

public:

    bool insertDB(Product* product);
    void displayProducts();
    BinTree& getClassics();
    BinTree& getComedies();
    BinTree& getDramas();
};

#include "ProductDB.cpp"

#endif //PROGRAM4_PRODUCTDB_H
