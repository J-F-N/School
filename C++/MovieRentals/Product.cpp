#include "Product.h"

using namespace std;
/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
Product::Product() = default;

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
Product::~Product() = default;

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
void Product::reduceStock() {
    cout << "stock was reduced" << endl;
    stock -= 1;
}

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
void Product::increaseStock(int amount) {

    this->stock += amount;
}

int Product::getStock() {

    return stock;
}

std::ostream& Product::display(std::ostream& output) {
    output << "This is some kind of product";
    return output;
}

std::ostream& operator<<(ostream &stream, Product& p) {
//    std::ostream* s = &stream;
    return p.display(stream);
//    stream << "This is some kind of product.";
//    return stream;
}
