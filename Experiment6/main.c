#include <stdio.h>
#include <stdlib.h>
#include "link.h"

int main(void) {
    list *q = init();
    int elem, opt;
    do {
        printf("1. Enqueue\n"
                "2. Dequeue\n"
                "3. Display\n"
                "4. Quit\n"
                "Enter your option: ");
        scanf("%d", &opt);
        if (opt == 1) {
            printf("Enter elem: ");
            scanf("%d", &elem);
            push(q, elem);
        } else if (opt == 2) {
            printf("Dequeue'd element: %d\n", dequeue(q));
        } else if (opt == 3) traverse(q);
    } while (opt != 4);
    done(q);
    return 0;
}
