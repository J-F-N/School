//
// Created by jneigel1 on 8/16/19.
//

#ifndef PROGRAM4_COMEDY_H
#define PROGRAM4_COMEDY_H

#include <string>
#include "Movie.h"

using std::string;

class Comedy: public Movie {

    friend ostream &operator<<(ostream &stream, Classic& movie);

public:

    Comedy();
    Comedy(string type, int stock, string director, string title, string year);
    ~Comedy() override;
    bool operator<(Product* movie) override;
    bool operator==(Product* movie) override;
    string getType() override;
    virtual std::ostream& display(std::ostream& output);
};

#include "Comedy.cpp"

#endif //PROGRAM4_COMEDY_H
