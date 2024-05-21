/*Que lea 10 numeros por teclado, los almacene en un array y muestre la suma, resta, multiplicacion y division de
todos.*/
#include <stdio.h>
#include <stdlib.h>

void listGen(int numQuantity, int *numbers);
int sum(int numQuantity, int *numbers);
int substraction(int numQuantity, int *numbers);
int multiplication(int numQuantity, int *numbers);
float division(int numQuantity, int *numbers);

int main() {
	int *numbers, numQuantity;

	printf("Ingrese la cantidad de numeros con los que desee realizar las operaciones: ");
	scanf("%d", &numQuantity);
	
	numbers = (int *)malloc(numQuantity * sizeof(int));

	listGen(numQuantity, numbers);

	printf("El resultado de la suma es %d\n", sum(numQuantity, numbers));
	printf("El resultado de la resta es %d\n", substraction(numQuantity, numbers));
	printf("El resultado de la multiplicacion es %d\n", multiplication(numQuantity, numbers));
	printf("El resultado de la division es %f\n", division(numQuantity, numbers));

	free(numbers);
	return 0;
}

void listGen(int numQuantity, int *numbers) {
	printf("Por favor, introduzca los %d numeros:\n", numQuantity);
	for(int i = 0; i < numQuantity; i++) {
		printf("> ");
		scanf("%d", &numbers[i]);
	}

	printf("La lista de numeros seleccionados: ");
	for(int i = 0; i < numQuantity; i++) {
		if(i == (numQuantity - 1)) {
			printf("%d\n", numbers[i]);
		} else {
			printf("%d, ", numbers[i]);
		}
	}
}
/**
 * Funcion que realiza la suma entre todos los numeros del array.
 * @param numQuantity: Cantidad de numeros que tiene el array.
 * @param numbers: Array que contiene todos los numeros.
 * @return Resultado de la suma del array completo.
 */
int sum(int numQuantity, int *numbers) {
	int result = numbers[0];
	for(int i = 1; i < numQuantity; i++) {
		result = result + numbers[i];
	}
	return result;
}
/**
 * Funcion que realiza la resta entre todos los numeros del array.
 * @param numQuantity: Cantidad de numeros que tiene el array.
 * @param numbers: Array que contiene todos los numeros.
 * @return Resultado de la resta del array completo.
 */
int substraction(int numQuantity, int *numbers) {
	int result = numbers[0];
	for(int i = 1; i < numQuantity; i++) {
		result = result - numbers[i];
	}
	return result;
}
/**
 * Funcion que realiza la multiplicacion entre todos los numeros del array.
 * @param numQuantity: Cantidad de numeros que tiene el array.
 * @param numbers: Array que contiene todos los numeros.
 * @return Resultado de la multiplicacion del array completo.
 */
int multiplication(int numQuantity, int *numbers) {
	int result = numbers[0];
	for(int i = 1; i < numQuantity; i++) {
		result = result * numbers[i];
	}
	return result;
}
/**
 * Funcion que realiza la division entre todos los numeros del array.
 * @param numQuantity: Cantidad de numeros que tiene el array.
 * @param numbers: Array que contiene todos los numeros.
 * @return Resultado de la division del array completo.
 */
float division(int numQuantity, int *numbers) {
	float result = numbers[0];
	for(int i = 1; i < numQuantity; i++) {
		result = result / numbers[i];
	}
	return result;
}
