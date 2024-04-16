#pragma once
using namespace std;
#include<iostream>

// Linked List Node
struct node {
    unsigned long long int value;
    struct node* link;
    node()
    {
        value = 0;
        link = NULL;
    }
};

class CList
{

    node* head;
    int m_count = 0;
    node* lastCreatedNode = NULL, * newNode = NULL, * CurrenPos = NULL;

public:
    CList()
    {
        head = (node*)malloc(sizeof(struct node));
    }
    void insertNext(unsigned long long int data);
    int count() { return m_count; }
    node* next();
    void reset() {
        CurrenPos = head;
    }
    void removeAll();
    void reverseList();

};


