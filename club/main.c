#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 20
#define BUF_SIZE 500

typedef struct persona {
    char *nombre, *apellido;
    char sexo, plan;
    int edad, mesesIns;
    double monto;
} Persona;

void escribeArchivo(FILE *archivo, Persona *personas, int totalPersonas);
void calcMontos(Persona *personas, int totalPersonas);
void agregaMonto(FILE *archivo, Persona *personas, char *lecturaLinea);
int main() {
    FILE *pointerPersFile;  //Puntero a archivo personas.txt
    pointerPersFile = fopen("personas.txt", "w");   //Abre el archivo personas.txt en modo escritura.
    int totalPersonas, planOptions, c;

    system("clear");
    printf("Cantidad de personas que desea agregar a la lista: ");
    scanf("%d", &totalPersonas);
    if(totalPersonas <= 0) {
        return 0;
    }

    //Espacio para las personas que se quieran almacenar.
    Persona *personas = (Persona *)malloc(totalPersonas * sizeof(Persona));
    Persona *pPersonas = personas;

    system("clear");
    printf("Ingrese los siguientes datos\n");

    //Toma los datos de las personas.
    for (int i = 0; i < totalPersonas; i++) {
        personas->nombre = (char *)malloc(MAX_CHAR * sizeof(char));
        personas->apellido = (char *)malloc(MAX_CHAR * sizeof(char));

        while((c = getchar()) != '\n' && c != EOF) { }  //Limpieza de buffer

        printf("Persona %d\n", i + 1);
        printf("\tNombre: ");
        fgets(personas->nombre, MAX_CHAR, stdin);
        personas->nombre[strcspn(personas->nombre, "\n")] = 0;  //Elimina el caracter newline.

        printf("\tApellido: ");
        fgets(personas->apellido, MAX_CHAR, stdin);
        personas->apellido[strcspn(personas->apellido, "\n")] = 0;  //Elimina el caracter newline.

        printf("\tEdad: ");
        scanf("%d", &personas->edad);

        while((c = getchar()) != '\n' && c != EOF) { }  //Limpieza de buffer

        do {
            printf("\tSexo [M/F]: ");
            scanf(" %c", &personas->sexo);
            getchar();
            personas->sexo = toupper(personas->sexo);   //Pasa a mayusculas el caracter ingresado.
        } while(personas->sexo != 'M' && personas->sexo != 'F');

        printf("\tMeses Inscripto: ");
        scanf("%d", &personas->mesesIns);

        while((c = getchar()) != '\n' && c != EOF) { }

        printf("\tSeleccione un plan.\n");
        do {
            printf("\t\tPresione:\n");
            printf("\t\t1. Plan A\n");
            printf("\t\t2. Plan B\n");
            printf("\t\t3. Plan C\n");
            printf("\t\t>>> ");
            scanf("%d", &planOptions);
            switch (planOptions) {
                case 1:
                    personas->plan = 'A';
                    break;
                case 2:
                    personas->plan = 'B';
                    break;
                case 3:
                    personas->plan = 'C';
                    break;
                default:
                    printf("\t\tError. El plan ingresado no es correcto.\n");
            }
        } while(planOptions < 1 || planOptions > 3);

        personas++;
    }
    personas = pPersonas;

    while((c = getchar()) != '\n' && c != EOF) { }  //Limpieza de buffer.

    escribeArchivo(pointerPersFile, personas, totalPersonas);   //Escribe los datos ingresados en personas.txt
    personas = pPersonas;
    calcMontos(personas, totalPersonas);    //Calcula los montos de los miembros en relacion a los planes elegidos.
    personas = pPersonas;
    fclose(pointerPersFile);    //Cierra el archivo personas.txt

    pointerPersFile = fopen("personas.txt", "r");  //Abre el archivo personas.txt en modo lectura
    FILE *pointerTmpFile = fopen("tmp.txt", "w");  //Abre el archivo tmp.txt en modo escritura.
    char *lecturaLinea = (char *)malloc(BUF_SIZE * sizeof(char));

    if((pointerPersFile == NULL) || (pointerTmpFile == NULL)) {
        printf("Error al abrir el archivo.\n");
        exit(-1);
    }

    //Lee linea por linea del archivo personas.txt y cada linea es almacenada en la variable lecturaLinea.
    //Luego, en el archivo tmp.txt se le agregan los montos por cada linea.
    for(int i = 0; i < totalPersonas; i++) {
        fgets(lecturaLinea, BUF_SIZE, pointerPersFile);
        lecturaLinea[strcspn(lecturaLinea, "\n")] = 0;  //Elimina el caracter newline.
        agregaMonto(pointerTmpFile, personas, lecturaLinea);
        personas ++;
    }
    fclose(pointerPersFile);    //Cierra el archivo personas.txt
    fclose(pointerTmpFile);     //Cierra el archivo tmp.txt
    pointerPersFile = fopen("personas.txt", "w");   //Abre personas.txt en modo escritura.
    pointerTmpFile = fopen("tmp.txt", "r");         //Abre tmp.txt en modo lectura.

    if((pointerPersFile == NULL) || (pointerTmpFile == NULL)) {
        printf("Error al abrir el archivo.\n");
        exit(-1);
    }

    //Sobreescribe el archivo personas.txt con las lineas de tmp.txt
    for(int i = 0; i < totalPersonas; i++) {
        fgets(lecturaLinea, BUF_SIZE, pointerTmpFile);
        fputs(lecturaLinea, pointerPersFile);
    }

    personas = pPersonas;
    free(personas);
    return 0;
}

/**
 * Escribe inicialmente los datos de las personas ingresadas por el usuario en el archivo indicado.
 *
 * @param archivo: archivo donde se ingresan los datos.
 * @param personas: personas ingresadas por el cliente.
 * @param totalPersonas: cantidad de personas ingresadas.
 */
void escribeArchivo(FILE *archivo, Persona *personas, int totalPersonas) {
    for(int i = 0; i < totalPersonas; i++) {
        fprintf(archivo, "%s %s - %d años - %c - Plan %c - %d meses\n", personas->nombre, personas->apellido,
                personas->edad, personas->sexo, personas->plan, personas->mesesIns);

        personas ++;
    }
}

/**
 * Calcula los montos que le corresponde a cada persona en relacion a los planes registrados en plan.txt.
 * Las personas que superen los 2 meses de inscripcion recibiran una bonificacion de:
 * - Plan A: %25
 * - Plan B: %30
 * - Plan C: %35.
 *
 * Ademas, si la persona es menor de 12 años o mayor de 65 años, recibe una bonificacion del %5 acumulable con
 * el descuento por los meses de inscripcion.
 *
 * @param personas: personas ingresadas por el cliente.
 * @param totalPersonas: cantidad de personas ingresadas.
 */
void calcMontos(Persona *personas, int totalPersonas) {
    for(int i = 0; i < totalPersonas; i++) {
        if(personas->mesesIns > 2) {
            switch (personas->plan) {
                case 'A':
                    personas->monto = 1000 - (1000*0.25);
                    break;
                case 'B':
                    personas->monto = 2250 - (2250*0.30);
                    break;
                case 'C':
                    personas->monto = 3500 - (3500*0.35);
                    break;
                default:
                    printf("Error. Plan no registrado.\n");
            }
        } else {
            switch (personas->plan) {
                case 'A':
                    personas->monto = 1000;
                    break;
                case 'B':
                    personas->monto = 2250;
                    break;
                case 'C':
                    personas->monto = 3500;
                    break;
                default:
                    printf("Error. Plan no registrado.\n");
            }
        }

        if(personas->edad < 12 || personas->edad > 65) {
            personas->monto = personas->monto - (personas->monto * 0.05);
        }

        personas ++;
    }
}

/**
 * Agrega una columna extra detallando a cada persona el monto total a abonar.
 *
 * @param archivo: archivo donde se ingresan los datos.
 * @param personas: personas ingresadas por el cliente.
 * @param lecturaLinea: linea donde se ingresa el monto total a pagar.
 */
void agregaMonto(FILE *archivo, Persona *personas, char *lecturaLinea) {
    fprintf(archivo, "%s - $%.2f\n", lecturaLinea, personas->monto);
}