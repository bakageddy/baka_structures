#include <stdio.h>
#include <limits.h>
#define SIZE 10
static int queue[SIZE];
int front = 0, rear = 0;

int isEmpty() {
    return front == rear;
}

int isFull() {
    if (front == rear + 1) return 1;
    else if (front == 0 && rear == SIZE) return 1;
    return 0;
}

void enqueue(int elem) {
    if (isFull()) return;
    if (rear == SIZE) rear = 0;
    queue[rear++] = elem;
}

int dequeue() {
    if (isEmpty()) return INT_MIN;
    if (front > rear && front == SIZE) front = 0;
    return queue[front++];
}

void traverse() {
    if (rear > front)
        for (int i = front; i < rear; i++)
            printf("%d ", queue[i]);
    else {
        for (int i = front; i < SIZE; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i < rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(void) {
    int opt, elem;
    do {
        printf("1. Enqueue\n2.Dequeue\n3.Display\n4.Quit\nEnter your option: ");
        scanf("%d", &opt);
        if (opt == 1) {
            printf("Enter your element: ");
            scanf("%d", &elem);
            enqueue(elem);
        } else if (opt == 2) {
            printf("Dequeue'd element: %d\n", dequeue());
        } else if (opt == 3) traverse();
    } while (opt != 4);
    return 0;
}
