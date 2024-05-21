/*Que rellene un array con los 100 primeros numeros enteros y los muestre en pantalla en orden ascendente y luego
descendente.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TOTAL_NUM 100 

void listGen(int *list);
void printList(int *list);
void swap(int *list, int i, int j);
void ascendentOrder(int *list);
void descendentOrder(int *list);

int main() {
	int list[TOTAL_NUM];

	printf("Lista original:\n");
	listGen(list);
	printList(list);
	
	ascendentOrder(list);
	printf("\nLista ordenada de forma ascendente:\n");
	printList(list);

	descendentOrder(list);
	printf("\nLista ordenada de forma descendente:\n");
	printList(list);
	
	return 0;
}
/**
 * Funcion para generar una lista con (TOTAL_NUM) valores aleatorios.
 * @param list: Array de (TOTAL_NUM) numeros.
 */
void listGen(int *list) {
	srand(time(NULL));
	for (int i = 0; i < TOTAL_NUM; i++) {
		list[i] = rand() % TOTAL_NUM;
	}
}
/**
 * Funcion para mostrar en pantalla la lista generada en listGen().
 * @param list: Array de (TOTAL_NUM) numeros.
 */
void printList(int *list) {
//Muestro la lista en pantalla.
	for (int i = 0; i < TOTAL_NUM; i++) {
		if(i == (TOTAL_NUM - 1)) {
			printf("%d\n", list[i]);
		} else {
			printf("%d, ", list[i]);
		}
	}
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