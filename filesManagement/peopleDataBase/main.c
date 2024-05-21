#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 20

typedef struct person {
    char *name, *surname, *age;
} Person;

int findMaxName(Person *people, int totalPeople);
int findMaxSurname(Person *people, int totalPeople);
void writeFile(FILE *file, Person *people, int totalPeople, int maxNameLength, int maxSurnameLength);
int main() {
    FILE *fPointer;
    fPointer = fopen("archivo1.txt", "w");
    int totalPeople;

    printf("Cantidad de personas que desea agregar a la lista: ");
    scanf("%d", &totalPeople);

    Person *people = (Person *)malloc(totalPeople * sizeof(Person));
    Person *pPeople = people;

    printf("Ingrese los siguientes datos\n");

    for (int i = 0; i < totalPeople; i++) {
        people->name = (char *)malloc(MAX_CHAR * sizeof(char));
        people->surname = (char *)malloc(MAX_CHAR * sizeof(char));
        people->age = (char *)malloc(3 * sizeof(char));

        int c;
        while((c = getchar()) != '\n' && c != EOF) { }

        printf("Persona %d\n", i + 1);
        printf("\tNombre: ");
        fgets(people->name, MAX_CHAR, stdin);
        people->name[strcspn(people->name, "\n")] = 0;

        printf("\tApellido: ");
        fgets(people->surname, MAX_CHAR, stdin);
        people->surname[strcspn(people->surname, "\n")] = 0;

        printf("\tEdad: ");
        fgets(people->age, 3, stdin);
        people->age[strcspn(people->age, "\n")] = 0;

        people++;
    }
    people = pPeople;

    writeFile(fPointer, people, totalPeople, findMaxName(people, totalPeople),
              findMaxSurname(people,totalPeople));

    people = pPeople;
    free(people);
    fclose(fPointer);
    return 0;
}
int findMaxName(Person *people, int totalPeople) {
    int max = 0;
    int temp;
    for(int i = 0; i < totalPeople; i++) {
        temp = (int)strlen(people->name);
        if(temp > max)
            max = temp;
        people ++;
    }
    return max;
}
int findMaxSurname(Person *people, int totalPeople) {
    int max = 0;
    int temp;
    for(int i = 0; i < totalPeople; i++) {
        temp = (int)strlen(people->surname);
        if(temp > max)
            max = temp;
        people ++;
    }
    return max;
}

void writeFile(FILE *file, Person *people, int totalPeople, int maxNameLength, int maxSurnameLength) {

    int blankNameSpaces, blankSurnameSpaces;

    fprintf(file, "Nombre%*s", maxNameLength, "");
    fprintf(file, "Apellido%*s", maxSurnameLength, "");
    fprintf(file, "Edad\n");

    fprintf(file, "------%*s", maxNameLength, "");
    fprintf(file, "--------%*s", maxSurnameLength, "");
    fprintf(file, "----\n");

    for(int i = 0; i < totalPeople; i++) {
        blankNameSpaces = (int)(maxNameLength - strlen(people->name));
        blankSurnameSpaces = (int)(maxSurnameLength - strlen((people->surname)));
        fprintf(file, "%s%*s\t\t",people->name, blankNameSpaces, "");
        fprintf(file, "%s%*s\t\t\t", people->surname, blankSurnameSpaces, "");
        fprintf(file, "%s\n", people->age);

        people ++;
    }
}