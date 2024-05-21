#include <stdio.h>
#include <stdlib.h>
#include "lib/library.h"

int main() {
    int num, menu;
    char option;

    system("clear");
    printf("Ingrese numeros para ser añadidos a la cola.\n");
    do{
        printf("\t>>> ");
        scanf("%d", &num);
        enqueue(num);
        printf("\tDesea agregar otro? [Y/N]: ");
        scanf(" %c", &option);
    } while(option != 'n' && option != 'N');
    system("clear");
    do {
        system("clear");
        printf("Para realizar otras operaciones, pulse:\n");
        printf("\t1. Agregar mas numeros.\n");
        printf("\t2. Eliminar numeros.\n");
        printf("\t3. Mostrar cola.\n");
        scanf("%d", &menu);

        switch(menu) {
            case 1:
                do{
                    printf("\t>>> ");
                    scanf("%d", &num);
                    enqueue(num);
                    printf("\tDesea agregar otro? [Y/N]: ");
                    scanf(" %c", &option);
                } while(option != 'n' && option != 'N');
                break;
            case 2:
                printf("Numero %d eliminado de la cola.\n", dequeue());
                break;
            case 3:
                printf("Mostrando cola en pantalla...\n");
                printCola();
                break;
            default:
                printf("Error. El valor ingresado es incorrecto.\n");
                exit(1);
        }
        printf("Desea realizar otra operacion? [Y/N]: ");
        scanf(" %c", &option);
    } while(option != 'n' && option != 'N');
    system("clear");
    return 0;
}