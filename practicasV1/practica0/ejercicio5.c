#include <stdio.h>
#include <stdlib.h>

/**
 * =================================Consigna==================================
 * Que lea 10 numeros por teclado, los almacene en un array y muestre la suma,
 * resta, multiplicacion y division de todos.
 * ===========================================================================
 */ 

/**
 * Funcion para calcular la suma de todos los numeros dentro del array.
 * @param numbers Array de numeros ingresados por el usuario.
 * @return Resultado de la suma.
 */ 
int addition(int *numbers) {
    int result;
    
    for(int i = 0; i < 10; i++) {
        result += numbers[i];
    }
    return result;
} 

/**
 * Funcion para calcular la resta de todos los numeros dentro del array.
 * @param numbers Array de numeros ingresados por el usuario.
 * @return Resultado de la resta.
 */ 
int subtraction(int *numbers) {
    int result;

    result = numbers[0];
    for(int i = 1; i < 10; i++) {
        result -= numbers[i];
    }
    return result;  
}

/**
 * Funcion para calcular la multiplicacion de todos los numeros dentro del array.
 * @param numbers Array de numeros ingresados por el usuario.
 * @return Resultado de la multiplicacion.
 */ 
int multiplication(int *numbers) {
    int result;

    result = numbers[0];
    for(int i = 1; i < 10; i++) {
        result *= numbers[i];
    }
    return result;
}

/**
 * Funcion para calcular la division de todos los numeros dentro del array.
 * @param numbers Array de numeros ingresados por el usuario.
 * @return Resultado de la division.
 */ 
double division(int *numbers) {
    double result;

    result = numbers[0];
    for(int i = 1; i < 10; i++) {
        result = numbers[i] / result;
    }
    return result;
}

int main() {
    int numbers[10];
    int num, result;

    //Se guardan los 10 numeros que el usuario ingresa por teclado.
    printf("Ingrese 10 numeros:\n");
    for(int i = 0; i < 10; i++) {
        printf("> ");
        scanf("%d", &numbers[i]);
    } 

    //Se imprimen los resultados de cada operacion.
    
    result = addition(numbers);
    printf("El resultado de la suma es: %d\n", result);

    result = subtraction(numbers);
    printf("El resultado de la resta es: %d\n", result);

    result = multiplication(numbers);
    printf("El resultado de la multiplicacion es: %d\n", result);

    printf("El resultado de la division es: %f\n", division(numbers));

    return 0;

}