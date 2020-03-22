#pragma once
#include"BSTree.h"
#include<queue>
#include<string>

using std::queue;
using std::string;

//manages transactions, client accounts, and conducts banking operations
class Bank
{
public:
	Bank();
	~Bank();
	void IntakeTransactions();
	void ProcessTransactions();
	void Print();
private:

	queue<string> pendingTransactions;
	BSTree accountTree;
};