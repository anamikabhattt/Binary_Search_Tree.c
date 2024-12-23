#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, create a new node and return it
    if (root == NULL) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // Return the (unchanged) node pointer
    return root;
}


struct Node* search(struct Node* root, int key) {
  
    if (root == NULL || root->data == key) {
        return root;
    }

   
    if (key > root->data) {
        return search(root->right, key);
    }

    
    return search(root->left, key);
}


void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


int main() {
    struct Node* root = NULL;

    
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

  
    printf("In-order traversal: ");
    inorder(root);
    printf("\n");

   
    printf("Pre-order traversal: ");
    preorder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postorder(root);
    printf("\n");

    int key = 40;
    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("Node %d found in the BST.\n", key);
    } else {
        printf("Node %d not found in the BST.\n", key);
    }

    return 0;
}
