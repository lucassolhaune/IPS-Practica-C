#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *link;
};
struct node *first = NULL;
struct node *last = NULL;

bool isEmpty() {
    if(first == NULL) {
        return true;
    }
    return false;
}
void enqueue(int data) {
    struct node *newElement = malloc(sizeof(struct node));
    if(isEmpty()) {
        newElement->data = data;
        newElement->link = NULL;
        first = newElement;
        last = first;
        return;
    }
    if(newElement == NULL) {
        printf("Error. No se pudo reservar espacio.\n");
        return;
    }
    newElement->data = data;
    newElement->link = NULL;
    last->link = newElement;
    last = newElement;
}
int dequeue() {
    if(isEmpty()) {
        printf("Error. La cola esta vacia.\n");
        exit(1);
    }
    int value = first->data;
    struct node *tmp = first;
    first = first->link;
    free(tmp);
    tmp = NULL;
    return value;
}
void printQueue() {
    struct node *ptr = first;
    while(ptr) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    printQueue();
    printf("\n");
    dequeue();
    dequeue();
    printQueue();
    printf("\n");
    return 0;
}

