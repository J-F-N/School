//
// Created by jneigel1 on 8/16/19.
//

//#include "Comedy.h"

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
Comedy::Comedy() = default;

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
Comedy::Comedy(string t, int s, string dir, string tit, string year) {
    type = t;
    stock = s;
    director = dir;
    title = tit;
    releaseYear = year;
}

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
Comedy::~Comedy() = default;

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
bool Comedy::operator<(Product* movie) {

    auto comedy = (const Comedy*)movie;

    return (title < comedy->title ||
      (title == comedy->title && releaseYear < comedy->releaseYear)) ? true : false;
}

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
bool Comedy::operator==(Product* movie) {

    auto comedy = (const Comedy*)movie;

    return (title == comedy->title && releaseYear == comedy->releaseYear) ? true : false;
}

string Comedy::getType() {
    return type;
}

std::ostream& Comedy::display(std::ostream& stream) {
    stream << getType() << ", " << getStock() <<
    ", " << getDir() << ", " << getTitle() << ", "
     <<  getYear();

    return stream;
}

ostream &operator<<(ostream &stream, Comedy& p) {

    return p.display(stream);
}
