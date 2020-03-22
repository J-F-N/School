#include "GraphL.h"
#include <fstream>
#include <cstdlib>
#include<limits.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<sstream>

using std::to_string;
using std::cout;
using std::endl;
using std::stringstream;
using std::left;
using std::setw;
using std::ifstream;

#define MAXNODES 101

//----------tester functions----------
void GraphL::traceEdges()
{/*
	for (int i = 1; i <= size; i++)
	{
		EdgeNode* current = nodeArray[i].edgeHead;
		cout << i << " to ";
		while (current != nullptr)
		{
			cout << current->adjGraphNode << " to ";
			current = current->nextEdge;
		}
		cout << "NULL" << endl;
	}*/
}
void GraphL::printGNodeData()
{
	for (int i = 1; i <= size; i++)
		cout << *nodeArray[i].data << endl;
}
//---------------GraphM---------------
GraphL::GraphL()
{
	
}

//---------------~GraphM---------------
//no dynamic memory allocated, destructor is default
GraphL::~GraphL()
{

}

void GraphL::depthFirstSearch()
{
	if (!size)
	{
		return; //bad stuff
	}

	for (int c = 1; c <= size; ++size)
	{
		if (nodeArray[c].visited == false)
		{
			cout << "Depth first order: ";

			nodeArray[c].visited = true;

			cout << c;

			//depthFirstHelper(nodeArray[c].edgeHead);
		}

		cout << endl;
	}
}

void GraphL::buildGraph(ifstream& inFile)
{
	int from = 1;
	int to = 0;

	if (inFile.eof())
	{
		return;
	}

	inFile >> this->size;
	inFile.ignore(2);	//skip ' ' && '/n' token

	//fill GraphNode data
	for (int i = 1; i <= size; i++)
	{
		string str;
		getline(inFile, str);
		nodeArray[i].data = new NodeData(str);
	}
	
	while (from != 0) 
	{
		string next = "";
		getline(inFile, next);
		stringstream stream(next);
		stream >> from >> to;

		if (from > 0)
		{
			if (nodeArray[from].edgeHead == nullptr)
			{
				nodeArray[from].edgeHead = new EdgeNode();
				nodeArray[from].edgeHead->adjGraphNode = to;
			}

			else
			{
				EdgeNode *nextNode = new EdgeNode();
				nextNode->adjGraphNode = to;
				nextNode->nextEdge = nodeArray[from].edgeHead;
				nodeArray[from].edgeHead = nextNode;
			}
		}
	}
}