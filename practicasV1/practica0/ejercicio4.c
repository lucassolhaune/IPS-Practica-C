#include <stdio.h>
#include <stdlib.h>

#define ASC_ORDER 0     
#define DESC_ORDER 1
#define MAX_INDEX 50
#define ARRAY_SIZE 100

/**
 * ======================================Consigna=========================================
 * Programa que rellene un array con los numeros pares y otro con los impares 
 * comprendidos entre 1 y 100 y los muestre en pantalla en orden ascendente y descendente.
 * =======================================================================================
 */

/**
 * Funcion que llena un array de numeros del 1 al 100.
 * @param numbers array vacio de 100 posiciones.
 * @return Array completados con numeros del 1 al 100.
 */ 
int *generateArray(int *numbers) {
    for(int i = 0; i < 100; i++){
        numbers[i]=i+1;
    }
    return numbers;
}

/**
 * Partiendo del array que comprende la totalidad de numeros del 1 al 100, le pasamos a la funcion
 * dos arrays vacios, uno para los numeros pares y otro para numeros impares. La funcion realiza 
 * la division por 2 para cada numero del array total de numeros y si el resto de la division
 * es 0, ese numero se guarda en el array de los numeros pares. Si esto no se cumple, se guarda 
 * en el de los impares.
 * @param numbers Array con numeros del 1 al 100.
 * @param evenNum Array vacio donde se guardaran numeros pares.
 * @param oddNum Array vacio donde se guardaran numeros impares.
 * @param division Estructura para realizar la division y conocer el resto de la misma.
 * @return Dos arrays completados: uno con numeros pares y otro con numeros impares.
 */ 
int *getEvenOdd(int *numbers, int *evenNum, int *oddNum, div_t division) {
    int x = 0, y = 0;
    for(int i = 0; i < 100; i++) {
        division = div(numbers[i] , 2);
        if (division.rem == 0) {
            evenNum[x] = numbers[i];
            x++;
        }
        else{
            oddNum[y] = numbers[i];
            y++;
        }
    }
    return evenNum, oddNum;
}

/**
 * Muestra los numeros pares e impares ordenados de forma ascendente o descendente. 
 * Cuando order equivale a 0, los numeros de cualquier array se ordenan de forma 
 * ascendente y, por el contrario, cuando order equivale a 1, de forma descendente.
 * 
 * Nota: Para que no queden muchos numeros en un solo renglon, cada 10 numeros se sigue en la 
 * linea de abajo.
 * 
 * @param order El tipo de orden que se va a tener. 0 => Ascendente / 1 => Descendente.
 * @param maxIndex Indice maximo dentro de los for para realizar el ordenamiento correctamente.
 * @param arrayNum Array que se le pasa a la funcion para que lo ordene.
 * @param division Estructura para realizar la division y conocer el resto de la misma.
 */ 
void showArray (int order, int maxIndex, int *arrayNum, div_t division){
    if (order == 0) {
        printf("\t\t");
        for(int i = 0; i < maxIndex; i++) {    
            division = div(i + 1, 10);
            printf("%d", arrayNum[i]);
            if (i < 49) {
                printf(" , ");
                if (division.rem == 0) {
                    printf("\n\t\t");    
                }
            }
            else {
                printf(".\n");
            }
        }
    }
    else if (order == 1) {
        printf("\t\t");
        for(int i = maxIndex - 1; i >= 0; i--) {
            division = div(i, 10);    
            printf("%d", arrayNum[i]);
            if (i > 0) {
                printf(" , ");
                if (division.rem == 0) {
                printf("\n\t\t");    
                }
            }
            else {
                printf(".\n");
            }
        }
    } 
}

int main() { 

    //Array total de numeros
    int numbers[ARRAY_SIZE];

    //Array de numeros pares.
    int evenNum[ARRAY_SIZE];

    //Array de numeros impares.
    int oddNum[ARRAY_SIZE];

    //Estructura que se utilizara para la division.
    div_t division;

    generateArray(numbers);
    getEvenOdd(numbers, evenNum, oddNum, division);
    
    printf("\nNumeros pares:");
    printf("\n\tOrden ascendente:\n");
    showArray(ASC_ORDER, MAX_INDEX, evenNum, division);
    printf("\n\tOrden descendente:\n");
    showArray(DESC_ORDER, MAX_INDEX, evenNum, division);

    printf("\nNumeros impares:");
    printf("\n\tOrden ascendente:\n");
    showArray(ASC_ORDER, MAX_INDEX, oddNum, division);
    printf("\n\tOrden descendente:\n");
    showArray(DESC_ORDER, MAX_INDEX, oddNum, division);


    printf(".........................................................................................\n");
    return 0;
}