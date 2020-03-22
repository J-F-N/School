

#ifndef PROGRAM4_PRODUCT_H
#define PROGRAM4_PRODUCT_H

#include <string>
#include <ostream>

using std::ostream;
using std::string;

class Product
{

    friend ostream &operator<<(ostream &stream, Product& p);

private:

protected:

    int stock;      //current amount in stock

public:

    Product();


    virtual ~Product();

    void reduceStock();                                     //reduces the current stock by 1
    void increaseStock(int amount);                         //increases the current stock by the param amount
    virtual bool  operator<(Product* product) = 0;    //compares the param to the calling object
    virtual bool operator==(Product* product) = 0;    //compares the param to the calling object
    int getStock();                                         //returns an int for the stock of the calling Product
    virtual string getType() = 0;
    virtual std::ostream& display(std::ostream& output);
};

#include "Product.cpp"

#endif //PROGRAM4_PRODUCT_H
