#include <stdio.h>
#include <stdlib.h>
#include "library.h"

struct node {
    int data;
    struct node *link;
} *rear = NULL;

struct node *front = NULL;

void enqueue(int data) {
    struct node *element = malloc(sizeof(struct node));
    if(element == NULL) {
        printf("Error: No se pudo reservar memoria para el nuevo nodo.\n");
        exit(1);
    }
    element->data = data;
    element->link = NULL;
    if(isEmpty()) {
        front = element;
        rear = element;
        return;
    }
    rear->link = element;
    rear = element;
}
int dequeue() {
    struct node *tmp = front;
    if(isEmpty()) {
        printf("No se pudo eliminar el nodo. La cola se encuentra vacia.\n");
        exit(1);
    }
    int value = front->data;
    front = front->link;
    free(tmp);
    tmp = NULL;
    return value;
}
bool isEmpty() {
    if(front == NULL) {
        return true;
    }
    return false;
}
int size() {
    int nodeCounter = 0;
    struct node *tmp = front;
    while(tmp) {
        nodeCounter ++;
        tmp = tmp->link;
    }
    return nodeCounter;
}
int peek() {
    return front->data;
}
void printCola() {
    struct node *tmp = front;
    if(isEmpty()) {
        printf("La cola se encuentra vacia.\n");
    }
    while(tmp) {
        printf("%d ", tmp->data);
        tmp = tmp->link;
    }
    printf("\n");
}
