#include "Bank.h"
#include<iostream>
#include<fstream>
#include<sstream>

using std::stringstream;
using std::ifstream;
using std::cout;
using std::endl;
using std::stoi;

//Bank implementations
Bank::Bank()
{
};

Bank::~Bank()
{
}

void Bank::IntakeTransactions()
{
	ifstream inFile;
	inFile.open("BankTransIn.txt");
	string line;

	while (inFile)
	{
		getline(inFile, line);
		pendingTransactions.push(line);
	}

	inFile.close();
}

void Bank::ProcessTransactions()
{
	while (!pendingTransactions.size() == 0)
	{
		char letter;
		string token;
		string line = pendingTransactions.front();
		stringstream ss(line);
		letter = ss.peek();

		switch (letter)
		{
			
			case 'O':
			{
				string firstName;
				string lastName;
				string clientID;

				//parse line
				ss << token; // discard operation letter

				ss << lastName;
				ss << firstName;
				ss << clientID;

				//create client
				Client* newClient = new Client(lastName, firstName, stoi(clientID));

				//insert client into tree
				this->accountTree.Insert(newClient);

				break;
			}
			case 'D':
			{
				//todo
				break;
			}
			case 'W':
			{
				break;
			}
			case 'T':
			{
				break;
			}
			default:
			{

			}
		}
	}
}

void Bank::Print()
{
	accountTree.PrintTree();
}