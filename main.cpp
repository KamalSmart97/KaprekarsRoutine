#define _CRT_SECURE_NO_WARNINGS
#include"hash.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

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

int kaprekarCycle(unsigned long long int nStartValue, unsigned long long int nEndValue, char * fileName)
{
	unsigned long long int nNumber = 0llu, nAscending = 0llu, nDescedning = 0llu, ntemp = 0llu;
	bool bNewCycle = false;
	FILE* fp = NULL;
	fp = fopen(fileName, "w+");
	hashMap actualCyclehash;

	for (unsigned long long int nNumber = nStartValue; nNumber < nEndValue; nNumber++)
	{
3		hashMap temphash;
		bNewCycle = true;
		ntemp = nNumber;
		while (temphash.insert(ntemp))
		{
			if (actualCyclehash.search(ntemp))
			{
				bNewCycle = false;
				break;
			}
			ArrangeInOrder(ntemp, &nAscending, &nDescedning,11);
			ntemp = nDescedning - nAscending;
		}
		if ((ntemp > 0) && bNewCycle)
		{
			fprintf(fp, "\n Number: %llu \n", nNumber);
			while (actualCyclehash.insert(ntemp))
			{
				ArrangeInOrder(ntemp, &nAscending, &nDescedning, 11);
				ntemp = nDescedning - nAscending;
				fprintf(fp, "%llu ->", ntemp);
			}
			fprintf(fp,"\n", &ntemp);
		}
	}
	if (fp)
		fclose(fp);

	return 0;
}

// Define a structure to pass parameters to the threads
typedef struct {
	unsigned long long int start;
	unsigned long long int end;
	char* fileName;
} ThreadParams;

// The thread function that calls kaprekarCycle
void* threadFunction(void* arg) {
	ThreadParams* params = (ThreadParams*)arg;
	kaprekarCycle(params->start, params->end, params->fileName);
	return NULL;
}

int main() {
	const int NUM_THREADS = 4; // Number of threads to create
	pthread_t threads[NUM_THREADS];
	ThreadParams threadParams[NUM_THREADS];
	char* fileNames[NUM_THREADS] = { "output1.txt", "output2.txt", "output3.txt", "output4.txt" };

	// Assuming you want to process numbers from 1 to 1000000
	unsigned long long int range = 1000000 / NUM_THREADS;
	for (int i = 0; i < NUM_THREADS; i++) {
		threadParams[i].start = i * range + 1;
		threadParams[i].end = (i + 1) * range;
		threadParams[i].fileName = fileNames[i];

		if (pthread_create(&threads[i], NULL, threadFunction, &threadParams[i])) {
			fprintf(stderr, "Error creating thread\n");
			return 1;
		}
	}

	// Wait for all threads to finish
	for (int i = 0; i < NUM_THREADS; i++) {
		if (pthread_join(threads[i], NULL)) {
			fprintf(stderr, "Error joining thread\n");
			return 2;
		}
	}

	printf("Kaprekar cycles computation completed.\n");
	return 0;
}