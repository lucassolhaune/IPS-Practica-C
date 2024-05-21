#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 50

void push(int data);
int pop();
bool isEmpty();
bool isFull();
int peek();
int size();
void printStack();

int top = -1;
int stack[STACK_SIZE];
int main() {
    int num, menu;
    char option;

    printf("Ingrese numeros para ser añadidos al stack.\n");
    do{
        printf("\t>>> ");
        scanf("%d", &num);
        push(num);
        printf("\tDesea agregar otro? [Y/N]: ");
        scanf(" %c", &option);
    } while(option != 'n' && option != 'N');

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
    return 0;
}
void push(int data) {
    if(isFull()) {
        printf("Stack lleno. No se pueden agregar mas elementos.\n");
        exit(1);
    }
    top = top + 1;
    stack[top] = data;
}
int pop() {
    if(isEmpty()) {
        printf("Stack vacio. No se pueden eliminar mas elementos.\n");
        exit(1);
    }
    int value = stack[top];
    top = top - 1;
    return value;
}
bool isEmpty() {
    if(top == -1) {
        return true;
    }
    return false;
}
bool isFull() {
    if(top == STACK_SIZE) {
        return true;
    }
    return false;
}
int peek() {
    return stack[top];
}
int size() {
    return top + 1;
}
void printStack() {
    int tmp = top;
    while(tmp > -1) {
        printf("%d ", stack[tmp]);
        tmp = tmp - 1;
    }
    printf("\n");
}