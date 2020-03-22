//
// Created by jneigel1 on 8/16/19.
//

#include "Drama.h"

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
Drama::Drama() = default;

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
Drama::Drama(string t, int s, string dir, string tit, string year) {

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
Drama::~Drama() = default;

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
bool Drama::operator<(Product* movie) {

    auto drama = (const Drama*) movie;

    return (director < drama->director || (director == drama->director && title < drama->title)) ? true : false;
}

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
bool Drama::operator==(Product* movie) {

    auto drama = (const Drama*) movie;

    return (director == drama->director && title == drama->title) ? true : false;
}

string Drama::getType() {
    return type;
}

std::ostream& Drama::display(std::ostream& stream) {
    stream << getType() << ", " << getStock() <<
    ", " << getDir() << ", " << getTitle() << ", "
     <<  getYear();

    return stream;
}

ostream &operator<<(ostream &stream, Drama& p) {

    return p.display(stream);
}
