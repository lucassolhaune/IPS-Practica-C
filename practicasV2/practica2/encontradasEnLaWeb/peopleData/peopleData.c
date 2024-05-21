/*Hacer una estructura que registre los datos de cinco personas como: Nombre, apellido, edad, sexo y teléfono.*/

#include <stdio.h>
#include <malloc.h>

#define TOTAL_PEOPLE 2
#define MAX_CHARACTERS 10

typedef struct person {
    char *name;
    char *surname;
    char sex;
    int age;
    long telNumber;
} Person;

void getData(Person *people);

int main() {
    Person *people = (Person *)malloc(TOTAL_PEOPLE * sizeof(Person));
    Person *pPeople = people;

    printf("Por favor ingrese los datos de las siguientes %d personas.\n", TOTAL_PEOPLE);
    getData(people);

    people = pPeople;

    printf("====================================\n");
    printf("Datos ingresados\n");

    for(int i = 0; i < TOTAL_PEOPLE; i++) {
        printf("Persona %i\n", i + 1);
        printf("\tNombre: %s", people->name);
        printf("\tApellido: %s", people->surname);
        printf("\tEdad: %d\n", people->age);
        printf("\tSexo: %c\n", people->sex);
        printf("\tNumero de teléfono: %ld\n", people->telNumber);

        people ++;
    }
    people = pPeople;
    free(people);

    return 0;
}

void getData(Person *people) {
    int c;
    for(int i = 0; i < TOTAL_PEOPLE; i++) {
        people->name = calloc(MAX_CHARACTERS, sizeof(char));
        people->surname = calloc(MAX_CHARACTERS, sizeof(char));
        printf("Persona %i\n", i + 1);

        printf("\tNombre: ");
        fgets(people->name, MAX_CHARACTERS, stdin);

        printf("\tApellido: ");
        fgets(people->surname, MAX_CHARACTERS, stdin);

        printf("\tEdad: ");
        scanf("%d", &people->age);

        printf("\tSexo [M/F]: ");
        scanf(" %c", &people->sex);
        while((people->sex != 'f' && people->sex != 'F') && (people->sex != 'm' && people->sex != 'M')) {
            printf("Ingrese el sexo correctamente [M/F]: ");
            scanf(" %c", &people->sex);
        }

        printf("\tNumero de teléfono: ");
        scanf("%ld", &people->telNumber);

        while ((c = getchar()) != '\n' && c != EOF) { }

        people ++;
    }
}