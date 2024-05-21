#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHAR 10
#define TOTAL_EMPLOYEES 2

typedef struct tm Date;

typedef struct employee {
    char *name;
    char *lastName;
    int age;
    Date dateOfBirth;
} Employee;

void dataInput(Employee *employees);
int ageCalc(Employee *employees);
void showData(Employee *employees);

int main() {
    Employee *employees = (Employee *) malloc(TOTAL_EMPLOYEES * sizeof(Employee));
    dataInput(employees);
    showData(employees);

    return 0;
}

/*
 * Con esta funcion, tomo los datos de cada empleado.
 * @param Employee *employees: Estructura donde se almacenan los datos de los empleados.
 */
void dataInput(Employee *employees) {
    int c;

    printf("Por favor, ingrese los siguientes datos:\n");
    for (int i = 0; i < TOTAL_EMPLOYEES; i++) {
        employees->name = calloc(MAX_CHAR, sizeof(char));
        employees->lastName = calloc(MAX_CHAR, sizeof(char));

        printf("Empleado N°%d\n", i + 1);
        printf("\tNombre: ");
        fgets(employees->name, MAX_CHAR, stdin);
        printf("\tApellido: ");
        fgets(employees->lastName, MAX_CHAR, stdin);
        printf("\tFecha de nacimiento\n");
        printf("\t\tAño: ");
        scanf("%d", &employees->dateOfBirth.tm_year);
        printf("\t\tMes: ");
        scanf("%d", &employees->dateOfBirth.tm_mon);
        printf("\t\tDia: ");
        scanf("%d", &employees->dateOfBirth.tm_mday);
        ageCalc(employees);
        printf("\tEdad: %d años.\n", employees->age);

        while ((c = getchar()) != '\n' && c != EOF) { }

        employees ++;
    }
}
/*
 * La funcion algCalc() calcula la edad de cada empleado teniendo en cuenta su fecha de nacimiento y
 * a la fecha actual. Es decir, si un empleado todavía no cumplió los años al momento de la fecha,
 * se calcula su edad restándole 1 a la diferencia entre el año actual y el de nacimiento.
 */
int ageCalc(Employee *employees) {
    Date *tm;
    time_t t;

    t = time(NULL);
    tm = localtime(&t);
    tm->tm_year = tm->tm_year + 1900;

    if(tm->tm_mon == employees->dateOfBirth.tm_mon) {
        if(tm->tm_mday > employees->dateOfBirth.tm_mday) {
            employees->age = tm->tm_year - employees->dateOfBirth.tm_year;
        } else {
            employees->age = (tm->tm_year - employees->dateOfBirth.tm_year) - 1;
        }
    } else if (tm->tm_mon > employees->dateOfBirth.tm_mon){
        employees->age = tm->tm_year - employees->dateOfBirth.tm_year;
    } else {
        employees->age = (tm->tm_year - employees->dateOfBirth.tm_year) - 1;
    }
    return employees->age;
}
void showData(Employee *employees) {
    printf("==============================================\n");
    printf("Informacion ingresada sobre los empleados:\n");
    for (int i = 0; i < TOTAL_EMPLOYEES; i++) {
        printf("Empleado N°%d\n", i + 1);
        printf("\tNombre: %s", employees->name);
        printf("\tApellido: %s", employees->lastName);
        printf("\tFecha de nacimiento: %d/%d/%d\n", employees->dateOfBirth.tm_mday, employees->dateOfBirth.tm_mon,
               employees->dateOfBirth.tm_year);
        printf("\tEdad: %d años.\n", employees->age);
        employees++;
    }
}