#pragma once

#include<string>
#include<list>

using std::list;
using std::string;

//class to contain balance and history of account
class Account
{

private:

	int balance = 0;
	list<string> history;

public:

	Account();
	~Account();
	int getBalance();
};