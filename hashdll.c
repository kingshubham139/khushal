#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Node structure for doubly linked list
typedef struct Node {
    int key;
    struct Node* next;
    struct Node* prev;
} Node;

// Hash table structure
typedef struct HashTable {
    Node* table[TABLE_SIZE];
} HashTable;

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Initialize hash table
HashTable* createHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

// Insert key into the hash table
void insert(HashTable* ht, int key) {
    int index = hash(key);
    Node* newNode = createNode(key);
    
    // Insert at the head of the doubly linked list
    if (ht->table[index] == NULL) {
        ht->table[index] = newNode;
    } else {
        newNode->next = ht->table[index];
        ht->table[index]->prev = newNode;
        ht->table[index] = newNode;
    }
}

// Search for a key in the hash table
Node* search(HashTable* ht, int key) {
    int index = hash(key);
    Node* current = ht->table[index];
    
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    
    return NULL; // Not found
}

// Delete a key from the hash table
void deleteKey(HashTable* ht, int key) {
    int index = hash(key);
    Node* current = ht->table[index];
    
    while (current != NULL) {
        if (current->key == key) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                ht->table[index] = current->next; // Update head
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            printf("Key %d deleted.\n", key);
            return;
        }
        current = current->next;
    }
    
    printf("Key %d not found.\n", key);
}

// Display the hash table
void display(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* current = ht->table[i];
        while (current != NULL) {
            printf("%d <-> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Main function with menu-driven interface
int main() {
    HashTable* ht = createHashTable();
    int choice, key;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(ht, key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                Node* result = search(ht, key);
                if (result) {
                    printf("Key %d found.\n", result->key);
                } else {
                    printf("Key %d not found.\n", key);
                }
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(ht, key);
                break;
            case 4:
                display(ht);
                break;
            case 5:
printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    // Free memory
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = ht->table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht);

    return 0;
}
