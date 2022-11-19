#ifndef __LINK_H
#define __LINK_H
#endif

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node_t;

typedef struct {
    node_t *head;
    int len;
} list;

list *init() {
    list *temp = (list *) malloc(sizeof(list));
    if (!temp) exit(1);
    temp -> head = NULL;
    temp -> len = 0;
    return temp;
}


node_t *new(int data) {
    node_t *temp = (node_t *) malloc(sizeof(node_t));
    if (!temp) exit(1);
    temp -> data = data;
    temp -> next = NULL;
    return temp;
}

void done(list *list) {
    node_t *temp = list -> head, *clear;
    while (temp) {
        clear = temp;
        temp = temp -> next;
        free(clear);
    }
    list -> len = 0;
    free(list);
}

int get(list *list, const unsigned int index) {
    if (index >= list -> len) {
        done(list);
        exit(1);
    }
    int i = 0;
    node_t *temp = list -> head;
    while (temp) {
        if (i == index) {
            return temp -> data;
        }
        i++;
        temp = temp -> next;
    }
}

void traverse(const list *list) {
    node_t *temp = list -> head;
    while (temp) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

void push(list *list, const int elem) {
    node_t *temp = list -> head, *n;
    if (temp == NULL) {
        list -> head = new(elem);
        return;
    }
    while (temp -> next) temp = temp -> next;
    n = new(elem);
    temp -> next = n;
    list -> len += 1;
}

void queue(list *list, const int elem) {
    node_t *temp = list -> head, *n;
    if (temp == NULL) {
        list -> head = new(elem);
        return;
    }
    n = new(elem);
    list -> head = n;
    n -> next = temp;
    list -> len += 1;
}

void insert(list *list, const int index, const int elem) {
    int i = 0;
    node_t *temp = list -> head, *n;

    if (index > list -> len + 1) {
        free(list);
        exit(1);
    }

    if (index == 0) {
        queue(list, elem);
        return;
    }

    if (temp == NULL) {
        done(list);
        exit(1);
    }

    while (temp != NULL && i != index - 1) {
        temp = temp -> next;
        i++;
    }

    n = new(elem);
    n -> next = temp -> next;
    temp -> next = n;
    list -> len += 1;
}

int pop(list *list) {
    int data;
    node_t *temp = list -> head, *prev;
    while (temp -> next) {
        prev = temp;
        temp = temp -> next;
    }
    data = temp -> data;
    prev -> next = NULL;
    free(temp);
    list -> len--;
    return data;
}

int dequeue(list *list) {
    int data;
    node_t *temp = list -> head;
    list -> head = list -> head -> next;
    data = temp -> data;
    free(temp);
    list -> len--;
    return data;
}

void delete(list *list, const int index) {
    if (index >= list -> len) {
        done(list);
        exit(1);
    }

    if (index == 0) {
        dequeue(list);
        return;
    }

    if (index == list -> len - 1) {
        pop(list);
        return;
    }

    int i = 0;
    node_t *temp = list -> head, *del;

    if (temp == NULL) {
        done(list);
        exit(1);
    }

    while (temp != NULL && i != index - 1) {
        temp = temp -> next;
        i++;
    }

    del = temp -> next;
    temp -> next = temp -> next -> next;
    free(del);
    list -> len -= 1;
}

int search(list *list, const int elem) {
    node_t *temp = list -> head;
    int i = 0;
    while (temp) {
        if (temp -> data == elem)
            return i;
        else
            i++;
        temp = temp -> next;
    }
    return -1;
}
