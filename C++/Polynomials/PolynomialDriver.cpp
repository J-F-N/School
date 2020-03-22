#include"polynomial.h"
#include<iostream>

using std::cout;
using std::endl;

int main()
{
	Polynomial p1;

	//test insertions & print
	p1.changeCoefficient(2, 9); //first term added
	cout << p1 << endl;
	p1.changeCoefficient(3, 4); // insertion to end
	cout << p1 << endl;
	p1.changeCoefficient(2, 6); // insertion into middle
	cout << p1 << endl;
	p1.changeCoefficient(2, 7); // insertion into middle
	cout << p1 << endl;
	p1.changeCoefficient(2, 8); // insertion into middle
	cout << p1 << endl;

	//test copy constructor
	Polynomial p2(p1);
	cout << p2 << endl;

	//this last one screwed with me. The copy constructor is somehow creating the head
	//as a nullptr, and I don't know why.

	return 0;
}


