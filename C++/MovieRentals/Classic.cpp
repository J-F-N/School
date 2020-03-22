//
// Created by jneigel1 on 8/16/19.
//

#include "Classic.h"
#include <ostream>

using std::endl;

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
Classic::Classic(){};

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
Classic::Classic(string t, int s, string dir, string tit, string year, string month, string actor) {

    type = t;
    stock = s;
    director = dir;
    title = tit;
    releaseYear = year;
    releaseMonth = month;
    majorActor = actor;
}

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
Classic::~Classic() = default;

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
bool Classic::operator<(Product* movie) {

    const Classic* classic = (const Classic*)movie; //cast to allow comparison of data fields.

    //compares on year, then if equal on month, then if equal on major actor.
    return (releaseYear < classic->releaseYear ||
           (releaseYear == classic->releaseYear && releaseMonth < classic->releaseMonth) ||
           (releaseYear == classic->releaseYear && releaseMonth == classic->releaseMonth &&
            majorActor < classic->majorActor));
}

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
bool Classic::operator==(Product* movie) {
//    cout << endl << "Running Classic equality" << endl;
    if(this == movie)
    {
        return true;
    }
    
//    Classic* classic = (const Classic*)movie;
    
    Classic *classic = static_cast<Classic*>(movie);

//    cout << " comparing on " << *classic << endl << " AND " << endl;
//    cout << endl << "              " << *this << endl;
    bool samenessness = stoi(releaseYear) == stoi(classic->releaseYear) &&
    stoi(releaseMonth) == stoi(classic->releaseMonth) &&
            majorActor == classic->majorActor;
//    if(samenessness) cout << endl << "THEY'RE EQUALL!!!!!!!" << endl;
    return samenessness;
}

string Classic::getActor() {
    return majorActor;
}

string Classic::getMonth() {
    return releaseMonth;
}

std::ostream& Classic::display(std::ostream& stream) {

    stream << getType() << ", " << getStock() <<
    ", " << getDir() << ", " << getTitle() << ", "
     << getActor() << " " << getMonth() << " " << getYear(); /*<< getMonth()
     << " " << getYear()*/;

    return stream;
}

ostream &operator<<(ostream &stream, Classic& p) {

    return p.display(stream);
}

/*ostream &operator<<(ostream &stream, Product *&product) {

    cout << "Entered operator<<" << endl;

    auto movie = (Classic*) product;

    stream << movie->getType() << ", " << movie->getStock() <<
    ", " << movie->getDir() << ", " << movie->getTitle() << ", "
     << movie->majorActor << " " << movie->releaseMonth << " " <<
     movie->releaseYear << endl;

    return stream;
}*/

