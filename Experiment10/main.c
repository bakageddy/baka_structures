#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

int main(void) {
    int opt, elem;
    AVL *tree = NULL;
    do {
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Quit\n");
        printf("Your option: ");
        scanf("%d", &opt);
        if (opt == 1) {
            printf("Enter the element: ");
            scanf("%d", &elem);
            tree = insert(tree, elem);
        } else if (opt == 2) {
            preorder(tree);
        }
    } while (opt != 3);
    freeMe(tree);
    return 0;
}
