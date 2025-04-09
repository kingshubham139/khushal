#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int key;
    int data;
    struct Node* next;
};

struct Node* hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key, int data) {
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->data = data;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        struct Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main() {
    insert(10, 100);
    insert(25, 250);
    insert(17, 170);

    // Accessing the hash table
    int index = hashFunction(25);
    struct Node* temp = hashTable[index];
    while (temp != NULL) {
        printf("Key: %d, Data: %d\n", temp->key, temp->data);
        temp = temp->next;
    }

    return 0;
}
