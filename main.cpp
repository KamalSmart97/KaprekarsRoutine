#define _CRT_SECURE_NO_WARNINGS
#include"hash.h"

#include <thread>
#include <stdio.h>
#include<iostream>
#include <stdlib.h>

#define NO_OF_DIGITS 6

using namespace std;


//order 1 is ascending
//order 2 is descending
unsigned long long int ArrangeInOrder(unsigned long long int nNumber, unsigned long long int* pAsceding, unsigned long long int* pDescending, int nNoOfDigits)
{
	int temp = 0, nCount = 0;
	int arr[10] = { 0 };
	unsigned long long int nArrangedNumber = 0llu, nAsceding = 0llu, nDescending = 0llu;

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

void kaprekarCycle(unsigned long long int nStartValue, unsigned long long int nEndValue, string fileName)
{
	unsigned long long int nNumber = 0llu, nAscending = 0llu, nDescedning = 0llu, ntemp = 0llu;
	bool bNewCycle = false;
	FILE* fp = NULL;
	const char* myCharPtr = fileName.c_str();
	fp = fopen(myCharPtr, "w+");
	hashMap actualCyclehash;

	for (unsigned long long int nNumber = nStartValue; nNumber < nEndValue; nNumber++)
	{
		hashMap temphash;
		bNewCycle = true;
		ntemp = nNumber;
		while (temphash.insert(ntemp))
		{
			if (actualCyclehash.search(ntemp))
			{
				bNewCycle = false;
				break;
			}
			ArrangeInOrder(ntemp, &nAscending, &nDescedning, NO_OF_DIGITS);
			ntemp = nDescedning - nAscending;
		}
		if ((ntemp > 0) && bNewCycle)
		{
			fprintf(fp, "\n Number: %llu \n", nNumber);
			while (actualCyclehash.insert(ntemp))
			{
				ArrangeInOrder(ntemp, &nAscending, &nDescedning, NO_OF_DIGITS);
				ntemp = nDescedning - nAscending;
				fprintf(fp, "%llu ->", ntemp);
			}
			fprintf(fp, "\n", &ntemp);
		}
	}
	if (fp)
		fclose(fp);

	return;
}

int main() {
	const int NUM_THREADS = 20; // Number of threads to create
	thread threads[NUM_THREADS];
	string fileNames[NUM_THREADS] = { "D:/project/kaprekarsroutine/sampleFIle/output1.txt", "D:/project/kaprekarsroutine/sampleFIle/output2.txt", "D:/project/kaprekarsroutine/sampleFIle/output3.txt", "D:/project/kaprekarsroutine/sampleFIle/output4.txt","D:/project/kaprekarsroutine/sampleFIle/output5.txt","D:/project/kaprekarsroutine/sampleFIle/output6.txt","D:/project/kaprekarsroutine/sampleFIle/output7.txt","D:/project/kaprekarsroutine/sampleFIle/output8.txt","D:/project/kaprekarsroutine/sampleFIle/output9.txt","D:/project/kaprekarsroutine/sampleFIle/output10.txt","D:/project/kaprekarsroutine/sampleFIle/output11.txt","D:/project/kaprekarsroutine/sampleFIle/output12.txt", "D:/project/kaprekarsroutine/sampleFIle/output13.txt", "D:/project/kaprekarsroutine/sampleFIle/output14.txt", "D:/project/kaprekarsroutine/sampleFIle/output15.txt", "D:/project/kaprekarsroutine/sampleFIle/output16.txt", "D:/project/kaprekarsroutine/sampleFIle/output17.txt", "D:/project/kaprekarsroutine/sampleFIle/output18.txt", "D:/project/kaprekarsroutine/sampleFIle/output19.txt","D:/project/kaprekarsroutine/sampleFIle/output20.txt" };
	unsigned long long int nStart = 0, nEnd = 0;
	// Assuming you want to process numbers from 1 to 1000000
	unsigned long long int range = 1000000 / NUM_THREADS;
	for (int i = 0; i < NUM_THREADS; i++) {
		nStart = i * range + 1;
		nEnd = (i + 1) * range;
		threads[i] = thread(kaprekarCycle, ref(nStart), ref(nEnd), ref(fileNames[i]));
	}

	// Wait for all threads to finish
	for (int i = 0; i < NUM_THREADS; i++) {
		threads[i].join();
	}

	printf("Kaprekar cycles computation completed.\n");
	return 0;
}
