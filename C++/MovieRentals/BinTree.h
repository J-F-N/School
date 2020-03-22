/*Author: John Neigel
---------------------------
Last Edit: 08/16/2019
---------------------------
Description: Class interface for the BinTree class.
This class stored Product objects according to the properties
of a binary search tree. This class has friend functions from
Transactions derived classes to allow transactions to make
appropriate changes to the tree structure.
---------------------------
*/

#ifndef PROGRAM4_BINTREE_H
#define PROGRAM4_BINTREE_H

#include "Product.h"

class BinTree
{

private:

    //Node struct to hold item information
//and relationships between items.
//public to allow ProductsDB to store pointers to tree roots in vector.
    struct Node {
        Product* product;
        Node* left;
        Node* right;
        Node() {
            product = nullptr;
            left = nullptr;
            right = nullptr;
        }
        ~Node() {
            delete product;
            product = nullptr;

            delete left;
            left = nullptr;

            delete right;
            right = nullptr;
        }
    };

	//Node struct to hold item information
	//and relationships between items.

	Node* root;		//root of the tree

    //recursive helper for insertions
    void insertHelper(Node* node, Product* product);

    //recursive helper for retrievals
    bool retrieveHelper(Node* node, Product* product);

    //recursive helper for destructor
    void emptyTree(Node* node);

    //recursive helper for display()
    static void displayHelper(Node* node);

public:

    BinTree();
    ~BinTree();
    void insert(Product* product);		//inserts a product into the tree
    bool retrieve(Product* product);	//retrieves a product from the tree
    Node* getRoot();
    void display();
};

#include "BinTree.cpp"

#endif //PROGRAM4_BINTREE_H
