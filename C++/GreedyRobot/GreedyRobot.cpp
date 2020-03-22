#include<iostream>
#include<string>
#include<math.h>

using namespace std;

//prototypes
void findPaths(string path, int xRobot, int yRobot,const int &xTreasure,const int &yTreasure, int movesLeft, int &totalPaths);

int main()
{
	//variables for main
	string path = "";
	int movesLeft = 0;
	int xRobot = 0;
	int yRobot = 0;
	int xTreasure = 0;
	int yTreasure = 0;
	int totalPaths = 0;

	//user instructions
	cout << "Please enter four integers for the coordinates of the robot and treasure." << endl;

	//take input for coordinates
	cin >> xRobot;
	cin >> yRobot;
	cin >> xTreasure;
	cin >> yTreasure;

	//calculate the shortest path number of moves
	movesLeft = abs(xRobot - xTreasure) + abs(yRobot - yTreasure);

	//call to find and print paths and number of paths
	findPaths(path, xRobot, yRobot, xTreasure, yTreasure, movesLeft, totalPaths);

	//number of paths found
	cout << "Number of Paths: " << totalPaths << endl;

	return 0;
}

//recursive function to print all unique shortest paths between robot and treasure and keep count of paths
void findPaths(string path, int xRobot, int yRobot, const int &xTreasure,const int &yTreasure, int movesLeft, int &totalPaths)
{
	//base case: repeated moves
	if (path.length() >= 3 && path[path.length() - 1] == path[path.length() - 2] && path[path.length() - 2] == path[path.length() - 3])
	{
	return;
	}

	//base case: not shortest path
	else if (movesLeft < 0)
	{
		return;
	}

	//base case: path found
	else if (xRobot == xTreasure && yRobot == yTreasure)
	{
		totalPaths++;
		cout << path << endl;
	}

	//recursive case
	else
	{
		findPaths(path + "N", xRobot, yRobot + 1, xTreasure, yTreasure, movesLeft - 1, totalPaths);
		findPaths(path + "E", xRobot + 1, yRobot, xTreasure, yTreasure, movesLeft - 1, totalPaths);
		findPaths(path + "S", xRobot, yRobot - 1, xTreasure, yTreasure, movesLeft - 1 , totalPaths);
		findPaths(path + "W", xRobot - 1, yRobot, xTreasure, yTreasure, movesLeft - 1, totalPaths);
	}
}