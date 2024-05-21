#include <stdio.h>

/**
 * ===================================Consigna========================================
 * Programa que rellene un array con los 100 primeros numeros enteros y los muestre en
 * pantalla en orden ascendente y luego descendente.
 * ===================================================================================
 */

/**
 * Imprime en pantalla los primeros 100 numeros (0-99) ordenados en orden ascendente. 
 * @param hundred array de 100 posiciones
 */ 
void up(int *hundred) {

    printf("\n=====================================================================\n");
    printf("Estas viendo los primeros 100 numeros ordenados de forma ascendente:\n");
    printf("=> "); 
    for(int i = 0; i < 100; i++) {
        hundred[i] = i;
        printf("%d", hundred[i]);
        if (i < 99) {
            printf(" , ");
        }
        else {
            printf("\n");
        }
    }

} 

/**
 * Imprime en pantalla los primeros 100 numeros (0-99) ordenados en orden ascendente. 
 * @param hundred array de 100 posiciones
 */ 
void down(int *hundred) {

    printf("\n=====================================================================\n");
    printf("Ahora, los primeros 100 numeros ordenados de forma descendente:\n");
    printf("=> "); 
    for(int i = 99; i >= 0; i--) {
        hundred[i] = i;
        printf("%d", hundred[i]);
        if (i > 0) {
            printf(" , ");
        }
        else {
            printf("\n");
        }
    }
}

int main() {

    //Array donde se guardan los 100 primeros numeros.
    int firstHundred[100];
    //Contador.
    int i;

    up(firstHundred);

    down(firstHundred);

    return 0;

}
