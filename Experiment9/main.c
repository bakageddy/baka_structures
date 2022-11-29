#include <stdio.h>
#include <stdlib.h>
#include "bst.h"  // Only include this line if you are having a separate bst.h file
// Or else dont include the line...


int main(void) {
    int opt, elem, n;
    BST *tree = NULL;
    do {
        printf("1. Create\n"
               "2. Insert\n"
               "3. Inorder\n"
               "4. Preorder\n"
               "5. Postorder\n"
               "6. Quit\n"
               "Enter your option: ");
        scanf("%d", &opt);
        if (opt == 1) {
            printf("Enter the amount of elements to insert: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Enter the elem: ");
                scanf("%d", &elem);
                tree = insert(tree, elem);
            }
        } else if (opt == 2) {
            printf("Enter elem: ");
            scanf("%d", &elem);
            tree = insert(tree, elem);
        } else if (opt == 3) inorder(tree);
        else if (opt == 4) preorder(tree);
        else if (opt == 5) postorder(tree);
    } while (opt != 6);
    freeTree(tree);
}
