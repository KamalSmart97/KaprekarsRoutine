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

void CList::insertNext(unsigned long long int data)
{
    m_count++;
    newNode = (node*)malloc(sizeof(struct node));
    newNode->link = NULL;
    if (!lastCreatedNode)
        head->link = newNode;
    else
        lastCreatedNode->link = newNode;

    newNode->value = data;
    lastCreatedNode = newNode;
}

node * CList::next()
{
    node* tempNode = NULL;
    tempNode = CurrenPos->link;
    CurrenPos = tempNode;
    return tempNode;
}

void CList::removeAll()
{
    node* tempNode = NULL;
    reset();
    while ((tempNode = next()) != NULL)
    {
        head->link = tempNode->link;
        free(tempNode);
    }
}

void CList::reverseList()
{
    node* next;
    node* current = head->link;
    node* previous = NULL;
    while (current != NULL)
    {
        next = current->link;
        current->link = previous;
        previous = current;
        current = next;
    }
    head->link = previous;
}