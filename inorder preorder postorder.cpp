#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *left;
    struct node *right;
};

void inorder(struct node *n) {
    if (n != NULL) {
        inorder(n->left);
        printf("%c ", n->data);
        inorder(n->right);
    }
}

void preorder(struct node *n) {
    if (n != NULL) {
        printf("%c ", n->data);
        preorder(n->left);
        preorder(n->right);
    }
}

void postorder(struct node *n) {
    if (n != NULL) {
        postorder(n->left);
        postorder(n->right);
        printf("%c ", n->data);
    }
}

struct node *newNode(char data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main() {
    struct node *root = newNode('+');
    root->left = newNode('*');
    root->right = newNode('-');
    root->left->left = newNode('a');
    root->left->right = newNode('b');
    root->right->left = newNode('c');
    root->right->right = newNode('d');

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}

