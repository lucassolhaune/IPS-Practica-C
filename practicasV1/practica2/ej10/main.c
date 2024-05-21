#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int numeroDominio, numeroMotor, tamanioMotor;
	char *marca;
	char *modelo;
	char *color;
} Auto;

void crearAuto(Auto *carList, int i, int cant);

void cambiarColor(Auto *carList);

void mostrarAuto(Auto *carList);

int main() {
	Auto *carList;
	Auto *pCarList;
	Auto *modifCar;

	bool carCheck = false;
	int cant;
	char restart, option;

	do {
		printf("Ingrese la cantidad de autos que quiere agregar en la lista: ");
		scanf("%d", &cant);
		getchar();

		carList = (Auto *)malloc(cant * sizeof(Auto));
		pCarList = carList;
		modifCar = (Auto *)malloc(sizeof(Auto));

		for(int i = 0; i < cant; i++) {
			crearAuto(&carList[i], i, cant);
		}
		printf("\nLos autos ingresados son:\n");

		for(int i = 0; i < cant; i++) {
			mostrarAuto(&carList[i]);
		}

		printf("\nDesea cambiar el color de algun auto? [y/n]: ");
		scanf(" %c", &option);
		getchar();


		while (option == 'y' || option == 'Y') {

			do {
				printf("================================\n");
				printf("\tPatente: ");
				scanf("%d", &modifCar->numeroDominio);
				getchar();

				for(int i = 0; i < cant; i++) {
					if(modifCar->numeroDominio == carList->numeroDominio) {
						carCheck = true;
						cambiarColor(carList);
						printf("\nLista actualizada de autos:\n");
//						for(int i = 0; i < cant; i++) {
//							mostrarAuto(carList);
//							*carList++;
//						}
						continue;
					}

					carList++;
				}

			} while(carCheck == false);

			printf("\nDesea cambiar el color de otro auto? [y/n]: ");
			scanf(" %c", &option);
			getchar();

		}

		carList = pCarList;

		free(carList);
		carList = NULL;

		free(modifCar);
		modifCar = NULL;

		printf("\nPrograma finalizado. Desea reintentar? [y/n]: ");
		scanf(" %c", &restart);
		getchar();

	} while (restart == 'y' || restart == 'Y');
	return 0;
}

void crearAuto(Auto *carList, int i, int cant) {
	printf("\nIngrese los siguientes datos para el auto %d\n", i + 1);

	carList->marca = (char *)malloc((cant * 100) * sizeof(char));

	carList->modelo = (char *)malloc((cant * 100) * sizeof(char));

	carList->color = (char *)malloc((cant * 20) * sizeof(char));

	printf("\tMarca: ");
	fgets(carList->marca, 100, stdin);

	printf("\tModelo: ");
	fgets(carList->modelo, 100, stdin);

	printf("\tPotencia del motor (hp): ");
	scanf("%d", &carList->tamanioMotor);
	getchar();

	printf("\tColor: ");
	fgets(carList->color, 20, stdin);

	printf("\tNumero de la patente: ");
	scanf("%d", &carList->numeroDominio);
	getchar();

	while(carList->numeroDominio > 999) {
		printf("\nIngrese un valor correcto por favor: ");
		scanf("%d", &carList->numeroDominio);
		getchar();
	}

	printf("\tNumero grabado de motor: ");
	scanf("%d", &carList->numeroMotor);
	getchar();


}



void cambiarColor(Auto *carList) {
	printf("\nIngrese el nuevo color del %s: ", carList->marca);
	fgets(carList->color, 20, stdin);
}


void mostrarAuto(Auto *carList) {
	printf("================================\n");
	printf("\t%s\t%s\tPotencia: %d\tColor: %s\tDominio: %d\tNro Motor: %d\n", carList->marca, carList->modelo, carList->tamanioMotor, carList->color, carList->numeroDominio, carList->numeroMotor);

}
