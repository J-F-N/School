/*Author: John Neigel
---------------------------
Last Edit: 08/16/2019
---------------------------
Description: Class interface for the Movie class. Movie is a generalization
 of the specific derived classes such as Classic, Comedy, and Drama. It uses
 inheritance to pass shared data members to the derived classes.
---------------------------
*/

#ifndef PROGRAM4_MOVIE_H
#define PROGRAM4_MOVIE_H

#include <string>
#include "Product.h"

using std::string;

class Movie : public Product {

protected:

    string type;            //represents the type of movie
    string director;        //director of the movie
    string title;           //title of the movie
    string releaseYear;     //year the movie was released
    string mediaType;

    virtual ~Movie();

public:

    Movie();
    virtual bool  operator<(Product* movie) = 0;    //compares the param to the calling object
    virtual bool operator==(Product* movie) = 0;    //compares the param to the calling object
    string getType() override;
    string getDir() const;
    string getTitle() const;
    string getYear() const;
    int getStock() const;
    virtual std::ostream& display(std::ostream& output);
};

#include "Movie.cpp"

#endif //PROGRAM4_MOVIE_H
