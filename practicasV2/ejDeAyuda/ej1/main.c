#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

struct Semana {     //Estructura de una semana.
    int num;        //Numero del dia de la semana.
    char dia[11];   //Nombre del dia de la semana.
};
bool validacionNombreDia(char *inputNombreDia); //Funcion para validar el nombre ingresado por el usuario.
int valoresDias(char *inputNombreDia);          //Funcion para asignar el numero correspondiente a cada dia.
int main() {
    int dia;                //Variable donde se guarda el numero ingresado por teclado a comparar.
    char opc;               //Variable donde se almacena la decision del usuario de continuar ingresando numeros o no.
    struct Semana dias[5];  //Array donde se almacenan los dias de la semana.

    printf("Ingrese 5 dias de la semana:\n");
    //Ingreso por teclado los 5 dias que quiero guardar en el array.
    for(int i = 0; i < 5; i++) {
        printf("\t> ");
        fgets(dias[i].dia, 11, stdin);

        //A la primera letra ingresada por el usuario la transformo a mayusculas, y al resto, a minusculas.
        //De esta forma, mientras no haya errores de ortografia ni se escriba un nombre de dia inexistente,
        // se tomara de forma correcta independientemente del tipo de letras ingresadas.
        dias[i].dia[0] = toupper(dias[i].dia[0]);
        for(int j = 1; j < (strlen(dias[i].dia) - 1); j++) {
            dias[i].dia[j] = tolower(dias[i].dia[j]);
        }
        //Chequeo si lo ingresado por el usuario es correcto y repito la transformacion de los tipos de letras
        //al ingresar un nuevo input.
        while(validacionNombreDia(dias[i].dia) == false) {
            printf("Error de escritura.\n\tIngrese el dia nuevamente: ");
            fgets(dias[i].dia, 11, stdin);
            dias[i].dia[0] = toupper(dias[i].dia[0]);
            for(int j = 1; j < (strlen(dias[i].dia) - 1); j++) {
                dias[i].dia[j] = tolower(dias[i].dia[j]);
            }
        }
        //Asigno al dia ingresado por el usuario, su numero de la semana correspondiente.
        dias[i].num = valoresDias(dias[i].dia);
    }
    do {
        //Ingreso un numero aleatorio por teclado, valido que se encuentre entre 1 y 7 y, de ser correcto,
        //informo el nombre y numero del dia de la semana que le corresponde.
        printf("Ingrese numero del dia para ver las coincidencias: ");
        scanf("%d", &dia);
        //Verificacion del numero ingresado.
        while(dia != 1 && dia != 2 && dia != 3 && dia != 4 && dia != 5 && dia != 6 && dia != 7) {
            printf("El numero ingresado debe estar entre 1 y 7: ");
            scanf("%d", &dia);
        }
        int i = 0;
        int cont = 0;
        //Muestra de dias coincidentes. Recorro array de dias y, en caso de ser iguales el numero ingresado por
        //el usuario al de algun dia guardado en la lista, lo muestro en pantalla junto a su nombre.
        printf("\tCoincidencias: ");
        while(i < 5) {
            if(dia == dias[i].num) {
                printf("%i. %s", dias[i].num, dias[i].dia);
                cont++;
            }
            i++;
        }
        //Informo si no se encontro ningun numero coincidente.
        if(cont == 0) {
            printf("No se encontro ninguna coincidencia.\n");
        }
        //Opcion de repetir el proceso con otro numero. Si se ingresa un valor distinto a Y, finaliza el programa.
        //*Nota: La 'y' puede estar tanto en mayusculas como minusculas.
        printf("Desea ingresar otro numero? [Y/N]: ");
        scanf(" %c", &opc);
    } while(opc == 'y' || opc == 'Y');

    return 0;
}

/**
 * Esta funcion compara el nombre ingresado por teclado con los dias de la semana. De esta manera
 * evaluamos tanto la ortografia como el ingreso de un nombre existente.
 *
 * @param inputNombreDia: Dato ingresado por teclado a comparar con los dias de la semana.
 * @return true: Los datos fueron ingresados correctamente.
 *         false: Dato ingresado erroneamente.
 */
bool validacionNombreDia(char *inputNombreDia) {
    if((strcmp(inputNombreDia, "Lunes\n") == 0) || (strcmp(inputNombreDia, "Martes\n") == 0) ||
       (strcmp(inputNombreDia, "Miercoles\n") == 0) || (strcmp(inputNombreDia, "Jueves\n") == 0) ||
       (strcmp(inputNombreDia, "Viernes\n") == 0) || (strcmp(inputNombreDia, "Sabado\n") == 0) ||
       (strcmp(inputNombreDia, "Domingo\n") == 0)) {
        return true;
    } else {
        return false;
    }
}
/**
 * Mediante esta funcion le asignamos el numero del dia de la semana correspondiente al dia ingresado por el usuario,
 * validado previamente. A pesar de esto ultimo, por las dudas devuelve una salida con error en caso de no
 * coincidir con ningnun valor.
 *
 * @param inputNombreDiaDato: ingresado por teclado ya validado.
 * @return numero de dia de la semana perteneciente al dia ingresado.
 */
int valoresDias(char *inputNombreDia) {
    if(strcmp(inputNombreDia, "Lunes\n") == 0) {
        return 1;
    } else if (strcmp(inputNombreDia, "Martes\n") == 0) {
        return 2;
    } else if (strcmp(inputNombreDia, "Miercoles\n") == 0) {
        return 3;
    } else if (strcmp(inputNombreDia, "Jueves\n") == 0) {
        return 4;
    } else if (strcmp(inputNombreDia, "Viernes\n") == 0) {
        return 5;
    }else if(strcmp(inputNombreDia, "Sabado\n") == 0) {
        return 6;
    } else if(strcmp(inputNombreDia, "Domingo\n") == 0) {
        return 7;
    } else {
        printf("Error. El nombre ingresado no coincide con ningun dia de la semana.\n");
        exit(-1);
    }
}