/*Que rellene un array con los numeros pares y otro con los impares comprendidos entre 1 y 100 y los muestre en
 pantalla en orden ascendente y descendente.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TOTAL_NUM 100

void listGen(int *list);
void printList(int *list);
void swap(int *list, int i, int j);
void ascendentOrder(int *list);
void descendentOrder(int *list);
void evenOrOdd(int *list, int *evenNumbers, int *oddNumbers);

int main() {
	int list[TOTAL_NUM];    //Lista de (TOTAL_NUM) numeros.
	int *evenNumbers;       //Array donde se almacenan numeros pares.
	int *oddNumbers;        //Array donde se almacenan numeros impares.
	int *pEven;             //Puntero para guardar la posicion inicial a *evenNumbers.
	int *pOdd;              //Puntero para guardar la posicion inicial a *oddNumbers.

    //Reservo memoria para ambos arrays.
	evenNumbers = (int *)malloc(TOTAL_NUM * sizeof(int));
	oddNumbers = (int *)malloc(TOTAL_NUM * sizeof(int));
    //Guardo posicion inicial de ambos punteros.
	pEven = evenNumbers;
	pOdd = oddNumbers;

	listGen(list);
	printf("Lista original:\n");
	printList(list);

	evenOrOdd(list, evenNumbers, oddNumbers);
	printf("Numeros pares:\n");
	printList(evenNumbers);
	printf("Numeros impares:\n");
	printList(oddNumbers);
	
	ascendentOrder(evenNumbers);
	printf("Numeros pares ordenados de forma ascendente:\n");
	printList(evenNumbers);

	descendentOrder(evenNumbers);
	printf("Numeros pares ordenados de forma descendente:\n");
	printList(evenNumbers);
	
	ascendentOrder(oddNumbers);
	printf("Numeros impares ordenados de forma ascendente:\n");
	printList(oddNumbers);

	descendentOrder(oddNumbers);
	printf("Numeros impares ordenados de forma descendente:\n");
	printList(oddNumbers);

    //Vuelvo a la posicion inicial de ambos punteros para liberar memoria reservada.
	evenNumbers = pEven;
	oddNumbers = pOdd;
	free(evenNumbers);
	free(oddNumbers);
	
	return 0;
}
/**
* Funcion para generar una lista con (TOTAL_NUM) valores aleatorios.
* @param list: Array de (TOTAL_NUM) numeros.
*/
void listGen(int *list) {
	srand(time(NULL));
	for (int i = 0; i < TOTAL_NUM; i++) {
		list[i] = 1 + (rand() % (TOTAL_NUM - 1));
	}
}
/**
 * Funcion para mostrar en pantalla la lista generada en listGen().
 * @param list: Array de (TOTAL_NUM) numeros.
 */
 void printList(int *list) {
	for (int i = 0; i < TOTAL_NUM; i++) {
		if(list[i] != 0) {
			printf("%d, ", list[i]);		
		}
	}
	printf("\n");
}
/**
 * Funcion que realiza un intercambio de valores entre variables.
 * @param list: Array de (TOTAL_NUM) numeros.
 * @param i: Variable 1 del tipo integer.
 * @param j: Variable 2 del tipo integer.
 */
void swap(int *list, int i, int j) {
	int tmp;
	tmp = list[i];
	list[i] = list[j];
	list[j] = tmp;
}

/**
 * Funcion que ordena la lista de forma ascendente. \n
 * Se comparan los valores desde el principio hasta el final y, al encontrar un numero cuyo valor sea menor y se
 * encuentre en una posicion posterior al numero que se esta comparando, se llama a la funcion swap() para intercambiar
 * sus valores.
 * @param list: Array de (TOTAL_NUM) numeros.
 */
void ascendentOrder(int *list) {
	for(int i = 1; i < TOTAL_NUM; i++) {
		for(int j = 0; j <= i; j++) {
			if(list[i] < list[j]) {
				swap(list, i, j);			 
			}
		}
	}
}
/**
 * Funcion que ordena la lista de forma descendente. \n
 * Se comparan los valores desde el principio hasta el final y, al encontrar un numero cuyo valor sea mayor y se
 * encuentre en una posicion posterior al numero que se esta comparando, se llama a la funcion swap() para intercambiar
 * sus valores.
 * @param list: Array de (TOTAL_NUM) numeros.
 */
void descendentOrder(int *list) {
	for(int i = 1; i < TOTAL_NUM; i++) {
		for(int j = 0; j <= i; j++) {
			if(list[i] > list[j]) {
				swap(list, i, j);			 
			}
		}
	}
}
/**
 * Funcion que clasifica la lista original de numeros en pares o impares.\n
 * Para ello, realizamos un simple calculo en el cual, dividimos cada numero por 2. Si el resto de esta division da como
 * resultado 0, tendremos que se trata de un numero par y lo guardamos en la lista evenNumbers. Por el contrario si el
 * resultado es distinto de 0, obtendremos un numero impar y lo guardaremos en oddNumbers.
 * @param list: Array de (TOTAL_NUM) numeros.
 * @param evenNumbers: Array donde se almacenan numeros pares.
 * @param oddNumbers:  Array donde se almacenan numeros impares.
 */
void evenOrOdd(int *list, int *evenNumbers, int *oddNumbers) {
	int j = 0;
	int k = 0;
	for(int i = 0; i < TOTAL_NUM; i++) {
		if((list[i] % 2) == 0) {
			evenNumbers[j] = list[i];
			j++;
		} else {
			oddNumbers[k] = list[i];
			k++;
		}
	}
}