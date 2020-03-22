#pragma once
#include <iostream>
using std::ostream;

class Polynomial
{
public:

	//default constructor & destructor
	Polynomial();
	~Polynomial();

	//copy constructor
	//makes a deep copy of the polynomial passed as a parameter.
	Polynomial(const Polynomial &poly);

	//function to return the degree of the polymonial, that is the power of the highest order term.
	//will return 0 is polynomial is empty or contains no powered terms.
	int degree() const;

	//returns the coefficient in front of the term with the power passed by parameter.
	//assumes the target term exists in the polynomial
	double coefficient(const int power) const;

	//replaces the coefficient of the target term with the passed in value
	//if the term does not exist, the term is inserted
	bool changeCoefficient(const double newCoefficient, const int power);

	//arithmetic operator overloads
	Polynomial operator+(const Polynomial& poly) const; //adds the passed polynomial to the calling object
	Polynomial operator-(const Polynomial& poly) const; //subtracts the passed polynomial from the calling object

	//boolean comparison operator overloads
	//compares the calling and passed polynomials for equality
	bool operator==(const Polynomial& poly) const; //returns true if the polynomials are the same
	bool operator!=(const Polynomial& poly) const; //returns true is the polynomails are not the same

	//assingment operator overloads
	Polynomial& operator=(const Polynomial& poly);
	Polynomial& operator+=(const Polynomial& poly);
	Polynomial& operator-=(const Polynomial& poly);

	//outstream overload
	//prints a formatted representation of a polynomials contents
	friend ostream& operator<<(ostream& stream, const Polynomial& poly);

private:

	struct Term 
	{
		double coefficient; //coefficient number in front of each powered term
		int power; //the power associated with each term
		Term* next; //pointer to the next term in the polynomial
		Term* previous; //pointer to the previous term in the polynomial
	};

	int size;
	Term* head;

	//Private helper functions
	//insert() inserts a new term with passed coefficient and power values in front of the pos term
	bool insert(Term* pos, const double newCoefficient, const int power);
	//remove() removes the term node passed in
	bool remove(Term* pos);
};

