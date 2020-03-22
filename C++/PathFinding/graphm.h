#include "nodedata.h"
#include <array>
#include<fstream>

#pragma once
#define MAXNODES 100
#include<string>
using std::ifstream;

using std::string;

class GraphM
{
public:

	GraphM();							//constructor
	~GraphM();							//deconstructor
	void buildGraph(ifstream& inFile);
	void findShortestPath();
	void displayAll();
	bool insertEdge(int origin, int destination, int weight);
	bool removeEdge(int origin, int destination);
	string path(int origin, int destination);
	void printCArray();
	void printTArray();
	void display(int origin, int destination);

private:

	struct TableType {

		bool visited;	//whether a node has been visited

		int dist;		//shortest distance known so far

		int path;		//previous node in path of min distance
	};

	int size;							//number of nodes in the graph

	NodeData data[MAXNODES];			//data for graph nodes

	int C[MAXNODES][MAXNODES];			//cost array to represent adjacency matrix

	TableType T[MAXNODES][MAXNODES];	//stores visited, distance, and path
	
};