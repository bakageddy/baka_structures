#include <stdio.h>
#include <stdlib.h>
#include "link.h"

int main() {
    int elem, opt;
    list *stack = init();
    do {
        printf("1. Push\n2.Pop\n3.Display\n4.Quit\nEnter your choice: ");
        scanf("%d", &opt);
        if (opt == 1) {
            printf("Enter the elem: ");
            scanf("%d", &elem);
            push(stack, elem);
        } else if (opt == 2) {
            elem = pop(stack);
            printf("Popped: %d\n", elem);
        } else if (opt == 3) {
            traverse(stack);
        }
    } while (opt != 4);
    printf("Bye\n");
    return 0;
}
