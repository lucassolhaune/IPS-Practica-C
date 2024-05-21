#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 7

int stack[STACK_SIZE];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if(isFull()) {
        printf("Error al agregar un elemento. La cola se encuentra llena.\n");
        return;
    }
    if(isEmpty()) {
        front = 0;
    }
    rear ++;
    stack[rear] = data;
}
int dequeue() {
    if(isEmpty()) {
        printf("Error al eliminar un elemento. La cola se encuentar vacia.\n");
        exit(1);
    }
    if(front == rear) {
        front = -1;
        rear = -1;
    }
    int value = stack[front];
    front ++;
    return value;
}
bool isEmpty() {
    if(rear == -1) {
        return true;
    } else {
        return false;
    }
}
bool isFull() {
    if(rear == STACK_SIZE - 1) {
        return true;
    } else {
        return false;
    }
}
int peek() {
    return stack[front];
}
int size() {
    int counter = 0;
    for(int i = front; i <= rear; i++) {
        counter++;
    }
    return counter;
}
void printCola() {
    for(int i = front; i <= rear; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
