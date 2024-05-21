#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "library.h"

struct node {
    int data;
    struct node *link;
}*top = NULL;

void push(int data) {
    struct node *newNode = malloc(sizeof(struct node));
    if(newNode == NULL) {
        printf("Error. No se pudo reservar memoria para el nuevo nodo.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = top;
    top = newNode;
}
int pop() {
    struct node *tmp;
    int value;
    if(isEmpty()) {
        printf("Error. El stack se encuentra vacio.\n");
        exit(1);
    }
    tmp = top;
    value = tmp->data;
    top = top->link;
    free(tmp);
    tmp = NULL;

    return value;
}
bool isEmpty() {
    if(top == NULL) {
        return 1;
    } else {
        return 0;
    }
}
int peek() {
    if(isEmpty()) {
        printf("Error. El stack se encuentra vacio.\n");
        exit(1);
    }
    return top->data;
}
void print() {
    struct node *tmp = NULL;
    if(isEmpty()) {
        printf("Error. El stack se encuentra vacio.\n");
        exit(1);
    }
    printf("Mostrando stack en pantalla...\n");
    tmp = top;
    while(tmp) {
        printf("%d ", tmp->data);
        tmp = tmp->link;
    }
    printf("\n");
}