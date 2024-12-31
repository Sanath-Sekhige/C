#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *right, *left;
} Node;

typedef Node* NodePtr;

NodePtr createNode(int value) {
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    newNode->data = value;
    newNode->right = newNode->left = NULL;
    return newNode;
}

NodePtr insert(NodePtr root, int value) {
    if (!root) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        printf("Duplicate value %d not inserted.\n", value);
    }
    return root;
}

NodePtr search(NodePtr root, int value) {
    if (!root) {
        printf("Value %d not found in the tree.\n", value);
        return NULL;
    }
    if (value == root->data) {
        printf("Value %d found in the tree.\n", value);
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

NodePtr findMin(NodePtr root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

NodePtr delete(NodePtr root, int value) {
    if (!root) {
        printf("Value %d not found in the tree.\n", value);
        return root;
    }

    if (value < root->data) {
        root->left = delete(root->left, value);
    } else if (value > root->data) {
        root->right = delete(root->right, value);
    } else {
        if (!root->left) {
            NodePtr temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            NodePtr temp = root->left;
            free(root);
            return temp;
        }
        NodePtr temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void inorder(NodePtr root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(NodePtr root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NodePtr root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    NodePtr root = NULL;
    int choice, val;

    while (1) {
        printf("\nBST OPERATIONS\n");
        printf("1 ---> INSERT\n"
               "2 ---> DELETE\n"
               "3 ---> SEARCH\n"
               "4 ---> INORDER\n"
               "5 ---> PREORDER\n"
               "6 ---> POSTORDER\n"
               "7 ---> EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("\nEnter Data to Insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            }
            case 2: {
                printf("\nEnter Data to Delete: ");
                scanf("%d", &val);
                root = delete(root, val);
                printf("Value %d Deleted Successfully.\n", val);
                break;
            }
            case 3: {
                printf("\nEnter Data to Search: ");
                scanf("%d", &val);
                search(root, val);
                break;
            }
            case 4: {
                printf("\nInorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            }
            case 5: {
                printf("\nPreorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            }
            case 6: {
                printf("\nPostorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            }
            case 7: exit(0);
            default: printf("\nINVALID CHOICE\n");
        }
    }
    return 0;
}
