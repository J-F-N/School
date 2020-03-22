#ifndef AVLTREE_H
#define AVLTREE_H

// Description:
// This is an AVL tree that will store the rentables' information.

#include <string>
#include <map>
#include "NodeData.h"
using namespace std;

const std::map<std::char, string> ACCEPTABLETYPES = {
		{'C',"ClassicMovie"},
		{'F',"FunnyMovie"},
		{'D',"DramaMovie"}
};


const std::map<std::char, string> ACCEPTABLEMediums = {
		{'D',"DVD"}
};

// An avl tree that stores the rentables
class AVLTree
{
	private:

		// // nodes of the tree
		struct Node{
			NodeData* data;
			
			Node* left;
			Node* right;

		}

		NodeData* root = NULL;

		//Description: This makes the NodeData object a child of a different node
		// inserts the type in descending order, but each type is inserted in ascending order.
		// 
		// To illustrate, if you print in-order, the types will be in descending order, buy
		// the movies in every type will be in asceding order
		//Preconditions: This Object is initialized
		//Postconditions: The AVLTree will have one more node in the tree
		void insertNode(Node* root, NodeData* mp);
		//If(root == nullptr) insert here;
		//NodeData* rp = root->data;
		//
		//if ((mp->Rentaple)->type < (rp->movie)->type) {
		//	insertHelper(movie * root->right, movie * mp); // inverse tree
		//	return;
		//}
		//
		//if ((mp->movie)->type > (rp>movie)->type) {
		//	insertHelper(movie * root->left, movie * mp); // inverse tree
		//	return
		//}
		//
		//if (*(mp->movie) < *(rp->movie)) {
		//	insertHelper(movie * root->left, movie * mp); // Same type in-order
		//}
		//
		//if (*(mp->movie) > *(root->movie)) {
		//	insertHelper(movie * root->right, movie * mp); // inverse tree
		//}

		//else same type of movie, increment the the new stock and delete mp


		//Description: deletes a node and calls rebalanceTree.
		//Preconditions: This Object is initialized
		//Postconditions: The AVLTree will have one more node in the tree
		void deleteNode(Node* & cur);
		//psuedo-code: we didn't cover this in class, so it is left up to the
		//implementation



	public:

		//Description: This creates a new AVLTree
		//Preconditions: This object is un-initialized
		//Postconditions: This Object is initialized
		AVLTree();

		//Description: This destroys the AVLTree
		//Preconditions: This Object is initialized
		//Postconditions: This Object is un-initialized
		~AVLTree();

		//Description: This creates a new NodeData object using the newInput, and then calls insertNode(NodeData*), and then balances the tree
		//Preconditions: The String has a valid movie type, as well as a non-negative stock amount.
		//Postconditions: The AVLTree will have one more node in the tree
		void insertNode(string newInput);
		//psued-code:
		//
		// split the string into words.
		//
		// make sure the movie type is a key in ACCEPTABLETYPE.
		// if the type is not in ACCEPTABLETYPE, print an error message
		//
		// Check the validty of the stock by making sure it is bigger than 0
		// if the stock is 0 or less, print an error message
		//
		// Check that the year is bigger than 1500 and less than current time using ctime
		// if the year is not valid, print an error message
		//
		// assume the title and names are valid and call helper function insertNode(NodeData*)


		//Description: Checks the balance of the AVLTree, and calls rebalanceTree if nessecary
		//Preconditions: A newNode has just been inserted
		//Postconditions: The AVLTree is balanced
		boolean checkBalance();
		//psuedo-code:
		// Assume you have a helper functions checkBalance(NodeData*);
		// start from root
		// return (max(checkBalance(root->left), checkBalance(root->right)) > 1;

		//Description: Finds the highest unbalanced node, then balances the AVLtree
		//Preconditions: The AVLTree isn't balanced
		//Postconditions: The AVLTree is balanced
		void rebalanceTree();
		//psuedo-code:
		// Assume you have a helper functions checkBalance(NodeData*) that retruns the hight of a root
		// start from root
		// find the first unbalanced root using checkBalance(NodeData*)
		// 
		// find if its unbalance is left-left, left-right, right-left, or right-right
		// go to side that is unbalanced and find the long side using
		// checkBalance(NodeData*)

		//Description: Rempoves all of the nodes from the AVLTree
		//Preconditions: There is at least one node, in the AVLTree.
		//Postconditions: There are no more nodes in the AVLTree, and the head is pointing to NULL
		void clearTree();
		//psuedocode:
		// Assume there is a helper function clear(Node* &root) that deletes a tree form the root
		//
		// clearTree() simply calls clear with the root of the tree
		//
		// void clear(NodeData* &root) is defined like this
		// if (root == nullptr) return;
		//
		// clear(root->left)
		// clear(root->right)
		// delete root->data
		// delete root
		// root = nullptr.


		//Description: This will process a borrow or return trans
		//Preconditions: The NodeData exists, and has enough stock
		//Postconditions: the stock of the specified rentable is changed and a copy of the rentable is made
		Rentable changeStock(string command, int difference);
		// psuedo-code:
		//  assume there is a helper function find(Node* & cur, NodeData item) that searches the whole tree recursively
		// and returns a pointer to the  node that contains data equal to item. When type is being compared, it will go to the 
		// left if items type is bigger then the data in cur. Otherwise, it will follow normal BST logic of smaller to the left. 
		//
		// 
		// assume there is a helper function findClassic(Node* & cur, NodeData item, set& set) that searches the whole tree recursively
		// and returns a pointer to the  node that contains data equal to item. If the find is looking for a classic movie,
		// then it will update set with any movie that if finds to be the same but with different actor. 
		// find(Node* & cur, NodeData item, set& set) should traverse the whole tree
		//
		// chageStock should
		//
		// parse a command line to get the rentable objects data and whether to decrease the stock or increase it
		// If the medium is not in ACCEPTABLEMEDIUMS, then print error message
		// if the type of the rentable is not in ACCEPTABETYPES, print error message
		//
		// initialize a set;
		// Node* found = nullptr;
		//
		// if (movie type is classic){
		//		found = findClassic(Node* & cur, NodeData item, set& set);
		//		if (found == nullptr) print error message and show alternatives if set is not empty;
		//		return;
		// }
		// else found = find(Node* & cur, NodeData item);
		// 
		// if (found == nullptr) {
		//		if (you wanted to borrow) print error message and return.
		//		if (you wanted to insert) make a new node and return.
		//	}
		// 
		// if (changing the stock with difference will result in negative stock) print error message and return.
		// change the stock.
		// if the new stock is 0, call deleteNode

		

		//Description: This prints out all of the Nodes from a given Genre
		//Preconditions: The char is of a valid Genre type
		//Postconditions: The Genre's is printed out inorder
		printGenre(char);
		// psuedo-code:
		// use recursion and a helper function to traverse the whole tree.
		// only print a node if it is the specified genre

		//Description: This prints out all of the genres inventory inorder, because it is all sorted inorder
		//Preconditions: There is at least one NodeData in the AVLTree
		//Postconditions: The whole inventory is print in order of genre, and is sorted according to each genres internal order.
		printInventory();
		// psuedo-code:
		// use recursion and a helper function to traverse the whole tree and print everything.
};