#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

/**
 * ===============================Consigna=================================
 * Que lea 10 numeros por teclado, los almacene en un array y los ordene de
 * forma ascendente.
 * ========================================================================
 */  

/**
 * Genera el array de numeros ingresados por teclado.
 * @param numbers Array de 10 posiciones vacio.
 */ 
void genArray(int *numbers) {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("> ");
        scanf("%d", &numbers[i]);
    }
}

/**
 * Ordena los numeros del array de forma ascendente.
 * @param numbers Array de 10 posiciones con numeros ingresados por teclado.
 * @param temp Variable temporal
 */  
void orderArray(int *numbers) {
    int temp;
    for(int i = 0; i < ARRAY_SIZE - 1; i++) {
        for(int j = i+1; j < ARRAY_SIZE; j++) {
            if(numbers[j] < numbers[i]) {
                temp =  numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = temp;
            }
        }
    printf("%d, ", numbers[i]);
    }
}

int main() {
    int numbers[ARRAY_SIZE];

    //Se guardan los 10 numeros que el usuario ingresa por teclado.
    printf("Ingrese 10 numeros:\n");
    genArray(numbers);

    printf("\nArray ordenado de forma ascendente: ");
    orderArray(numbers);
    
    return 0;
}