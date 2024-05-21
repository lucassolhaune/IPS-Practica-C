#include <stdio.h>

/**
 * =================================Consigna=========================================
 * Realizar un programa que declare las variables x, y, z, les asigne los valores
 * 10, 20 y 30 e intercambie entre si sus valores de forma que el valor de x pasa a y,
 * el de y pasa a z y el valor de z pasa a x (se pueden declarar variables auxiliares
 * aunque se pide que se use el menor numero posible)
 * ==================================================================================
 */

int main() {

    int x = 10;
    int y = 20;
    int z = 30;

    printf("\nValores antes del intercambio:");
    printf("\n\tx = %d", x);
    printf("\n\ty = %d", y);
    printf("\n\tz = %d\n", z);


    int temp = x;
    x = z;
    z = y;
    y = temp;

    printf("\nValores despues del intercambio:");
    printf("\n\tx = %d", x);
    printf("\n\ty = %d", y);
    printf("\n\tz = %d\n", z);

    return 0;
}




