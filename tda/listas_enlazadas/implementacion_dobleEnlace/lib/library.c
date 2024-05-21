#include "library.h"

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head = NULL;

void add_at_beg(int data) {
    struct node *new = malloc(sizeof(struct node));
    if(new == NULL) {
        printf("Error al agregar un elemento al principio de la lista.\n");
        return;
    }
    new->prev = NULL;
    if(isEmpty()) {
        new->data = data;
        new->next = NULL;
        head = new;
        return;
    }
    new->data = data;
    new->next = head;
    head->prev = new;
    head = new;
}
void add_at_pos(int data, int pos) {
    struct node *new = malloc(sizeof(struct node));
    struct node *ptr1 = head;
    struct node *ptr2;
    if(new == NULL) {
        printf("Error al agregar un elemento en la lista.\n");
        return;
    }
    new->data = data;
    if(isEmpty()) {
        new->next = NULL;
        new->prev = NULL;
        head = new;
        return;
    }
    if(pos == 1) {
        new->next = head;
        new->prev = NULL;
        head->prev = new;
        head = new;
        return;
    }
    for(int i = 1; i < pos - 1; i ++) {
        if(ptr1->next == NULL) {
            new->next = NULL;
            new->prev = ptr1;
            ptr1->next = new;
            return;
        }
        ptr1 = ptr1->next;
    }
    ptr2 = ptr1->next;
    new->prev = ptr1;
    new->next = ptr2;
    ptr1->next = new;
    ptr2->prev = new;
}
void add_at_end(int data) {
    struct node *new = malloc(sizeof(struct node));
    struct node *ptr = head;
    if(new == NULL) {
        printf("Error al agregar un elemento al fina de la lista.\n");
        return;
    }
    new->data = data;
    new->next = NULL;
    if(isEmpty()) {
        new->next = NULL;
        new->prev = NULL;
        head = new;
        return;
    }
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new;
    new->prev = ptr;
}
int del_beg() {
    if(isEmpty()) {
        printf("Error al eliminar un elemento. Lista vacia.\n");
        exit(1);
    }
    struct node *tmp = head;
    int value = head->data;
    head = head->next;
    free(tmp);
    tmp = NULL;
    return value;
}
int del_pos(int pos) {
    struct node *ptr1 = head;
    struct node *ptr2;
    if(isEmpty()) {
        printf("Error al eliminar un elemento. Lista vacia.\n");
        exit(1);
    }
    for(int i = 1; i < pos - 1; i++) {
        if(ptr1->next == NULL) {
            if(head->next == NULL) {
                head = NULL;
            }
            int value = ptr1->data;
            ptr1 = NULL;
            return value;
        }
        ptr1 = ptr1->next;
    }
    ptr2 = ptr1->next->next;
    int value = ptr1->next->data;
    struct node *tmp = ptr1->next;
    ptr1->next = ptr2;
    ptr2->prev = ptr1;
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
    while(ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    struct node *tmp = ptr->next;
    int value = tmp->data;
    free(tmp);
    tmp = NULL;
    ptr->next = NULL;
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
    if (isEmpty()) {
        printf("La lista esta vacia.\n");
        return;
    }
    elementPos = 1;
    while (tmp) {
        printf("%d° - %d\n", elementPos, tmp->data);
        elementPos++;
        tmp = tmp->next;
    }
}