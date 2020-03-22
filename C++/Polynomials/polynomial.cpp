#include "polynomial.h"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;


Polynomial::Polynomial()
{
	size = 0;
	head = new Term();
	head->coefficient = 0;
	head->power = 0;
	head->next = nullptr;
	head->previous = nullptr;
}//polynomial


Polynomial::~Polynomial()
{
	while (head->next) //while still nodes present
	{
		remove(head->next);
		size--;
	}
}//~polynomial

Polynomial::Polynomial(const Polynomial &poly)
{
	Polynomial* newPoly = new Polynomial();
	Term* current = poly.head->next; //tracking current term to be copied
	Term* lastAdded = newPoly->head; //holds onto insertion position

	for (int i = 0; i < poly.size - 1; i++)
	{
		//instantiate new term and copy values
		Term* newTerm = new Term();
		newTerm->coefficient = current->coefficient;
		newTerm->power = current->power;
		newTerm->previous = lastAdded;
		lastAdded->next = newTerm;
		newPoly->size++;

		lastAdded = lastAdded->next; //update last added term
		current = current->next; //increment to next Term to be copied
	}
	
	//all terms copied, link last term to head.
	lastAdded->next = newPoly->head;
	newPoly->head->previous = lastAdded;
}//polynomial

bool Polynomial::changeCoefficient(const double newCoefficient, const int power)
{
	Term* target = head->next;

	//case: first insertion to list
	if (!target)
	{
		cout << "first insertion" << endl;
		Term* newTerm = new Term();
		newTerm->coefficient = newCoefficient;
		newTerm->power = power;
		this->head->next = newTerm;
		newTerm->previous = head;
		this->size++;
		return true;
	}

	while (target)
	{
		//case: replacement
		if (target->power == power)
		{
			cout << "replacement" << endl;
			this->insert(target, newCoefficient, power);
			this->remove(target);
			return true;
		}

		//case: insertion
		else if (target->power < power)
		{
			cout << "middle" << endl;
			this->insert(target, newCoefficient, power);
			this->size++;

			return true;
		}

		else if (target->next == nullptr)
		{
			cout << "end" << endl;
			//case: insertion at end of polynomial
			Term* newTerm = new Term();
			newTerm->coefficient = newCoefficient;
			newTerm->power = power;
			target->next = newTerm;
			newTerm->previous = target;
			this->size++;
			return true;
		}
		target = target->next;
	}
}//changeCoefficient

bool Polynomial::insert(Term* pos, const double newCoefficient, const int power)
{
	Term* newTerm = new Term();
	newTerm->coefficient = newCoefficient;
	newTerm->power = power;
	newTerm->next = pos;
	newTerm->previous = pos->previous;
	pos->previous->next = newTerm;
	pos->previous = newTerm;
	return true;
}//insert

bool Polynomial::remove(Term* pos)
{
	//case: removal from end
	if (pos->next == nullptr)
	{
		pos->previous->next = nullptr;
		pos->previous = nullptr;
		delete(pos);
		return true;
	}

	else
	{
		pos->previous->next = pos->next;
		pos->next->previous = pos->previous;
		pos->next = nullptr;
		pos->previous = nullptr;
		delete(pos);
		return true;
	}
}

ostream& operator<<(ostream& stream, const Polynomial& poly)
{
	Polynomial::Term* current = poly.head->next;
	while (current)
	{
		stream << current->coefficient << "x^" << current->power;
		current = current->next;
	}

	return stream;
}