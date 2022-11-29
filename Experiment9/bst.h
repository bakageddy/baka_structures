#ifndef __BST_H
#define __BST_H
#include <stdio.h>
#include <stdlib.h>

struct Tree {
    int data;
    struct Tree *left, *right;
};

typedef struct Tree BST;

BST *create(int elem) {
    BST *temp = (BST *) malloc(sizeof(BST));
    if (!temp) exit(1);
    temp -> data = elem;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

BST *insert(BST *tree, int elem) {
    if (tree == NULL) {
        return create(elem);
    } else if (tree -> data >= elem) {
        tree -> left = insert(tree -> left, elem);
    } else if (tree -> data < elem) {
        tree -> right = insert(tree -> right, elem);
    }
    return tree;
}

void preorder(BST *tree) {
    if (tree == NULL) return;
    printf("%d\n", tree -> data);
    preorder(tree -> left);
    preorder(tree -> right);
}
void inorder(BST *tree) {
    if (tree == NULL) return;
    inorder(tree -> left);
    printf("%d\n", tree -> data);
    inorder(tree -> right);
}
void postorder(BST *tree) {
    if (tree == NULL) return;
    postorder(tree -> left);
    postorder(tree -> right);
    printf("%d\n", tree -> data);
}

void freeTree(BST *tree) {
    if (tree == NULL) return;
    freeTree(tree -> left);
    freeTree(tree -> right);
    free(tree);
}

#endif
