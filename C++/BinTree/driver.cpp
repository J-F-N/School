#include"bintree.h"
using namespace std;

int main() {

	//test constructor
	BinTree tree1;

	//initializing some NodeData
	NodeData n1("d");
	NodeData n2("c");
	NodeData n3("f");
	NodeData n4("a");
	NodeData n5("b");
	NodeData n6("e");
	NodeData n7("i");
	NodeData n8("u");
	NodeData n9("v");
	NodeData n10("w");
	NodeData n11("l");
	NodeData n12("m");
	NodeData n13("h");
	NodeData n14("x");
	NodeData n15("k");
	NodeData n16("y");
	NodeData n17("z");
	NodeData n18("n");
	NodeData n19("j");
	NodeData n20("q");
	NodeData n21("r");
	NodeData n22("o");
	NodeData n23("p");
	NodeData n24("t");
	NodeData n25("s");

	//test insertions
	tree1.insert(&n1);
	tree1.insert(&n2);
	tree1.insert(&n3);
	tree1.insert(&n4);
	tree1.insert(&n5);
	tree1.insert(&n6);
	tree1.insert(&n7);
	tree1.insert(&n8);
	tree1.insert(&n9);
	tree1.insert(&n10);
	tree1.insert(&n11);
	tree1.insert(&n12);
	tree1.insert(&n13);
	tree1.insert(&n14);
	tree1.insert(&n15);
	tree1.insert(&n16);
	tree1.insert(&n17);
	tree1.insert(&n18);
	tree1.insert(&n19);
	tree1.insert(&n20);
	tree1.insert(&n21);
	tree1.insert(&n22);
	tree1.insert(&n23);
	tree1.insert(&n24);
	tree1.insert(&n25);
	
	//test copy constructor
	BinTree tree2(tree1);

	//test output operator
	tree1.displaySideways();

	cout << "\n--------------------------------\n" << endl;

	tree2.displaySideways();

	cout << "\n--------------------------------\n" << endl;
	
	//test tree deletion and empty tree
	BinTree tree3;
	cout << tree3.isEmpty() << endl; //true: with new instantiation
	cout << tree1.isEmpty() << endl; //false
	tree1.makeEmpty();
	cout << tree1.isEmpty() << endl; //true

	cout << "\n--------------------------------\n" << endl;

	//test assignment(=) operator
	tree3 = tree2;
	tree3.displaySideways();
	cout << "\n--------------------------------\n" << endl;

	//test retrieve
	NodeData data1("a");
	NodeData data2("bb");
	NodeData* dataPtr;
	cout << tree3.retrieve(data1, dataPtr) << endl;//true
	cout << *dataPtr << endl; //a
	cout << tree3.retrieve(data2, dataPtr) << endl;//false
	cout << "\n--------------------------------\n" << endl;

	//test getHeight
	cout << "Height is: " << tree3.getHeight(data1) << endl;
	cout << "\n--------------------------------\n" << endl;

	//test comparison operators(==)(!=)
	if (tree3 == tree2) //true
	{
		cout << "The trees are equal" << endl;
	}

	else
	{
		cout << "The trees are NOT equal" << endl;
	}

	if (tree3 != tree1) //true
	{
		cout << "The trees are NOT equal" << endl;
	}

	else
	{
		cout << "The trees are equal" << endl;
	}
	cout << "\n--------------------------------\n" << endl;
	
	return 0;
}