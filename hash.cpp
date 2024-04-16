#include"CList.h"
#include"hash.h"

#define CAPACITY 1000003


 unsigned long int hashMap::hashFunction(unsigned long long int number)
{
    unsigned long int bucketIndex;

    bucketIndex = number % CAPACITY;
    return bucketIndex;
}


int hashMap::search(unsigned long long int number)
 {

     // Getting the bucket index
     // for the given key
     int bucketIndex = hashFunction(number);

     // Head of the linked list
     // present at bucket index
     CList * bucketList = arr[bucketIndex];
     node* tempNode = NULL;

     bucketList->reset();
     while ((tempNode=bucketList->next()) != NULL) {
         // Key is found in the hashMap
         if (tempNode->value == number) 
             return 1;   
     }
     return 0;
 }

int hashMap::insert(unsigned long long int number)
 {

     // Getting bucket index for the given
     int bucketIndex = hashFunction(number);
     numOfElements++;

     // Bucket index is empty....no collision
     if (arr[bucketIndex] == NULL) {
         CList list;
         arr[bucketIndex] = &list;
         arr[bucketIndex]->insertNext(number);
     }
     // Collision
     else {

         if (!search(number))
             arr[bucketIndex]->insertNext(number);
         else
             return 0;
     }
     return 1;
 }

int hashMap::deleteHashMap()
 {
     for (unsigned long int i = 0; i < CAPACITY; i++)
     {
         if (arr[i])
         {
             arr[i]->removeAll();
             free(arr[i]);
         }
     }
     if (arr)
         free(arr);
 }