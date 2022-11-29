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
    return height(root -> left) - height(root -> right);
}

AVL *rotateLeft(AVL *root) {
    return root;
}

AVL *rotateRight(AVL *root) {
    return root;
}

AVL *leftRight(AVL *root) {
    return root;
}

AVL *rightLeft(AVL *root) {
    return root;
}


AVL *insert(AVL *root, int elem) {
    int h, bal;
    if (root == NULL) {
        return giveMeNode(elem);
    } else if (root -> data >= elem) {
        root -> left = insert(root -> left, elem);
    } else if (root -> data < elem) {
        root -> right = insert(root -> right, elem);
    }
    bal = balance(root);
    h = height(root);
    if (bal != 2 || bal != -2) {
        return root;
    }
    else {
        if (bal == 2) {
            if (root -> left)
            return rotateRight(root);
        }
        if (bal == -2) {
            return root;
        }
    }
}

#endif
