#include "library.h"

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};
struct node *head = NULL;
struct node *tail = NULL;
struct node *tmp = NULL;
struct node *prevTmp = NULL;

void enqueue(int data) {
    struct node *newElement = malloc(sizeof(struct node));

    if(newElement == NULL) {
        printf("Error al reservar memoria para el nuevo elemento.\n");
        return;
    }
    newElement->data = data;
    newElement->link = NULL;
    if(isEmpty()) {
        head = newElement;
        tail = newElement;
        return;
    }
    if(newElement->data <= head->data) {
        newElement->link = head;
        head = newElement;
        return;
    } else if(newElement->data > tail->data) {
        tail->link = newElement;
        tail = newElement;
        return;
    }
    tmp = head->link;
    prevTmp = head;
    while(prevTmp->link != NULL) {
        if((newElement->data > prevTmp->data) && (newElement->data <= tmp->data)) {
            newElement->link = tmp;
            prevTmp->link = newElement;
            return;
        }
        prevTmp = tmp;
        tmp = tmp->link;
    }
}
int dequeue() {
    if(isEmpty()) {
        printf("La cola se encuentra vacia.\n");
        exit(1);
    }
    tmp = head;
    int value = head->data;
    head = head->link;
    free(tmp);
    tmp = NULL;
    return value;
}
bool isEmpty() {
    if(head == NULL) {
        return true;
    }
    return false;
}
void printCola() {
    if(isEmpty()) {
        printf("La cola se encuentra vacia.\n");
        return;
    }
    tmp = head;
    while(tmp) {
        printf("%d ", tmp->data);
        tmp = tmp->link;
    }
    printf("\n");
}