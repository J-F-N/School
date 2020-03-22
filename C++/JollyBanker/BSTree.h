#pragma once
#include"Client.h"

//binary tree containing client objects
class BSTree {

public:

	BSTree();
	~BSTree();

	//public functions
	bool Insert(Client* clientPtr);
	//bool Retrieve(const int& num, Client*& client) const; //recursive search of tree for account
	//void Display() const; //in-order traversal of tree to dispay accounts
	//void Empty();//clear all clients from tree
	bool isEmpty() const; //checks to see if there are clients in tree
	void PrintTree();

private:

	//struct to comprise BSTree
	struct Node
	{
		Client* clientPtr;
		Node* left;
		Node* right;
	};

	bool insertHelper(Client* clientPtr, Node* nodePtr);
	void printHelper(Node* nodePtr);

	Node* root;
};