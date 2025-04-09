#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node {
    char key[50];
    char value[50];
    struct Node* next;
} Node;

typedef struct HashTable {
    Node** table;
} HashTable;

// Function to create a new node
Node* createNode(const char* key, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->next = NULL;
    return newNode;
}

// Hash function
int hashFunction(const char* key) {
    int hash = 0;
    for (int i = 0; key[i] != '0'; i++) {
        hash += key[i];
    }
    return hash % TABLE_SIZE;
}

// Function to create a hash table
HashTable* createHashTable() {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    hashTable->table = (Node*)malloc(TABLE_SIZE * sizeof(Node));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

// Function to insert a key-value pair
void insert(HashTable* hashTable, const char* key, const char* value) {
    int index = hashFunction(key);
    Node* newNode = createNode(key, value);
    
    if (!hashTable->table[index]) {
        hashTable->table[index] = newNode;
    } else {
        Node* current = hashTable->table[index];
        while (current) {
            if (strcmp(current->key, key) == 0) {
                strcpy(current->value, value); // Update the value if the key already exists
                free(newNode);
                return;
            }
            if (!current->next) break;
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to delete a key
int deleteKey(HashTable* hashTable, const char* key) {
    int index = hashFunction(key);
    Node* current = hashTable->table[index];
    Node* prev = NULL;

    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                hashTable->table[index] = current->next;
            }
            free(current);
            return 1; // Success
        }
        prev = current;
        current = current->next;
    }
    return 0; // Key not found
}

// Function to search for a key
const char* search(HashTable* hashTable, const char* key) {
    int index = hashFunction(key);
    Node* current = hashTable->table[index];

    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL; // Key not found
}

// Function to display the hash table
void display(HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* current = hashTable->table[i];
        while (current) {
            printf("(%s: %s) -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Main function with menu
int main() {
    HashTable* hashTable = createHashTable();
    int choice;
    char key[50], value[50];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display Hash Table\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter value: ");
                scanf("%s", value);
                insert(hashTable, key, value);
                printf("Inserted (%s: %s)\n", key, value);
                break;
case 2:
                printf("Enter key to delete: ");
                scanf("%s", key);
                if (deleteKey(hashTable, key)) {
                    printf("Deleted key: %s\n", key);
                } else {
                    printf("Key %s not found.\n", key);
                }
                break;

            case 3:
                printf("Enter key to search: ");
                scanf("%s", key);
                const char* result = search(hashTable, key);
                if (result != NULL) {
                    printf("Found: (%s: %s)\n", key, result);
                } else {
                    printf("Key %s not found.\n", key);
                }
                break;

           
            case 4:
                printf("Hash Table Contents:\n");
                display(hashTable);
                break;

            case 5:
                printf("Exiting...\n");
                free(hashTable->table);
                free(hashTable);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
