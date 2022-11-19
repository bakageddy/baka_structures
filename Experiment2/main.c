#include <stdio.h>
#include <stdlib.h>
#include "link.h"

int main(void) {
    list *list = init();
    int option, elem, index;
    do {
        printf("1. Append\n"
                "2. Queue\n"
                "3. Insert\n"
                "4. Pop\n"
                "5. Dequeue\n"
                "6. Delete\n"
                "7. Search\n"
                "8. Display\n"
                "9. Quit\n"
                "Your Option: ");
        scanf("%d", &option);
        if (option == 1) {
            printf("Enter a element: ");
            scanf("%d", &elem);
            push(list, elem);
        } else if (option == 2) {
            printf("Enter the element: ");
            scanf("%d", &elem);
            queue(list, elem);
        } else if (option == 3) {
            printf("Enter the index: ");
            scanf("%d", &index);
            printf("Enter the element: ");
            scanf("%d", &elem);
            insert(list, index, elem);
        } else if (option == 4) {
            pop(list);
        } else if (option == 5) {
            dequeue(list);
        } else if (option == 6) {
            printf("Enter the index: ");
            scanf("%d", &index);
            delete(list, index);
        } else if (option == 7) {
            printf("Enter element: ");
            scanf("%d", &elem);
            printf("Element %d found at %d\n", elem, search(list, elem));
        } else if (option == 8) {
            traverse(list);
        } else {
            printf("Wrong Option!\n");
            continue;
        }
    } while (option != 9);
    done(list);
    return 0;
}
