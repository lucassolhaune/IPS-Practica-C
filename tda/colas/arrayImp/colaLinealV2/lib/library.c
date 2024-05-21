#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 5

int stack[STACK_SIZE];
int front = -1;

void enqueue(int data) {
    if(isFull()) {
        printf("Error al agregar un elemento. La cola se encuentra llena.\n");
        exit(1);
    }
    front = front + 1;
    for(int i = front; i > 0; i--) {
        stack[i] = stack[i - 1];
    }
    stack[0] = data;
}
int dequeue() {
    if(isEmpty()) {
        printf("Error al eliminar un elemento. La cola se encuentra vacia.\n");
        exit(1);
    }
    int value = stack[front];
    front = front - 1;
    return value;
}
bool isEmpty() {
    if(front == -1) {
        return true;
    } else {
        return false;
    }
}
bool isFull() {
    if(front == STACK_SIZE) {
        return true;
    } else {
        return false;
    }
}
int peek() {
    return stack[front];
}
int size() {
    return front + 1;
}
void printCola() {
    int tmp = front;
    for(int i = 0; i <= front; i++) {
        printf("%d ", stack[tmp]);
        tmp = tmp - 1;
    }
    printf("\n");
}