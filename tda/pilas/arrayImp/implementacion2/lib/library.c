#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 10
/**
 * En esta implementacion se almacena el ultimo elemento ingresado en la primera posicion del array.
 * Es decir, el ultimo numero se guarda en stack[0].
 */

int first = -1;
int stack[STACK_SIZE];

/**
 * Funcion para almacenar valores en el stack.
 * Se toma la referencia del primer elemento añadido y cada vez que se desee
 * agregar un dato, se corren todos los valores hacia la derecha, para almacenar el ultimo valor en stack[0].
 *
 * @param data Numero que se desee agregar.
 */
void push(int data) {
    if(!isFull()) {
        first = first + 1;
        for(int i = first; i > 0; i--) {
            stack[i] = stack[i - 1];
        }
        stack[0] = data;
    } else {
        printf("Error al agregar un elemento. Stack lleno.\n");
    }
}

/**
 * Funcion para eliminar el ultimo elemento del stack.
 * Se guarda el valor del numero que se encuentra en la cima (en este caso, en la posicion stack[0]), se mueven todas
 * las posiciones un lugar hacia la izquierda y devuelvo el valor almacenado en la variable data.
 *
 * @return Valor almacenado en la variable data.
 */
int pop() {
    int data;
    if(!isEmpty()) {
        data = stack[0];
        for(int i = 0; i < first; i++) {
            stack[i] = stack[i + 1];
        }
        first = first - 1;
        return data;
    } else {
        return EXIT_FAILURE;
    }
}

/**
 * Funcion que informa si el stack se encuentra vacio.
 * @return True si se encuentra vacio, False si no lo esta.
 */
bool isEmpty() {
    if(first == -1) {
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
    if(first == STACK_SIZE -1) {
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
    if(!isEmpty()) {
        return stack[0];
    } else {
        printf("El stack se encuentra vacio.\n");
        return 0;
    }
}
/**
 * Funcion que dice la cantidad total de elementos almacenados en el stack.
 * @return Cantidad de elementos almacenados en el stack.
 */
int size() {
    return first + 1;
}
/**
 * Esta funcion se encarga de mostrar en pantalla el stack entero.
 */
void printStack() {
    if(isEmpty()) {
        printf("El stack se encuentra vacio.");
    }
    for(int i = 0; i <= first; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
