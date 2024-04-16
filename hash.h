#pragma once

#include"CList.h"

#define CAPACITY 1000003

class  hashMap {

    // Current number of elements in hashMap
    // and capacity of hashMap
    unsigned long int numOfElements, capacity;

    // hold base address array of linked list
    struct CList** arr;

    hashMap()
    {
        // Default capacity in this case
        capacity = CAPACITY;
        numOfElements = 0;

        // array of size = 1
        arr = (struct CList**)malloc(sizeof(struct CList*) * capacity);
    }

    int search(unsigned long long int number);
    int deleteHashMap();
    int insert( unsigned long long int number);
    unsigned long int hashFunction(unsigned long long int number);
};
