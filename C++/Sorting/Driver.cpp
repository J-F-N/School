#include <iostream>
#include <vector>
#include <string>
#include "SortImpls.h"

//fuction prototypes
void InitArray(vector<int>& array, int randMax);
void PrintArrayDetails(const vector<int>& array, string name);

int main()
{
	//insertion sort
	cout << "InsertionSort:" << endl;
	vector<int> items(10);
	InitArray(items, 10);
	PrintArrayDetails(items, string("item"));
	InsertionSort(items, 0, 10 - 1);
	PrintArrayDetails(items, string("item"));
	
	cout << endl;
	cout << endl;
	cout << endl;
	
	//bubblesort
	cout << "BubbleSort:" << endl;
	vector<int> items2(10);
	InitArray(items2, 10);
	PrintArrayDetails(items2, string("item"));
	BubbleSort(items2, 0, 10 - 1);
	PrintArrayDetails(items2, string("item"));

	cout << endl;
	cout << endl;
	cout << endl;

	//QuickSort
	cout << "QuickSort" << endl;
	vector<int> items3(10);
	InitArray(items3, 10);
	PrintArrayDetails(items3, string("item"));
	BubbleSort(items3, 0, 10 - 1);
	PrintArrayDetails(items3, string("item"));

	cout << endl;
	cout << endl;
	cout << endl;

	//QuickSort
	cout << "MergeSort" << endl;
	vector<int> items4(10);
	InitArray(items4, 10);
	PrintArrayDetails(items4, string("item"));
	MergeSort(items4, 0, 10 - 1);
	PrintArrayDetails(items4, string("item"));
}

void InitArray(vector<int>& array, int randMax)
{
	if (randMax < 0)
	{
		return;
	}
	vector<int> pool(randMax);
	for (int i = 0; i < randMax; i++)
	{
		pool[i] = i;
	}
	int spot;
	for (int i = 0; i < randMax; i++)
	{
		spot = rand() % (pool.size());
		array[i] = pool[spot];
		pool.erase(pool.begin() + spot);
	}
}

void PrintArrayDetails(const vector<int>& array, string name)
{
	int size = array.size();
	for (int i = 0; i < size; i++)
		cout << name << "[" << i << "] = " << array[i] << endl;
}