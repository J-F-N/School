//
// Created by jneigel1 on 8/16/19.
//

#ifndef PROGRAM4_DRAMA_H
#define PROGRAM4_DRAMA_H

#include "Movie.h"
#include <string>

using std::string;

class Drama : public Movie {

    friend ostream &operator<<(ostream &stream, Drama& movie);

public:

    Drama();
    Drama(string type, int stock, string director, string title, string year);
    ~Drama() override;
    bool operator<(Product* movie) override;
    bool operator==(Product* movie) override;
    string getType() override;
    virtual std::ostream& display(std::ostream& output);
};

#include "drama.cpp"
#endif //PROGRAM4_DRAMA_H
