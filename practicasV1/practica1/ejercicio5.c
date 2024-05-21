#include <stdio.h>
#include <stdlib.h>

void importe(float kg, float precioKg);

int main() {
	float kg, precioKg;
	char restart;
	do {

		printf("A continuacion, ingrese la cantidad en Kg que haya adquirido de determinado producto\ny el precio por Kg de dicho producto\n");
		printf("\nKg: ");
		scanf("%f", &kg);

		printf("\nPrecio/kg: $ ");
		scanf("%f", &precioKg);

		importe(kg, precioKg);

		printf("\nDesea reintentar la operacion? Y/N:  ");
		scanf(" %c", &restart);

	} while(restart != 'n' || restart != 'N');

	return 0;
}

void importe(float kg, float precioKg) {

	//Calculo del importe.
	float importe = kg * precioKg;

	//Si el importe es mayor a $100, le descuento un 10%
	if(importe > 100) {
		printf("\nImporte sin descuento: $%f\n", importe);
		printf("\nDescuento: $%f\n", importe * 0.10);

		importe = importe - (importe * 0.10);
	}

	printf("\nMonto total a pagar: $%f\n", importe);
}
