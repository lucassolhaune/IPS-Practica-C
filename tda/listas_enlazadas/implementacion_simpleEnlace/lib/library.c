#include "library.h"

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};
struct node *head = NULL;

void add_at_beg(int data) {
    struct node *new = malloc(sizeof(struct node));
    if(new == NULL) {
        printf("Error al agregar un elemento al principio de la lista.\n");
        return;
    }
    if(isEmpty()) {
        new->data = data;
        new->link = NULL;
        head = new;
        return;
    }
    new->data = data;
    new->link = head;
    head = new;
}
void add_at_pos(int data, int pos) {
    struct node *new = malloc(sizeof(struct node));
    struct node *ptr = head;
    if(new == NULL) {
        printf("Error al agregar un elemento en la lista.\n");
        return;
    }
    new->data = data;
    if(isEmpty()) {
        new->link = NULL;
        head = new;
        return;
    }
    if(pos == 1) {
        new->link = head;
        head = new;
        return;
    }
    for(int i = 1; i < pos - 1; i ++) {
        if(ptr->link == NULL) {
            new->link = NULL;
            ptr->link = new;
            return;
        }
        ptr = ptr->link;
    }

    new->link = ptr->link;
    ptr->link = new;
}
void add_at_end(int data) {
    struct node *new = malloc(sizeof(struct node));
    struct node *ptr = head;
    if(new == NULL) {
        printf("Error al agregar un elemento al fina de la lista.\n");
        return;
    }
    new->data = data;
    new->link = NULL;
    if(isEmpty()) {
        head = new;
        return;
    }
    while(ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = new;
}
int del_beg() {
    if(isEmpty()) {
        printf("Error al eliminar un elemento. Lista vacia.\n");
        exit(1);
    }
    struct node *tmp = head;
    int value = head->data;
    head = head->link;
    free(tmp);
    tmp = NULL;
    return value;
}
int del_pos(int pos) {
    struct node *ptr = head;
    if(isEmpty()) {
        printf("Error al eliminar un elemento. Lista vacia.\n");
        exit(1);
    }
    for(int i = 1; i < pos - 1; i++) {
        if(ptr->link->link == NULL) {
            if(head->link == NULL) {
                head = NULL;
            }
            int value = ptr->link->data;
            ptr->link = NULL;
            free(ptr->link);
            return value;
        }
        ptr = ptr->link;
    }
    int value = ptr->link->data;
    struct node *tmp = ptr->link;
    ptr->link = ptr->link->link;
    free(tmp);
    tmp = NULL;
    return value;
}
int del_last() {
    struct node *ptr = head;
    if(isEmpty()) {
        printf("Error al eliminar un elemento. Lista vacia.\n");
        exit(1);
    }
    while(ptr->link->link != NULL) {
        ptr = ptr->link;
    }
    int value = ptr->link->data;
    free(ptr->link);
    ptr->link = NULL;
    return value;
}
bool isEmpty() {
    if(head == NULL) {
        return true;
    }
    return false;
}
void printList() {
    struct node *tmp = head;
    int elementPos;
    if(isEmpty()) {
        printf("La lista esta vacia.\n");
        return;
    }
    elementPos = 1;
    while(tmp) {
        printf("%d° - %d\n", elementPos, tmp->data);
        elementPos++;
        tmp = tmp->link;
    }
}