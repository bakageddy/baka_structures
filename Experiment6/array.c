#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

static int queue[SIZE] = {0};
int front = 0, rear = 0;

int isFull() {
    if (rear == SIZE) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if (front == rear) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(int elem) {
    if (isFull()) {
        exit(1);
    }
    queue[rear++] = elem;
}
int dequeue() {
    if (isEmpty()) {
        exit(1);
    }
    int elem = queue[front++];
    return elem;
}

void traverse() {
    for (int i = front; i < rear; i++) printf("%d ", queue[i]);
    printf("\n");
}

int main(void) {
    int opt, elem;
    do {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your option: ");
        scanf("%d", &opt);
        if (opt == 1) {
            printf("Enter your element: ");
            scanf("%d", &elem);
            enqueue(elem);
        } else if (opt == 2) {
            elem = dequeue();
            printf("Dequeue'd element: %d\n", elem);
        } else if (opt == 3) {
            traverse();
        }
    } while (opt != 4);
    return 0;
}
