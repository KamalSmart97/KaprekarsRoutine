#include"CList.h"

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

node* CList::next()
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