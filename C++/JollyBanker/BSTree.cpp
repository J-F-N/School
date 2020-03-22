#include"BSTree.h"
#include"Client.h"
#include<iostream>

using std::cerr;
using std::endl;
using std::cout;

//BSTree implementations
BSTree::BSTree()
{
	this->root = nullptr;
}

BSTree::~BSTree()
{
}

bool BSTree::Insert(Client* clientPtr)
{
	return insertHelper(clientPtr, root);
}

bool BSTree::insertHelper(Client* client, Node* nodePtr)
{
	Node* previous = nodePtr;

	//duplicate case
	if (*(client) == *(nodePtr->clientPtr))
	{
		return false;
	}

	//move left
	if (*(client) < *(nodePtr->clientPtr))
	{
		if (nodePtr->left == nullptr)
		{
			Node* insNode = new Node();
			previous->left = insNode;
			insNode->clientPtr = client;
			(*nodePtr->clientPtr).PrintAccounts();
			return true;
		}
		previous = nodePtr;
		insertHelper(client, nodePtr->left);
	}

	//move right
	if (*(client) > * (nodePtr->clientPtr))
	{
		if (nodePtr->right == nullptr)
		{
			Node* insNode = new Node();
			previous->right = insNode;
			insNode->clientPtr = client;
			(*nodePtr->clientPtr).PrintAccounts();
			return true;
		}

		previous = nodePtr;
		insertHelper(client, nodePtr->right);
	}
}

bool BSTree::isEmpty() const
{
	if (this->root)
	{
		return true;
	}

	else return false;
}

//preorder recursive helper
void BSTree::printHelper(Node* nodePtr)
{
	if (nodePtr == nullptr)
	{
		return;
	}

	//print at node
	(*nodePtr->clientPtr).PrintAccounts();


	printHelper(nodePtr->left);


	printHelper(nodePtr->right);
}

void BSTree::PrintTree()
{
	return printHelper(root);
}