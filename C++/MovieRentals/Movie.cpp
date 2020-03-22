//
// Created by jneigel1 on 8/16/19.
//

#include "Movie.h"

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
Movie::Movie()
{
    mediaType = "D";
}

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
Movie::~Movie() {}

string Movie::getDir() const {
    return director;
}

string Movie::getTitle() const {
    return title;
}

string Movie::getType() {

    return this->type;
}

string Movie::getYear() const {
    return releaseYear;
}


int Movie::getStock() const {
    return stock;
}


std::ostream& Movie::display(std::ostream& output) {
    output << "This is some kind of movie";
    return output;
}

ostream &operator<<(ostream &stream, Movie& p) {

    return p.display(stream);
}
