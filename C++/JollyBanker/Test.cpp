#include"Client.h"
#include"Account.h"
#include"Bank.h"
#include"BSTree.h"

int main()
{
	Bank bank1;
	bank1.IntakeTransactions();
	bank1.Print();
	return 0;
}