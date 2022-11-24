#include <stdio.h>
#include <string.h> // for memset function
#include <limits.h>
#define SIZE 10

static int table[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        table[i] = INT_MAX;
}

int hash(int elem, int i) {
    return (elem + i * i) % SIZE;
}

void insert(int elem) {
    int index;
    for (int i = 0; i < SIZE; i++) {
        index = hash(elem, i);
        if (table[index] == INT_MAX) {
            table[index] = elem;
            return;
        }
    }
    printf("Can't insert!\n");
}

int search(int elem) {
    int index;
    for (int i = 0; i < SIZE; i++) {
        index = hash(elem, i);
        if (table[index] == elem) return index;
    }
    return -1;
}

void delete(int elem) {
    int index;
    for (int i = 0; i < SIZE; i++) {
        index = hash(elem, i);
        if (table[index] == elem) {
            table[index] = INT_MAX;
            return;
        }
    }
    printf("Can't find element!\n");
}

void display() {
    int index;
    for (int i = 0; i < SIZE; i++) {
        printf("%d -> %d\n", i, table[i]);
    }
}

int main(void) {
    int elem, opt;
    init();
    do {
        printf("1. Insert\n"
               "2. Search\n"
               "3. Delete\n"
               "4. Display\n"
               "5. Quit\n"
               "Enter your option: ");
        scanf("%d", &opt);
        if (opt == 1) {
            printf("Enter the element: ");
            scanf("%d", &elem);
            insert(elem);
        } else if (opt == 2) {
            printf("Enter the element: ");
            scanf("%d", &elem);
            printf("Found element %d at %d\n", elem, search(elem));
        } else if (opt == 3) {
            printf("Enter the element: ");
            scanf("%d", &elem);
            delete(elem);
        } else if (opt == 4) {
            display();
        }
    } while (opt != 5);
    return 0;
}
