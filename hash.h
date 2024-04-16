#pragma once
#include"CList.h"

#define CAPACITY 1000003

class  hashMap {
public:
    // Current number of elements in hashMap
    // and capacity of hashMap
    unsigned long int numOfElements, capacity;

    // hold base address array of linked list
    CList** arr;

    hashMap()
    {
        // Default capacity in this case
        capacity = CAPACITY;
        numOfElements = 0;

        // array of size = 1
        //arr = (CList**)malloc(sizeof(CList*) * capacity);
        arr = new CList*[capacity];

        for (unsigned long int i = 0; i < capacity; i++)
            arr[i] = NULL;
    }

    int search(unsigned long long int number);
    int deleteHashMap();
    ~hashMap()
    {
        deleteHashMap();
    }
    int insert( unsigned long long int number);
    unsigned long int hashFunction(unsigned long long int number);
};

