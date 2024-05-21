#include <stdio.h>
#include <stdlib.h>

#define DAY_LONGEST_NAME 10

char *dayOfTheWeek(int dayNumber);

int main() {
    int dayNumber;
    char *dayName;

    printf("Ingrese un numero del 1 al 7: ");
    scanf("%d", &dayNumber);
    dayName = dayOfTheWeek(dayNumber);
    printf("El numero %d de la semana corresponde al dia %s.\n", dayNumber, dayName);

    return 0;
}

char *dayOfTheWeek(int dayNumber) {
    char *dayString;
    dayString = (char *) malloc(DAY_LONGEST_NAME * sizeof(char));

    switch (dayNumber) {
        case 1:
            dayString = "Lunes";
            break;
        case 2:
            dayString = "Martes";
            break;
        case 3:
            dayString = "Miercoles";
            break;
        case 4:
            dayString = "Jueves";
            break;
        case 5:
            dayString = "Viernes";
            break;
        case 6:
            dayString = "Sabado";
            break;
        case 7:
            dayString = "Domingo";
            break;
        default:
            printf("Valor incorrecto.");

    }
    return dayString;
}
