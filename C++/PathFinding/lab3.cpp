#include <iostream>
#include<fstream>
#include "graphm.h"
#include "GraphL.h"

using namespace std;

int main() {

	ifstream inFile("data31.txt");
	if (!inFile) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	//test constructor
	int run = 1;
	for (;;)
	{
		GraphM g1;
		g1.buildGraph(inFile); // test build graph
		if (inFile.eof())
			break;
		g1.findShortestPath(); //findShortestPath
		g1.displayAll(); //test display all
		g1.display(1, 4); //test display
		cout << endl;
		g1.display(1, 5);
		cout << "\n\n" << endl;

		g1.insertEdge(1, 4, 1); //test insertEdge
		g1.insertEdge(1, 5, 1);//test insertEdge by overriding existing
		g1.findShortestPath();
		g1.displayAll();
		cout << "\n\n" << endl;
		g1.removeEdge(1, 4); // test removeEdge, reverts back to previous shortest path
		g1.removeEdge(1, 5); // removes override, leaving now edge at all
		g1.findShortestPath();
		g1.displayAll();
	}

	// part 2 
	ifstream infile2("data32.txt");
	if (!infile2) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	//for each graph, find the depth-first search ordering
	for (;;) {
		GraphL G;
		G.buildGraph(infile2);
		if (infile2.eof())
			break;
		G.printGNodeData();
	//	G.traceEdges();
	}

	cout << endl;

	return 0;
}