#ifndef __AVL_H
#define __AVL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} AVL;

AVL *giveMeNode(int elem) {
    AVL *temp = NULL;
    temp = (AVL *) malloc(sizeof(AVL));
    if (!temp) {
        printf("No memory left!\n");
        exit(1);
    }
    temp -> data = elem;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

void freeMe(AVL *root) {
    if (!root) return;
    freeMe(root -> left);
    freeMe(root -> right);
    free(root);
}

int max(const int a, const int b) {
    return (a >= b) ? a : b;
}

int height(AVL *root) {
    if (root == NULL) return -1;
    return max(height(root -> left), height(root -> right)) + 1;
}

int balance(AVL *root) {
    if (root == NULL) return 0;
    return height(root -> left) - height(root -> right);
}

AVL *rotateLeft(AVL *root) {
    AVL *y = root -> right;
    AVL *B = y -> left;
    y -> left = root;
    root -> right = B;
    return y;
}

AVL *rotateRight(AVL *root) {
    AVL *y = root -> left;
    AVL *B = y -> right;
    y -> right = root;
    root -> left = B;
    return y;
}

AVL *insert(AVL *root, int elem) {
    int bal;
    if (root == NULL)
        return giveMeNode(elem);
    else if (root -> data > elem)
        root -> left = insert(root -> left, elem);
    else if (root -> data < elem)
        root -> right = insert(root -> right, elem);
    return root;
    bal = balance(root);
    if (bal > 1) {
        if (elem > root -> left -> data)
            root -> left = rotateLeft(root);
        return rotateRight(root);
    }
    else if (bal < -1) {
        if (elem < root -> right -> data)
            root -> right = rotateRight(root);
        return rotateLeft(root);
    }
    else return root;
}

void preorder(AVL *root) {
    if (root == NULL) return;
    printf("%d: %d\n", root -> data, balance(root));
    preorder(root -> left);
    preorder(root -> right);
}

#endif
