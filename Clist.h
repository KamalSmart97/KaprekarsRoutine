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
    node* lastCreatedNode , * newNode , * CurrenPos;

public:
    CList()
    {
        lastCreatedNode = NULL;
        newNode = NULL;
        CurrenPos = NULL;
        head = new node;
    }
    void insertNext(unsigned long long int data);
    int count() { return m_count; }
    node* next();
    void reset() {
        CurrenPos = head;
    }
    void removeAll();
    ~CList()
    {

    }

    void reverseList();

};


