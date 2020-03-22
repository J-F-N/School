#include "Account.h"
#include<iostream>

using std::cout;
using std::endl;

Account::Account()
{
}


Account::~Account()
{
}

int Account::getBalance()
{
	return this->balance;
}