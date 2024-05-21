#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}


void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


int main() {
    struct Node* root = NULL;
    printf("enter root element\n");
    int rootele,n;
    scanf("%d",&rootele);
    printf("enter no of other elements to insert\n");
    scanf("%d",&n);
    root = insert(root, rootele);
    printf("enter other elements\n");
    int i,ele;
    for(i=0;i<n;i++){
        scanf("%d",&ele);
    insert(root, ele);
   
                    }
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    
    printf("enter element to delete");
    int delvalue;
    scanf("%d",&delvalue);
    root = deleteNode(root, delvalue);
    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

