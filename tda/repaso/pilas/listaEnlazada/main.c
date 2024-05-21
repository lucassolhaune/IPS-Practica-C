#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *link;
} *top = NULL;

int elemCounter = 0;

void push(int data);
int pop();
bool isEmpty();
int peek();
int size();
void printStack();
int main() {
    int num, menu;
    char option;
    system("clear");
    printf("Ingrese numeros para ser añadidos al stack.\n");
    do{
        printf("\t>>> ");
        scanf("%d", &num);
        push(num);
        printf("\tDesea agregar otro? [Y/N]: ");
        scanf(" %c", &option);
    } while(option != 'n' && option != 'N');
    system("clear");
    do {
        system("clear");
        printf("Para realizar otras operaciones, pulse:\n");
        printf("\t1. Eliminar numeros.\n");
        printf("\t2. Mostrar stack.\n");
        printf("\t3. Mostrar el ultimo numero del stack.\n");
        printf("\t4. Mostrar la cantidad de numeros guardados en el stack.\n");
        scanf("%d", &menu);

        switch(menu) {
            case 1:
                printf("Numero %d eliminado del stack.\n", pop());
                break;
            case 2:
                printf("Mostrando stack en pantalla...\n");
                printStack();
                break;
            case 3:
                printf("El ultimo numero es %d.\n", peek());
                break;
            case 4:
                printf("El stack contiene %d elementos.\n", size());
                break;
            default:
                printf("Error. El valor ingresado es incorrecto.\n");
                exit(1);
        }
        printf("Desea realizar otra operacion? [Y/N]: ");
        scanf(" %c", &option);
    } while(option != 'n' && option != 'N');
    system("clear");
    return 0;
}
void push(int data) {
    struct node *element = malloc(sizeof(struct node));
    if(element == NULL) {
        printf("Error. No se pudo reservar espacio para el nodo.\n");
        exit(1);
    }
    element->data = data;
    element->link = top;
    top = element;
    elemCounter = elemCounter + 1;
}
int pop() {
    int value = top->data;
    if(isEmpty()) {
        printf("No se pueden eliminar mas elementos. Lista vacia.\n");
        exit(1);
    }
    top = top->link;
    elemCounter = elemCounter - 1;
    return value;
}
bool isEmpty() {
    if(top == NULL) {
        return true;
    } else {
        return false;
    }
}
int peek() {
    return top->data;
}
int size() {
    return elemCounter;
}
void printStack() {
    struct node *tmp = top;
    while(tmp) {
        printf("%d ", tmp->data);
        tmp = tmp->link;
    }
    printf("\n");
}