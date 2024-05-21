#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

void primeFactors(int num);
void push(int data);
int pop();
bool isFull();
bool isEmpty();
int peek();
int size();

int top = -1;
int stack[STACK_SIZE];
int main() {
    int number;
    system("clear");
    printf("Ingrese el numero para calcular sus factores primos: ");
    scanf("%d", &number);

    primeFactors(number);

    return 0;
}

void primeFactors(int num) {
    int i = 2;
    printf("%d = ", num);
    while(num != 1) {
        while(num % i == 0) {
            push(i);
            num = num / i;
        }
        i++;
    }

    while(top != -1) {
        printf("%d ", pop());
    }
    printf("\n");
}
void push(int data) {
    if(!isFull()) {
        top = top + 1;
        stack[top] = data;
    } else {
        printf("Error al agregar un elemento. Stack lleno.\n");
    }
}
int pop() {
    int data;
    if(!isEmpty()) {
        data = stack[top];
        top = top - 1;
        return data;
    } else {
        printf("Error al eliminar un elemento. Stack vacio.\n");
        return EXIT_FAILURE;
    }
}
bool isEmpty() {
    if(top == -1) {
        return true;
    } else {
        return false;
    }
}
bool isFull() {
    if(top == STACK_SIZE) {
        return true;
    } else {
        return false;
    }
}
int peek() {
    return stack[top];
}
int size() {
    return top + 1;
}