//
// Created by jneigel1 on 8/16/19.
//

#ifndef PROGRAM4_CLASSIC_H
#define PROGRAM4_CLASSIC_H

#include "Movie.h"
#include <string>

using std::string;

class Classic: public Movie {

protected:

    string majorActor;
    string releaseMonth;

public:

    Classic();
    Classic(string type, int stock, string director, string title, string year, string month, string actor);
    ~Classic() override;
    bool operator<(Product* movie) override;
    bool operator==(Product* movie) override;
    //string getType() override;
    string getActor();
    string getMonth();
    virtual std::ostream& display(std::ostream& output);
    friend ostream &operator<<(ostream &stream, Classic& movie);
};

#include "Classic.cpp"

#endif //PROGRAM4_CLASSIC_H
