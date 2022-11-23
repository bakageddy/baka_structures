#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

static int stack[SIZE] = {0};
int ptr = 0;

void push(int elem) {
    if (ptr == SIZE)
        exit(1);
    stack[ptr++] = elem;
}

int pop() {
    if (ptr == 0) exit(1);
    int elem = stack[--ptr];
    return elem;
}

void display() {
    for (int i = 0; i < ptr; i++)
        printf("%d ", stack[i]);
    puts(" ");
}

int main(void) {
    int elem, opt;
    do {
        printf("1. Push\n"
               "2. Pop\n"
               "3. Display\n"
               "4. Quit\n"
               "Your option: ");
        scanf("%d", &opt);
        if (opt == 1) {
            printf("Enter the element: ");
            scanf("%d", &elem);
            push(elem);
        } else if (opt == 2) {
            elem = pop();
            printf("Popped: %d\n", elem);
        } else if (opt == 3) {
            display();
        }
    } while (opt != 4);
    return 0;
}
