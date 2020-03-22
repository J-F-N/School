/*
Purpose: Implementation file for sort functions.
Creation Date: 05/22/2019
Author: John Neigel
*/

#pragma once
#include<vector>
#include<string>
using namespace std;

//todo
void QuickSort(vector<int>& items, int first, int last)
{
	//prototypes for scope issues
	void InsertionSort(vector<int> & items, int first, int end);
	int partition(vector<int> & items, int first, int last);

	if (last < 4) // array too small for pivot location
	{
		InsertionSort(items, first, last);
	}

	else // recursive case
	{
		int pivotIndex = partition(items, first, last);

		QuickSort(items, first, pivotIndex - 1);
		QuickSort(items, pivotIndex + 1, last);
	}
}//end QuickSort

void BubbleSort(vector<int>& items, int first, int size)
{
	bool swap = true;
	int pass = 1;
	while (swap)
	{
		swap = false;

		for (int i = first; i <= (size - pass); i++)
		{
			if (items[i] > items[i + 1])
			{
				int temp = items[i + 1];
				items[i + 1] = items[i];
				items[i] = temp;
				swap = true;
			}
		}
		pass++;
	}
}//end BubbleSort

void InsertionSort(vector<int>& items, int first, int end)
{
	int temp = 0;

	if (end > 0) //if more than one value in array
	{
		for (int i = first + 1; i <= end; i++)
		{
			temp = items[i];

			for (int j = i; j > 0 && items[j - 1] > temp; j--)
			{
				items[j] = items[j - 1];
				items[j - 1] = temp;
			}
		}
	}
}//end InsertionSort

void MergeSort(vector<int> &items, int first, int last)
{
	//prototype for scope issues
	void merge(vector<int> &items, int first, int mid, int last);

   	if (first < last)
	{
		int mid = (first + last) / 2;

		//recursive breakdown of array
		MergeSort(items, first, mid);
		MergeSort(items, mid + 1, last);
		
		//merge into sorted array
		merge(items, first, mid, last);
	}
}//end MergeSort

//For use in QuickSort.
//Finds the appropriate pivot value by taking a median of three and petitions the array.
int partition(vector<int>& items, int first, int last)
{
	if (items[first] > items[last / 2])
	{
		int temp = items[last / 2];
		items[last / 2] = items[first];
		items[first] = temp;
	}

	if (items[last / 2] > items[last])
	{
		int temp = items[last];
		items[last] = items[last / 2];
		items[last / 2] = temp;
	}

	if (items[first] > items[last / 2])
	{
		int temp = items[last / 2];
		items[last / 2] = items[first];
		items[first] = temp;
	}

	//assign and position pivot
	int pivot = items[last / 2];
	int temp = items[last - 1];
	items[last - 1] = pivot;
	items[last / 2] = temp;

	int leftIndex = first + 1;
	int rightIndex = last - 2;
	bool complete = false;

	while (!complete)
	{
		while (items[leftIndex] < pivot)
		{
			leftIndex++;
		}

		while (items[rightIndex] > pivot)
		{
			rightIndex--;
		}

		if (leftIndex < rightIndex)
		{
			int temp = items[leftIndex];
			items[leftIndex] = items[rightIndex];
			items[rightIndex] = temp;
		}

		else
		{
			complete = true;
		}

		int temp = items[last - 1];
		items[last - 1] = items[leftIndex];
		items[leftIndex] = temp;

		return leftIndex;
	}
}//end partition

void merge(vector<int> &items, int first, int mid, int last)
{
	//array for use in merging
	vector<int> tempArray;

	//variables to identify bounds of subarrays
	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;

	//next spot available in temp array
	int index = first;

	while ((first1 <= last1) && (first2 <= last2))
	{
		if (items[first1] <= items[first2])
		{
			tempArray[index] = items[first1];
			first1++;
		}

		else
		{
			tempArray[index] = items[first2];
			first2++;
		}
		index++;
	}

	while (first1 <= last1)
	{
		tempArray[index] = items[first1];
		first1++;
		index++;
	}

	while (first2 <= last2)
	{
		tempArray[index] = items[first2];
		first2++;
		index++;
	}

	//copy sorted result to original array
	for (index = first; first <= last; index++)
	{
		items[index] = tempArray[index];
	}
}//end merge