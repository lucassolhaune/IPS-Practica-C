#include "library.h"
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int top = -1;           //Declaro e inicializo top en -1.
int stack[STACK_SIZE];  //Declaro e inicializo el stack con STACK_SIZE posiciones.

/**
 * La funcion push es la encargada de agregar cada elemento al stack. Se evalua si el array se encuentra lleno y,
 * de ser negativo, le suma un valor a la variable top para tomar como referencia el ultimo valor que se agrego a la
 * pila.
 * @param data Valor que debe agregarse al stack.
 */
void push(int data) {
    if(!isFull()) {
        top = top + 1;
        stack[top] = data;
    } else {
        printf("Error al agregar un elemento. Stack lleno.\n");
    }
}
/**
 * La funcion pop elimina el ultimo elemento agregado a la pila, ya que la misma se caracteriza por trabajar con LIFO,
 * es decir, el ultimo agregado es el primero en eliminarse.
 *
 * Si la lista esta vacia no se podra borrar ningun valor. Caso contrario, tomo el valor del numero que quiero eliminar,
 * le resto uno a top para informar que el ultimo elemento ahora es el anterior al que se encontraba antes, y devuelvo el
 * valor guardado.
 *
 * @return Valor eliminado.
 */
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
/**
 * Funcion que informa si el stack se encuentra vacio.
 * @return True si se encuentra vacio, False si no lo esta.
 */
bool isEmpty() {
    if(top == -1) {
        return true;
    } else {
        return false;
    }
}
/**
 * Funcion que informa si el stack se encuentra lleno.
 * @return True si se encuentra lleno, False si no lo esta.
 */
bool isFull() {
    if(top == STACK_SIZE) {
        return true;
    } else {
        return false;
    }
}
/**
 * Esta funcion informa el valor que se encuentra en la cima.
 * @return Valor del ultimo numero del stack.
 */
int peek() {
    return stack[top];
}
/**
 * Funcion que dice la cantidad total de elementos almacenados en el stack.
 * @return Cantidad de elementos almacenados en el stack.
 */
int size() {
    return top + 1;
}
/**
 * Esta funcion se encarga de mostrar en pantalla el stack entero.
 */
void printStack() {
    for(int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}