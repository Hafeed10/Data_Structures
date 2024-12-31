#include <stdio.h>
#include <stdlib.h>
// Structure for a node in the binary search tree
struct Node
{
    int key;
    struct Node *left, *right;
};
// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to insert a new key in the BST
struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }
    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to search for a key in the BST
int search(struct Node *root, int key)
{
    if (root == NULL)
    {
        return 0; // Key not found
    }
    if (root->key == key)
    {
        return 1; // Key found
    }
    if (key < root->key)
    {
        return search(root->left, key); // Search in the left subtree
    }
    return search(root->right, key); // Search in the right subtree
}

// In-order traversal (to display the BST elements in sorted order)
void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->key);
        inOrderTraversal(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, value, key;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Search for a key\n");
        printf("3. Display (In-order Traversal)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;

        case 2:
            printf("Enter key to search: ");
            scanf("%d", &key);
            if (search(root, key))
            {
                printf("Key %d found in the BST.\n", key);
            }
            else
            {
                printf("Key %d not found in the BST.\n", key);
            }
            break;

        case 3:
            printf("BST elements (in sorted order): ");
            inOrderTraversal(root);
            printf("\n");
            break;

        case 4:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}