#include<iostream>
using namespace std;
//order 1 is ascending
//order 2 is descending
unsigned long long int ArrangeInOrder(unsigned long long int nNumber, unsigned long long int* pAsceding, unsigned long long int* pDescending)
{
	int temp = 0;
	int arr[10] = { 0 };
	unsigned long long int nArrangedNumber = 0, nAsceding = 0, nDescending=0;

	while (nNumber > 0)
	{
		temp = nNumber % 10;
		arr[temp] = arr[temp] + 1;
		nNumber = nNumber / 10;
	}

	if (pAsceding)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < arr[i]; j++)
				(nAsceding) = (nAsceding) * 10 + i;
		}
		*pAsceding = nAsceding;
	}
	if (pDescending)
	{
		for (int i = 9; i >= 0; i--)
		{
			for (int j = 0; j < arr[i]; j++)
				(nDescending) = (nDescending) * 10 + i;
		}
		*pDescending = nDescending;
	}
	return 0;
}

int main()
{
	unsigned long long int nNumber = 0, nAscending = 0, nDescedning = 0;
	cout << "enter the number";
	cin >> nNumber;
	ArrangeInOrder(nNumber, &nAscending, &nDescedning);

	cout << "\n ascending order" << nAscending;
	cout << "\n Descedning order" << nDescedning;
	return 0;
}