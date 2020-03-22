#pragma once
#include"nodedata.h"
#include<fstream>
#include<string>
#include <array>
#define MAX_G_NODES 101
using std::ifstream;

using std::string;

class GraphL
{

public:

	GraphL();
	~GraphL();
	void buildGraph(ifstream& inFile);
	void displayGraph();
	void depthFirstSearch();
	void printGNodeData(); //tester
	void traceEdges(); // tester

private:

	struct EdgeNode {

		int adjGraphNode;  // subscript of the adjacent graph node

		EdgeNode* nextEdge;

	};

	struct GraphNode {    // structs used for simplicity, use classes if desired

		EdgeNode* edgeHead; // head of the list of edges

		NodeData* data;     // data information about each node

		bool visited;

	};

	int size;
	GraphNode nodeArray[MAX_G_NODES];
};