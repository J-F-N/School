#pragma once
#include<iostream>
#include "nodedata.h"
using namespace std;

class BinTree {
public:

	BinTree();								// constructor

	//---------------BinTree---------------
	// copy constructor
	// Preconditions: NONE
	// Postconditions: constructed tree is deep copy of parameter tree
	BinTree(const BinTree& tree);

	//---------------~BinTree---------------
	// destructor, calls makeEmpty
	// Preconditions: NONE
	// Postconditions: all object memory is deallocated
	~BinTree();		

	//---------------isEmpty---------------
	// true if tree is empty, otherwise false
	// Preconditions: NONE
	// Postconditions: BinTree remains unchanged.
	bool isEmpty() const;				

	//---------------makeEmpty---------------
	// make the tree empty so isEmpty returns true
	// Preconditions: NONE
	// Postconditions: all Node and NodeData memory is deallocated, root is nullptr
	void makeEmpty();				

	//---------------operator<<---------------
	//overloads << operator to allow BinTree in outstream
	// Preconditions: NONE
	// Postconditions: BinTree remains unchanged.
	friend ostream operator<<(ostream& stream, const BinTree& tree); 

	//---------------operator=---------------
	//assigns calling tree as deep copy of passed tree
	// Preconditions: NONE
	// Postconditions: calling tree is deep copy of parameter tree
	BinTree& operator=(const BinTree&);		

	//---------------operator==---------------
	//compares two trees, true if equal in structure and value, false otherwise
	// Preconditions: NONE
	// Postconditions: BinTree remains unchanged.
	bool operator==(const BinTree& tree) const; 

	//---------------operator!=---------------
	//compares two trees, true if NOT equal in structure and value, false otherwise
	// Preconditions: NONE
	// Postconditions: BinTree remains unchanged.
	bool operator!=(const BinTree& tree) const; 

	//---------------insert---------------
	//inserts passed NodeData as ptr to tree, true if inserted, false if duplicate
	// Preconditions: NONE
	// Postconditions: a new Node with parameter data is inserted into proper position
	bool insert(NodeData* nodeData);	

	//---------------retrieve---------------
	//returns ptr to value passed in, if exists in tree
	// Preconditions: NONE
	// Postconditions: BinTree remains unchanged.
	bool retrieve(const NodeData& nodeData, NodeData*& dataPtr) const;

	//---------------getHeight---------------
	//returns an int for the height of an value in tree, 0 if not found
	// Preconditions: NONE
	// Postconditions: BinTree remains unchanged.
	int getHeight(const NodeData&) const;

	//---------------bstreeToArray---------------
	//empties and transfers tree to array of DataNode ptr
	// Preconditions: NONE
	// Postconditions: BinTree is empty and array contains data from tree
	void bstreeToArray(NodeData* []);

	//---------------displaySideways---------------
	// Displays a binary tree as though you are viewing it from the side;
	// hard coded displaying to standard output.
	// Preconditions: NONE
	// Postconditions: BinTree remains unchanged.
	void displaySideways() const { // provided below, displays the tree sideways
		sideways(root, 0);
	}

private:

	struct Node {
		NodeData* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
	};
	Node* root;								// root of the tree

	//helper functions
	void outputHelper(ostream& stream);						// helper for operator<<()
	void inorderTreeToArray(Node* node, NodeData* array[]); //helper for bstreeToArray()
	void inorderHelper(Node* node, ostream& stream) const;  //helper for operator<<()
	void copyHelper(Node* root);							//helper for copy operator==()
	void postOrderDelete(Node* root);						//helper for Empty()
	int heightHelper(const Node* node, const NodeData& data) const; //helper for getHeight()
	BinTree::Node* preOrderCopy(const Node* root);			//helper for copy constructor
	bool comparisonHelper(Node* callNode, Node* paramNode) const;

	void sideways(Node* current, int level) const { // provided below, helper for displaySideways()
		if (current != NULL) {
			level++;
			sideways(current->right, level);

			
			for (int i = level; i >= 0; i--) {
				cout << "    ";
			}

			cout << *current->data << endl;        // display information of object
			sideways(current->left, level);
		}
	}
};