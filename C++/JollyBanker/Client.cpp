#include "Client.h"
#include<iostream>

using std::cout;
using std::ostream;
using std::endl;

//Client implementations
Client::Client()
{
	this->firstName = "";
	this->lastName = "";
	this->clientID = 0;
}

Client::~Client()
{
}

Client::Client(string lastName, string firstName, int clientID)
{
	this->lastName = lastName;
	this->firstName = firstName;
	this->clientID = clientID;
}

string Client::getFirstName()
{
	return this->firstName;
}

string Client::getLastName()
{
	return this->lastName;
}

int Client::getClientID()
{
	return this->clientID;
}

bool Client::operator==(Client& tClient) const
{
	if (this->clientID == tClient.clientID)
	{
		cout << "Duplicate ID: Client not added." << endl;
		return true;
	}

	else if (this->firstName == tClient.firstName && this->lastName == tClient.lastName)
	{
		cout << "Client already exists: Client not added." << endl;
		return true;
	}

	else return false;
}
bool Client::operator>(Client& tClient) const
{
	if (this->clientID > tClient.clientID)
	{
		return true;
	}

	else return false;
}
bool Client::operator<(Client& tClient) const
{
	if (this->clientID < tClient.clientID)
	{
		return true;
	}

	else return false;
}

void Client::PrintAccounts()
{
	cout << "-----------------------------------------------" << endl;
	cout << "Client: " << this->firstName << this->lastName << "/tID: "  << this->clientID << endl;
	cout << "---------------------------------------" << endl;

	for (int i = 0; i < 10; i++)
	{
		switch (i)
		{
			case 0:
			{
				cout << " Account: Money Market" << endl;
			}

			case 1:
			{
				cout << " Account: Prime Money Market" << endl;
			}

			case 2:
			{
				cout << " Account: Long-Term Bond" << endl;
			}

			case 3:
			{
				cout << " Account: Short-Term Bond" << endl;
			}

			case 4:
			{
				cout << " Account: 500 Index Fund" << endl;
			}

			case 5:
			{
				cout << " Account: Capital Value Fund" << endl;
			}

			case 6:
			{
				cout << " Account: Growth Equity Fund" << endl;
			}

			case 7:
			{
				cout << " Account: Growth Index Fund" << endl;
			}

			case 8:
			{
				cout << " Account: Value Fund" << endl;
			}

			default:
			{
				cout << " Account: Value Stock Index" << endl;
			}
		}

		cout << "Balance: " << accounts[i].getBalance() << endl;

	}

}