#include "BinTree.h"
#include "Classic.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
void BinTree::insertHelper(Node* node, Product* product) {

    if(!node) {
        Node* newNode = new Node();
        newNode->product = product;
        root = newNode;
        return;
    }

    if(*product == node->product) {
        node->product->increaseStock(product->getStock());
    }

    if(*product < node->product) {
        if(!node->left) {
            Node* newNode = new Node();
            newNode->product = product;
            node->left = newNode;
        }
        else {
            insertHelper(node->left, product);
        }
    }

    else {
        if(!node->right) {
            Node* newNode = new Node();
            newNode->product = product;
            node->right = newNode;
        }

        else {
            insertHelper(node->right, product);
        }
    }
}

void BinTree::displayHelper(Node* node) {

    if(!node) return;

//    cerr << "displayHelper(node->left)";
    displayHelper(node->left);
//
//    node->product->printProduct();
//    cerr << "*node-";
    cout << *node->product << endl;
//
    displayHelper(node->right);
}

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
bool BinTree::retrieveHelper(Node* node, Product* product) {

//    cout << "entered the BinTree::retrieve helper" << endl;
    if(node == nullptr) return false;

    if(*product == node->product) //product is found
    {
//        cout << "found the product" << endl;
        if(!node->product->getStock() == 0) {
            node->product->reduceStock();

            return true;
        }
    }

    else if(*product < node->product) //go left
    {
//        cout << "went left" << endl;
        retrieveHelper(node->left, product);
    }

    else //go right
    {

//        cout << "went right" << endl;
        retrieveHelper(node->right, product);
    }
    if(*product == node->product)
    {
        return true;
    }
    return retrieveHelper(node->left, product)
    || retrieveHelper(node->right, product);
}

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
void BinTree::emptyTree(Node* node) {

}

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
BinTree::BinTree() {

    root = nullptr;
}

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
BinTree::~BinTree() {
    delete root;
}

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
void BinTree::insert(Product* product) {

    //EDGE-CASE SECTION
    //Case: empty tree; root is nullptr
    if(nullptr == root)   //When BinTree.isEmpty()
    {
        Node* newNode;
        newNode = new Node();
        newNode->product = product;
        newNode->left = nullptr;
        newNode->right = nullptr;
        root = newNode;
        return;
    }

    insertHelper(root, product);
}

/*---------------------------------------------------------------
Description:
-----------------------------------------------------------------
Preconditions:
-----------------------------------------------------------------
PostConditions:
---------------------------------------------------------------*/
bool BinTree::retrieve(Product* product) {

//    cout << "entered the BinTree::retrieve" << endl;
    return retrieveHelper(root, product);
}

BinTree:: Node* BinTree::getRoot() {
    return root;
}

void BinTree::display() {
    //pawn this off to displayHelper
    displayHelper(root);
}
