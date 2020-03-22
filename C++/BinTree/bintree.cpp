#include "bintree.h"

//----------Constructor/Destructor----------
//Default constructor
BinTree::BinTree()
{
	this->root = nullptr;
}

//Deconstructor
BinTree::~BinTree()
{
	this->makeEmpty();
}

//Copy constructor
BinTree::BinTree(const BinTree& tree)
{
	this->root = nullptr;
	copyHelper(tree.root);
}

//----------Public member functions----------
//converts a BinTree to an array of NodeData ptr
//does not currently work
/*void BinTree::bstreeToArray(NodeData* array[])
{
	this->inorderTreeToArray(root, array);
}*/

//returns the height of a value found in the tree
//as an integer, 0 if value is not found
int BinTree::getHeight(const NodeData& data) const
{
	int height = 0;
	return heightHelper(root, data);
}

//Function to search the tree for the passed in NodeData value
//returns true and a NodeData ptr by reference if found, false otherwise
bool BinTree::retrieve(const NodeData& nodeData, NodeData*& dataPtr) const
{
	Node* current = root;

	while (current)
	{
		if (nodeData == *(current->data))
		{
			dataPtr = current->data;
			return true;
		}

		else if (nodeData < *(current->data)) //move left
		{
			current = current->left;
		}

		else //move right
		{
			current = current->right;
		}
	}

	return false;
}

//Function to insert the passed NodeData into the tree
//in the proper position
bool BinTree::insert(NodeData* nodeData)
{
	Node* parent = nullptr;
	Node* current = root;

	if (!root) //first node added
	{
		root = new Node();
		root->data = nodeData;
		return true;

	}

	else if (*nodeData == *(current->data)) //duplicate found
	{
		return false;
	}

	else while (current) //iterates to proper insertion position
	{
		parent = current;

		if (*nodeData == *(current->data)) //duplicate found
		{
			return false;
		}

		else if (*nodeData < *(current->data)) //move left
		{
			current = current->left;
		}

		else //move right
		{
			current = current->right;
		}
	}

	if (*nodeData < *(parent->data)) //make insertion to left
	{
		parent->left = new Node();
		parent->left->data = nodeData;
		return true;
	}

	if (*nodeData > *(parent->data)) // make insertion to right
	{
		parent->right = new Node();
		parent->right->data = nodeData;
		return true;
	}

	return false;
}

//deletes dynamic memory portions of the tree, leaving it empty
//root is left as nullptr
void BinTree::makeEmpty()
{
	postOrderDelete(root);

	root = nullptr;
}

//function to check if a tree is empty
//returns true if root is nullptr(ie. tree is empty), false if otherwise
bool BinTree::isEmpty() const
{
	if (!root)
	{
		return true;
	}

	else
	{
		return false;
	}
}

//----------Helper Functions----------
//Helper function to assist recursion of boolian comparison operators
bool BinTree::comparisonHelper(Node* callNode, Node* paramNode) const
{
	if (callNode == nullptr && paramNode == nullptr)
	{
		return true;
	}

	else if((callNode == nullptr && paramNode != nullptr) ||
			(callNode != nullptr && paramNode == nullptr) ||
			(*(callNode->data) != *(paramNode->data)))
	{
	
			return false;
	}

	else
	{
		comparisonHelper(callNode->left, paramNode->left);
		comparisonHelper(callNode->right, paramNode->right);
	}
}

//helper function for preorder copying of a binary tree
void BinTree::copyHelper(Node* root)
{
	if (root)
	{
		this->insert(root->data);
		copyHelper(root->left);
		copyHelper(root->right);
	}
}

//helper function to post order traverse and delete tree
void BinTree::postOrderDelete(Node* root)
{
	if (!root)//end of subtree
	{
		return;
	}

	postOrderDelete(root->left);
	postOrderDelete(root->right);

	delete root;

	root = nullptr;
}

//helper function to preorder traverse and copy existing tree
BinTree::Node* BinTree::preOrderCopy(const BinTree::Node* root)
{
	BinTree::Node* newNode = new BinTree::Node();

	if (!root)
	{
		return nullptr;
	}

	else 
	{
		*newNode->data = *root->data;
		newNode->left = preOrderCopy(root->left);
		newNode->right = preOrderCopy(root->right);
	}

	return newNode;
}

//helper function to count the height of a value in the tree recursively
int BinTree::heightHelper(const Node* node, const NodeData& data) const
{
	if (node == nullptr)
	{
		return 0;
	}
	
	else if (*(node->data) == data)
	{
		return 1;
	}


	int height = 0;
	height = heightHelper(node->left, data);
	height += heightHelper(node->right, data);


	if (height == 0)
	{
		return 0;
	}

	else
	{
		return height + 1;
	}
}

//Helper function to assist in outstream operation
//does not currently work(unresolved external error)
/*void BinTree::inorderHelper(Node* node, ostream& stream) const
{
	if (!node)
	{
		return;
	}

	inorderHelper(node->left, stream);

	stream << *(node->data);

	inorderHelper(node->right, stream);
}*/

//Helper function to assist recursion in outstream conversion of BinTree
//Function was needed as intermediary between stream object and BinTree object
//does not currently work(unresolved external error)
/*void BinTree::outputHelper(ostream& stream)
{
	inorderHelper(this->root, stream);
}*/

//Function to convert a BinTree to an Array of NodeData Pointers.
//Does not work currently.
/*void BinTree::inorderTreeToArray(Node* node, NodeData* array[])
{
	if (!node)
	{
		return;
	}

	inorderHelper(node->left, array);

	 *(node->data);

	inorderHelper(node->right, stream);
}*/

//----------Operator Overloads----------
//Assigns one tree to another, creating a deep copy
BinTree& BinTree::operator=(const BinTree& tree)
{
	this->makeEmpty();
	copyHelper(tree.root);
	
	return *this;
}

//Compares two trees, true if equal, false otherwise
bool BinTree::operator==(const BinTree& tree) const
{
	bool isEqual = true;
	return comparisonHelper(root, tree.root);
}

//Compares two trees, true if NOT equal, false if otherwise
bool BinTree::operator!=(const BinTree& tree) const
{
	return !(*this == tree);
}

//Overload to allow outstream use of BinTree to print to console
//Does not currently work(unresolved external error)
/*ostream& operator<<(ostream& stream, BinTree& tree)
{
	tree.outputHelper(stream);
	return stream;
}*/