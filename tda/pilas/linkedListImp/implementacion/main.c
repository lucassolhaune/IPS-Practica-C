#include <stdio.h>
#include <stdlib.h>
#include "../lib/library.h"

int main() {
    int choice, num;

    while(1) {
        printf("Elija una opcion.\n");
        printf("\t1. Añadir numero.\n");
        printf("\t2. Eliminar numero.\n");
        printf("\t3. Mostrar ultimo numero añadido.\n");
        printf("\t4. Mostrar stack en pantalla.\n");
        printf("\t5. Salir del programa.\n");
        printf("\t>>> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\t\tInserte el numero que desee añadir: ");
                scanf("%d", &num);
                push(num);
                break;
            case 2:
                printf("\t\t%d eliminado con exito.\n", pop());
                break;
            case 3:
                printf("El ultimo elemento añadido es el %d.\n", peek());
                break;
            case 4:
                print();
                break;
            case 5:
                exit(1);
            default:
                printf("Valor incorrecto.\n");
        }
    }
}