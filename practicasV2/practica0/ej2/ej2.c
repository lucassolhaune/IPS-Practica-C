/*Escriba un programa que lea por teclado diez números enteros distintos de cero y a continuación lea una secuencia de
valores enteros indicando si están entre los diez valores leídos. Cuando se lea el valor cero, el programa finalizara.*/

#include <stdio.h>
#define LIST_SIZE 10

void listGen(int *numList);
void isInTheList(const int *numList);

int main() {
	int numList[LIST_SIZE];

	printf("Ingrese 10 valores distintos de 0:\n");
	listGen(numList);
	printf("\nIngrese números aleatorios y se informara si los mismos se encuentran en la lista.\nIngrese 0 para "
           "finalizar.\n");
	isInTheList(numList);
	return 0;
}
/**
 * Función para generar la lista de números.
 * @param numList: array de (LIST_SIZE) números el cual, sera completado mediante esta función.
 */
void listGen(int *numList) {
    //Pido al user (LIST_SIZE) números distintos de 0.
	for (int i = 0; i < LIST_SIZE; i++) {
		printf("> ");
		scanf("%d", &numList[i]);
        //Al ingresar un 0, se le pedirá otro número hasta que el mismo sea distinto de 0.
		while(numList[i] == 0) {
			printf("Por favor, ingrese un valor distinto de 0: ");
			scanf("%d", &numList[i]);
		}
	}
}
/**
 * Función para comparar si los números que se ingresan, se encuentran en la lista previamente armada en la función
 * listGen(). \n El user ingresara números hasta que el mismo sea igual a 0. \n Al ingresar 0, finaliza el programa.
 *
 * @param numList: array de (LIST_SIZE) números.
 */
void isInTheList(const int *numList) {
	int selectedNum = 1;
	while(selectedNum != 0) {
		printf("> ");
		scanf("%d", &selectedNum);
        //Comparo el número ingresado con cada posición de la lista.
		for(int i = 0; i < LIST_SIZE; i++) {
            //Si encuentra una coincidencia, se informa en pantalla.
			if(selectedNum == numList[i]) {
				printf("El numero %d se encuentra en la lista.\n", selectedNum);
				break;
			}
		}
	}
}
