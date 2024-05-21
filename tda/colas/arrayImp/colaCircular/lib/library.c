#include "library.h"

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 7

int stack[STACK_SIZE];
int front = -1;
int rear = -1;
int sizeCounter = 0;

void enqueue(int data) {
    if(isFull()) {
        printf("La cola se encuentra llena. Elimine al menos un elemento para seguir agregando.\n");
        return;
    }
    if(isEmpty()) {
        front = 0;
    }
    rear ++;
    stack[rear] = data;
    sizeCounter ++;
}
int dequeue() {
    if(isEmpty()) {
        printf("La cola se encuentra vacia. No se pudo borrar ningun elemento.\n");
        exit(1);
    }
    int value = stack[front];
    if(front == rear) {
        front = -1;
        rear = -1;
    }
    front ++;
    sizeCounter --;
    return value;
}
bool endOfQueue() {
    if(rear == STACK_SIZE - 1) {
        return true;
    }
    return false;
}
bool isFull() {
    if((endOfQueue() && front == 0) || (front == rear + 1)) {
        return true;
    }
    return false;
}
bool isEmpty() {
    if(rear == -1) {
        return true;
    }
    return false;
}
int peek() {
    return stack[front];
}
int size() {
    return sizeCounter;
}
void printCola() {
    if(isEmpty()) {
        printf("La lista se encuentra vacia.\n");
        return;
    }
    for(int i = front; i != rear; i++) {
        printf("%d ", stack[i]);
    }
    printf("%d", stack[rear]);
    printf("\n");
}