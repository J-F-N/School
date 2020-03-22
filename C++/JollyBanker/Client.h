#pragma once
#include"Account.h"
#include<string>

using std::string;

//class to model a bank client with accounts
class Client
{

private:

	string firstName;
	string lastName;
	int clientID = 0;
	Account accounts[10];

public:

	//constructors & destructors
	Client();
	~Client();
	Client(string lastName, string firstName, int clientID);

	//getters
	string getFirstName();
	string getLastName();
	int getClientID();
	void PrintAccounts();

	//operator overloads
	bool operator==(Client& tClient) const;
	bool operator>(Client& tClient) const;
	bool operator<(Client& tClient) const;
};