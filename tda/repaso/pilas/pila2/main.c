#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 50

void push(int data);
int pop();
bool isEmpty();
bool isFull();
int peek();
int size();
void printStack();

int stack[STACK_SIZE];
int first = 0;

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
    if(isFull()) {
        printf("El stack se encuentra lleno. No se pueden agregar mas elementos.\n");
        exit(1);
    }
    first = first + 1;
    for(int i = first; i > 0; i--) {
        stack[i] = stack[i - 1];
    }
    stack[0] = data;
}
int pop() {
    if(isEmpty()) {
        printf("El stack se encuentra vacio. No se pueden eliminar mas elementos.\n");
        exit(1);
    }
    int value = stack[0];
    for(int i = 0; i <= first; i++) {
        stack[i] = stack[i + 1];
    }
    first = first - 1;
    return value;
}
bool isFull() {
    if(first == STACK_SIZE) {
        return true;
    }
    return false;
}
bool isEmpty() {
    if(first == -1) {
        return true;
    }
    return false;
}
int peek() {
    return stack[0];
}
int size() {
    return first;
}
void printStack() {
    int tmp = 0;
    while(tmp < first) {
        printf("%d ", stack[tmp]);
        tmp = tmp + 1;
    }
    printf("\n");
}