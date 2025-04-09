#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to perform level-order traversal and count nodes at each level
void levelOrder(Node* root) {
    if (root == NULL) return;

    int level = 0;
    int count[100]; // Adjust size as needed
    Node** queue = (Node*)malloc(100 * sizeof(Node)); // Adjust size as needed
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int nodeCount = rear - front;
        count[level] = nodeCount;

        printf("Level %d: ", level);
        for (int i = 0; i < nodeCount; i++) {
            Node* node = queue[front++];
            printf("%d ", node->data);

            if (node->left != NULL) {
                queue[rear++] = node->left;
            }
            if (node->right != NULL) {
                queue[rear++] = node->right;
            }
        }
        printf("\n");
        level++;
    }

    printf("Total levels in the tree: %d\n", level);
    printf("Count of nodes at each level:\n");
    for (int i = 0; i < level; i++) {
        printf("Level %d: %d nodes\n", i, count[i]);
    }

    free(queue);
}

// Main function to demonstrate the BST
int main() {
    Node* root = NULL;
    
    // Insert nodes into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Perform level-order traversal
    levelOrder(root);

    return 0;
}
