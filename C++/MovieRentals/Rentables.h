#ifndef RENTABLES_H
#define RENTABLES_H

// Description:
// This header file contains the descriptions for all rentable items.
// There is a generic Rentable class that represents any rentable item.
// Then abstract Movie inherits Rentable. There are three genres of the movies.
// Each genre is represented by a subclass of movie (Comedy, Classic, Drama).


#include <string>
#include <iostream>

using namespace std;

// This abstract class represents rentable objects. It is included in the design, 
// but it is better if it is deleted from the implementation.
class Rentable {


	// Description: overloaded the << output operator. Prints the rentable.
	// Pre: an output stream is constructed and open.
	// Post: The rentable is printed to os.
	friend ostream & operator<<(ostream & os, const Rentable & r)
	{
		this->print(os);
	}
	
public:

	// Description: this is the defualt constructor.
	// preconditions: None.
	// postconditions: a rentable is constructed with type.
	Rentable(char type) {
		this->type = type;
	}
	

	// Description: this destroys a rentable.
	// preconditions: None
	// postconditions: This rentable is destructed.
	virtual ~Rentable();

	// Description: this is the equality operator
	// This is a pure virtual funtion.
	// preconditions: r is already initialized.
	// postconditions: returns True if the rentables are equal.
	virtual bool operator==(const Rentable & r) const = 0;

	// Description: this is the inequality operator
	// preconditions: r is already initialized
	// postconditions: True if the rentables are not equal.
	virtual bool operator!=(const Rentable & r) const
	{
		return !(*this == r);
	}

	// Description: this is the less-than operator
	// This is a pure virtual funtion.
	// preconditions: r is already initialized
	// postconditions: True if this rentable has a smaller
	// value than r.
	virtual bool operator<(const Rentable & f) const = 0;

	// Description: this is the greater-than operator
	// preconditions: r is already initialized
	// postconditions: True if this rentable has a larger
	// value than r.
	virtual bool operator>(const Rentable & f) const
	{
		return !(*this == f || *this < f);
	}

	// Description: this is the less-than or equal operator
	// preconditions: r is already initialized
	// postconditions: True if this rentable has a value that is smaller than or
	// equal to r.
	virtual bool operator<=(const Rentable & r) const
	{
		return (*this == r || *this < r);
	}

	// Description: this is the greater-than operator
	// preconditions: r is already initialized
	// postconditions: True if the this rentable has a value larger than or
	// equal to r.
	virtual bool operator>=(const Rentable & r) const
	{
		return !(this < r);
	}

	// Description: This function is a helper for the <<  operator.
	// it prints this object to os.
	// This is a pure virtual function.
	// preconditions: os is open, valid and usable.
	// postconditions: this object is printed to os.
	virtual void print(ostream & os) const = 0;

	// Getters
	virtual char getType() const
	{
		return type;
	}

	
protected:

	// The type of the rentable
	char type;

}; // Rentable

// This abstract class represents a Movie.
class Movie : public Rentable{
	
public:

	// Description: this constructor makes a movie with
	// the passed parameter values.
	// preconditions: the parameters are valid. if the parameters are not
	// valid, an exception will be thrown.
	// postconditions: a movie is constructed.
	Movie(char type, int stock, string directorFirstName,
		  string directorLastName, string title, int year): Rentable(type) {

		
		this->setStock(stock);

		this->directorFirstName = directorFirstName;
		this->directorLastName = directorLastName;

		this->title = title;

		if (year < 1500 /* or year > current date using ctime*/) throw invalid_argument("year out of range");
		this->year = year;

	}

	// Description: this destroys a movie.
	// preconditions: None
	// postconditions: This movie is destructed.
	virtual ~Movie();


	// Getters
	int getStock() const
	{
		return stock;
	}

	string getDirectorFirstName() const
	{
		return directorFirstName;
	}

	string getDirectorLastName() const
	{
		return directorLastName;
	}

	string getTitle() const
	{
		return title;
	}

	int getYear() const
	{
		return year;
	}


	// Setters

	// Preconditions: assumes stock is greater than 0.
	virtual setStock(int stock) {
		if (stock < 1) throw invalid_argument("there has to be stock");
		this->stock = stock;
	}


protected:

	// The number of available copies of the movie
	int stock;

	// First name and last name of the director
	string directorFirstName;
	string directorLastName;

	// Title of the movie
	string title;

	// Release year of the movie
	int year;

}; // Movie


class ClassicMovie : public Movie {

public:

	// Description: this constructur instantiates the object
	// with the passed parameters.
	// preconditions: all the parameters are valid.
	// Will throw an exception if the parameters are not valid.
	// postconditions: this is constructed.
	ClassicMovie(char type, int stock, string directorFirstName,
		string directorLastName, string title, string actorFirstName,
		string actorLastName, int month, int year) :
		Movie(type, stock, directorFirstName, directorLastName, title, year)
	{
		
		this->actorFirstName = actorFirstName;
		this->actorLastName = actorLastName;

		if (month < 1 || month > 12) throw invalid_argument("month is out of range");

	}

	// Description: defualt destructor.
	// preconditions: None
	// postconditions: This movie is destructed.
	virtual ~ClassicMovie() {}

	// Description: this is the equality operator
	// preconditions: m is already initialized and represents a ClassicMovie.
	// postconditions: returns True if the movies are the same.
	virtual bool operator==(const Rentable & m) const;

	// Description: this is the less-than operator
	// preconditions: m is already initialized and represents a ClassicMovie.
	// postconditions: True if this movie has a smaller
	// value than m.
	virtual bool operator<(const Rentable & m) const;

	// Description: This function is a helper for the <<  operator.
	// it prints this object to os.
	// preconditions: os is open, valid and usable.
	// postconditions: this object is printed to os.
	virtual void print(ostream & os) const;

	//getters
	string getActorFirstName() const
	{
		return actorFirstName;
	}

	string getActorLastName() const
	{
		return actorLastName;
	}

	int getMonth() const
	{
		return month;
	}

protected:

	// Actor first and last name
	string actorFirstName;
	string actorLastName;

	// Release Month
	int month;
}; // end of ClassicMovie

class FunnyMovie : public Movie {

public:

	// Description: this constructur instantiates the object
	// with the passed parameters.
	// preconditions: all the parameters are valid.
	// Will throw an exception if the parameters are not valid.
	// postconditions: this is constructed.
	FunnyMovie(char type, int stock, string directorFirstName,
		string directorLastName, string title, int year) :
		Movie(type, stock, directorFirstName, directorLastName, title, year) {}

	// Description: defualt destructor.
	// preconditions: None
	// postconditions: This movie is destructed.
	virtual ~FunnyMovie() {}

	// Description: this is the equality operator
	// preconditions: m is already initialized and represents a FunnyMovie
	// postconditions: returns True if the movies are the same.
	virtual bool operator==(const Rentable & m) const;

	// Description: this is the less-than operator
	// preconditions: m is already initialized and represents a FunnyMovie
	// postconditions: True if this movie has a smaller
	// value than m.
	virtual bool operator<(const Rentable & m) const;

	// Description: This function is a helper for the <<  operator.
	// it prints this object to os.
	// preconditions: os is open, valid and usable.
	// postconditions: this object is printed to os.
	virtual void print(ostream & os) const;

}; // end of FunnyMovie

class DramaMovie : public Movie {

public:

	// Description: this constructur instantiates the object
	// with the passed parameters.
	// preconditions: all the parameters are valid.
	// Will throw an exception if the parameters are not valid.
	// postconditions: this is constructed.
	DramaMovie(char type, int stock, string directorFirstName,
		string directorLastName, string title, int year) :
		Movie(type, stock, directorFirstName, directorLastName, title, year) {}

	// Description: defualt destructor.
	// preconditions: None
	// postconditions: This movie is destructed.
	virtual ~DramaMovie() {}

	// Description: this is the equality operator
	// preconditions: m is already initialized and represents a DramaMovie
	// postconditions: returns True if the movies are the same.
	virtual bool operator==(const Rentable & m) const;

	// Description: this is the less-than operator
	// preconditions: m is already initialized and represents a DramaMovie
	// postconditions: True if this movie has a smaller
	// value than m.
	virtual bool operator<(const Rentable & m) const;

	// Description: This function is a helper for the <<  operator.
	// it prints this object to os.
	// preconditions: os is open, valid and usable.
	// postconditions: this object is printed to os.
	virtual void print(ostream & os) const;

}; // end of DramaMovie

#endif // RENTABLES_H
