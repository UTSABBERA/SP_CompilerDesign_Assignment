//Hashing Implementation
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct DataItem {
   int data;   
   int key;
};

struct DataItem* hashArray[SIZE];

int hashCode(int key) {
    return key % SIZE;
}

struct DataItem* search(int key) {
    int hashIndex = hashCode(key); 
    while(hashArray[hashIndex] != NULL) {
        if(hashArray[hashIndex]->key == key) return hashArray[hashIndex]; 
        hashIndex = (hashIndex+1)%SIZE;
    }        
    return NULL;        
}

void insert(int key,int data) {
    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item->data = data;  
    item->key = key;
    int hashIndex = hashCode(key);
    while(hashArray[hashIndex] != NULL) hashIndex = (hashIndex+1)%SIZE;
    hashArray[hashIndex] = item;
}

struct DataItem* delete(struct DataItem* item) {
   int key = item->key;
   int hashIndex = hashCode(key);
    while(hashArray[hashIndex] != NULL) {
        if(hashArray[hashIndex]->key == key) {
            struct DataItem* temp = hashArray[hashIndex]; 
            hashArray[hashIndex] = NULL; 
            return temp;
        }
        hashIndex = (hashIndex+1)%SIZE;
   }
   return NULL;        
}

void display() {
    int i = 0;
    for(i = 0; i<SIZE; i++) {
        if(hashArray[i] != NULL) printf(" (%d, %d)", hashArray[i]->key, hashArray[i]->data);
        else printf(" --");
    } 
    printf("\n");
}

int main() {
    insert(31, 20);
    insert(12, 70);
    insert(28, 80);
    insert(4, 25);

    display();

    struct DataItem* item = search(4);

    if(item != NULL) printf("Element found: %d\n", item->data);
    else printf("Element not found\n");

    delete(item);
    item = search(4);

    if(item != NULL) printf("Element found: %d\n", item->data);
    else printf("Element not found\n");

    return 0;
}