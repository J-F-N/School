/*John Neigel
04/24/2019
CSS342 Lab02
Description: This is a standalone driver function to calculate
the Catalan number located at the numeric position passed in. The chosen integer will
be entered in the command line upon execution.
*/

#include<iostream>
using namespace std;

//function prototypes
int calcCatalan(int n);

int main(int argc, const char *argv[])
{
	int n = atoi(argv[1]);
	int catalanNum = calcCatalan(n);
	cout << catalanNum << endl;

	return 0;
}

//recursive function to determine the Catalan value found at the numeric postion passed in
int calcCatalan(int n)
{
	if (n == 0)
	{
		return 1;
	}

	else
	{
		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			sum += calcCatalan(i) * calcCatalan(n - i - 1);
		}
		return sum;
	}
}