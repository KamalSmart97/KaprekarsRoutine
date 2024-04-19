#define _CRT_SECURE_NO_WARNINGS
#include"hash.h"
//order 1 is ascending
//order 2 is descending
unsigned long long int ArrangeInOrder(unsigned long long int nNumber, unsigned long long int* pAsceding, unsigned long long int* pDescending, int nNoOfDigits)
{
	int temp = 0, nCount = 0;
	int arr[10] = { 0 };
	unsigned long long int nArrangedNumber = 0llu, nAsceding = 0llu, nDescending=0llu;

	while (nNumber > 0)
	{
		temp = nNumber % 10;
		arr[temp] = arr[temp] + 1;
		nNumber = nNumber / 10;
		nCount++;
	}
	if (nCount < nNoOfDigits)
		arr[0] += (nNoOfDigits - nCount);

	if (pAsceding)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < arr[i]; j++)
				(nAsceding) = (nAsceding) * 10llu + (unsigned long long int)i;
		}
		*pAsceding = nAsceding;
	}
	if (pDescending)
	{
		for (int i = 9; i >= 0; i--)
		{
			for (int j = 0; j < arr[i]; j++)
				(nDescending) = (nDescending) * 10llu + (unsigned long long int)i;
		}
		*pDescending = nDescending;
	}
	return 0;
}

int main()
{
	unsigned long long int nNumber = 0llu, nAscending = 0llu, nDescedning = 0llu;
	FILE* fp = NULL;
	fp = fopen("D:/testSamples/instance1.txt", "w+");

	for (unsigned long long int nNumber = 1000llu; nNumber < 10000llu; nNumber++)
	{
		hashMap hash;
		unsigned long long int temp = nNumber;
		fprintf(fp, "\n Number: %llu \n", nNumber);
		while (hash.insert(temp))
		{
			ArrangeInOrder(temp, &nAscending, &nDescedning,4);
			temp = nDescedning - nAscending;
			fprintf(fp, "%llu ->", temp);
		}
		fprintf(fp,"\n", &temp);
		cout << " \n the kaprekars constant for nNumber" << temp;
	}
	if (fp)
		fclose(fp);

	return 0;
}