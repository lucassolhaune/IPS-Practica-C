/*Realizar un programa que declare las variables x, y, z, les asigne los valores 10, 20 y 30 e intercambie entre sí
sus valores de forma que el valor de x pasa a y, el de y pasa a z y el valor de z pasa a x (se pueden declarar variables
auxiliares aunque se pide que se use el menor numero posible).*/

#include <stdio.h>

void exchange(int x, int y, int z);

int main() {
	int x = 10;
	int y = 20;
	int z = 30;

	exchange(x, y, z);

	return 0; 
}
/**
 * Función que intercambia valores entre si.
 * @param x
 * @param y
 * @param z
 */
void exchange(int x, int y, int z) {
	int tmp;

	tmp = x;
	x = z;
	z = y;
	y = tmp;

	printf("Valor de x: %d\nValor de y: %d\nValor de z: %d\n", x, y, z);	
}
