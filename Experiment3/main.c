#include <stdio.h>
#include <stdlib.h>
#include "link.h"

typedef list poly;

void get_input(poly *poly, int terms) {
    int temp;
    for (int i = 0; i < terms; i++) {
        printf("Enter the coeff with exponent %d: ", i);
        scanf("%d", &temp);
        push(poly, temp);
    }
}

void display(poly *poly) {
    int i = 0;
    node_t *temp = poly -> head;
    while (temp != NULL) {
        printf("%dx^%d + ", temp -> data, i);
        temp = temp -> next;
        i++;
    }
    printf("\n");
}

int min(int a, int b) {
    return (a > b) ? b : a;
}

poly *poly_add(poly *poly1, poly *poly2) {
    int i;
    poly *result = init();
    node_t *p1 = poly1 -> head, *p2 = poly2 -> head;
    while (p1 != NULL && p2 != NULL) {
        push(result, p1 -> data + p2 -> data);
        p1 = p1 -> next;
        p2 = p2 -> next;
    }

    while (p1 != NULL) {
        push(result, p1 -> data);
        p1 = p1 -> next;
    }

    while (p2 != NULL) {
        push(result, p2 -> data);
        p2 = p2 -> next;
    }
    return result;
}

int main(void) {
    poly *p1, *p2, *result;
    int size;
    p1 = init();
    p2 = init();

    printf("Enter the biggest exponent in the term: ");
    scanf("%d", &size);
    get_input(p1, size);

    printf("Enter the biggest exponent in the term: ");
    scanf("%d", &size);
    get_input(p2, size);

    result = poly_add(p1, p2);
    display(result);

    done(p1);
    done(p2);
    done(result);

    return 0;
}
