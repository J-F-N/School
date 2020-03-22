#include "graphm.h"
#include <fstream>
#include <cstdlib>
#include<limits.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<sstream>

using std::stringstream;
using std::left;
using std::setw;
using std::ifstream;

#define MAXNODES 100

//---------------GraphM---------------
GraphM::GraphM()
{
	this->size = 0;

	//initialize member T data fields
	for (int i = 0; i < MAXNODES; i++)
	{
		for (int j = 0; j < MAXNODES; j++)
		{
			this->T[i][j].dist = 0;
			this->T[i][j].path = 0;
			this->T[i][j].visited = false;
		}
	}

	//initialize member C data fields
	for (int i = 0; i < MAXNODES; i++)
	{
		for (int j = 0; j < MAXNODES; j++)
		{
			this->C[i][j] = 0;
		}
	}
}

//---------------~GraphM---------------
//no dynamic memory allocated, destructor is default
GraphM::~GraphM()
{
}

//---------------buildGraph()---------------
void GraphM::buildGraph(ifstream& inFile)
{
		int weightFrom = 1, weightTo = 0;

		inFile >> this->size;
		inFile.ignore(2);	//skip ' ' && '/n' token

		if (inFile.eof())
		{
			return;
		}

		//fill data array
		for (int i = 1; i <= this->size; i++)
		{
			this->data[i].setData(inFile);
		}

		//fill C array
		while (weightFrom != 0)
		{
			inFile >> weightFrom >> weightTo;
			inFile >> this->C[weightFrom][weightTo];
			inFile.ignore();	//skip /n token
		}
}

void GraphM::findShortestPath()
{
	//reset T values
	for (int i = 0; i < MAXNODES; i++)
	{
		for (int j = 0; j < MAXNODES; j++)
		{
			this->T[i][j].dist = 0;
			this->T[i][j].path = 0;
			this->T[i][j].visited = false;
		}
	}

	for (int origin = 1; origin <= size; origin++)
	{
		T[origin][origin].visited = true; //visit origin of shortest path.
		//cout << origin << " is visited" << endl;
		
		//initialize adjacent nodes of origin.
		for (int v = 1; v <= size; v++)
		{
			if (v != origin && C[origin][v] != 0)
			{
				T[origin][v].dist = C[origin][v];
				T[origin][v].path = origin;
				//cout << origin << " to " << v << " is set to: " << C[origin][v] << endl;
				//cout << "path is " << origin << endl;
			}
		}

		//number of runs throught the algorithm should not be greater than the number of nodes.
		//each node gets visited once.
		for (int count = 1; count < size; count++)
		{
			//cout << "count = " << count << endl;

			int smallWeight = INT_MAX; //resets to max each time, so a new min can be found.
			int smallV = 0;			   //index of the smallest vertex.

			//cout << "small reset" << endl;


			//search through all unvisited nodes for new min.
			for (int v = 1; v <= size; v++)
			{
				if (v != origin && T[origin][v].visited == false && 
					T[origin][v].dist > 0 && T[origin][v].dist < smallWeight)
				{
					smallV = v;
					smallWeight = T[origin][smallV].dist;
				}
			}

			//since smallV holds 0 from initialization
			//we must handle the case where smallV is not chosen.
			if (smallV != 0)
			{

				T[origin][smallV].visited = true;					//visit the smallest node
				//cout << "visiting smallest: " << smallV << endl;

				//set weights for all unvisited adjacent vertices.
				//candidates must have adjacency with smallV (ie. weight > 0).
				//only set new weight if weight from origin is greater than
				//weight from smallV + weight from origin to smallV
				for (int u = 1; u <= size; u++)
				{
					if (T[origin][u].visited == false && u != smallV && C[smallV][u] > 0)
					{
						if (T[origin][u].dist > T[origin][smallV].dist + C[smallV][u] ||
							T[origin][u].dist == 0)
						{
							T[origin][u].dist = T[origin][smallV].dist + C[smallV][u];
							T[origin][u].path = smallV;
							//cout << origin << " to " << u << " is set to: " << T[origin][smallV].dist + C[smallV][u] << endl;
							//cout << u << " path from set to: " << smallV << endl;
						}
					}
				}
			}
		}
	}
}

string GraphM::path(int origin, int destination)
{
	string route = to_string(destination);
	int current = destination;

	while (current != origin)
	{
		route += " " + to_string(this->T[origin][current].path);
		current = T[origin][current].path;
	}

	reverse(route.begin(), route.end());

	return route;
}

void GraphM::displayAll()
{

	cout << " ________________________________________________________________________________" << endl;
	cout << "|                      |               |             |                |          |" << endl;
	cout << "| Description          | From_node     | To_node     | Dijkstra's     | Path     |" << endl;
	cout << "|______________________|_______________|_____________|________________|__________|" << endl;

	for (int i = 1; i <= size; i++)
	{
		cout << endl;
		cout << data[i] << endl;
		cout << endl;
		
		for (int j = 1; j <= size; j++)
		{
			if (i != j)
			{
				if (T[i][j].dist != 0)
				{
					cout << "__________________________________________________________________________________" << endl;
					cout << "|                      |               |             |                |          |" << endl;
					cout << "|                      | " << setw(14) << left << i << "| " << setw(12) << left << j << "| " << setw(15) << left << T[i][j].dist << "| " << setw(9) << left << path(i, j) << "|" << endl;
					cout << "|______________________|_______________|_____________|________________|__________|" << endl;
				}

				else
				{
					cout << "__________________________________________________________________________________" << endl;
					cout << "|                      |               |             |                |          |" << endl;
					cout << "|                      | " << setw(14) << left << i << "| " << setw(12) << left << j << "|      INF       " << "|          |" << endl;
					cout << "|______________________|_______________|_____________|________________|__________|" << endl;
				}
			}
		}
	}
}

bool GraphM::insertEdge(int origin, int destination, int weight)
{
	if (origin > size || destination > size)
	{
		return false;
	}

	C[origin][destination] = weight;
	return true;
}

bool GraphM::removeEdge(int origin, int destination)
{
	if (origin > size || destination > size)
	{
		return false;
	}

	C[origin][destination] = 0;
	return true;
}

void GraphM::display(int origin, int destination)
{
	string route = "";
	if (origin < size && destination < size && T[origin][destination].dist != 0)
	{
		int current = destination;

		cout << origin << "    " << destination << "     " << T[origin][destination].dist << "     " << path(origin, destination) << "\n" << endl;

		while (current != origin)
		{
			stringstream ss;
			ss << data[current];
			route = ss.str() + "\n" + route;

			current = T[origin][current].path;
		}

		stringstream ss;
		ss << data[current];
		route = ss.str() + "\n" + route;
	}

	cout << route << endl;
}