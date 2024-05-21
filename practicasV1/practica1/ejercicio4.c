#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

char * dayOfTheWeek(int dayNum, char *dayName) {

	switch (dayNum) {
		case 1:
			dayName = "Lunes";
		 	break;
		case 2:
			dayName = "Martes";
			break;
		case 3:
			dayName = "Miercoles";
			break;
		case 4:
			dayName = "Jueves";
			break;
		case 5:
			dayName = "Viernes";
			break;
		case 6:
			dayName = "Sabado";
			break;
		case 7:
			dayName = "Domingo";
			break;
		default :
			printf("\nEscribi bien pelotudo.\n");
			exit(EXIT_FAILURE);
			break;
	}

	return dayName;
}

int main() {
	int dayNum;
	char *dayName;
	char *originalPointer;

	//Reservo espacio para el dia con nombre mas largo (miercoles).
	dayName = (char *)malloc(9 * sizeof(char));

	//Guardo la direccion donde apunta el puntero originalmente.
	originalPointer = dayName;

	printf("Ingrese un numero del 1 al 7, correspondiente al dia que respresenta. >>  ");
	scanf("%d", &dayNum);

	dayName = dayOfTheWeek(dayNum, dayName);

	printf("\nEl dia correspondiente al numero %d es el dia %s\n", dayNum, dayName);

	//Regreso el puntero a la direccion original y lo libero.
	dayName = originalPointer;

	free(dayName);
	dayName = NULL;

	return 0;
}

