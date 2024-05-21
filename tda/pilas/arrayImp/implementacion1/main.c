#include <stdio.h>
#include <stdlib.h>
#include "lib/library.h"

int main() {
    int menu, element;

    system("clear");
    printf("============================================\n");
    printf("Ingrese alguna de las siguientes opciones.\n");
    printf("============================================\n");
    while(1) {
        printf("\t1. Agregar un elemento.\n");
        printf("\t2. Eliminar un elemento.\n");
        printf("\t3. Obtener el valor del ultimo elemento.\n");
        printf("\t4. Obtener el total de elementos en la lista.\n");
        printf("\t5. Mostrar la lista.\n");
        printf("\t6. Salir.\n");
        printf("> ");
        scanf("%d", &menu);
        switch (menu) {
            case 1:
                printf("Ingrese el elemento que desea agregar: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                element = pop(element);
                printf("Elemento %d eliminado con exito.\n", element);
                break;
            case 3:
                printf("El ultimo elemento en el stack es: %d.\n", peek());
                break;
            case 4:
                printf("La lista tiene un total de %d elementos.\n", size());
                break;
            case 5:
                printf("Mostrando stack en pantalla...\n");
                printStack();
                break;
            case 6:
                system("clear");
                return 1;
            default:
                printf("El valor ingresado no coincide con las opciones.\n");
                break;
        }
    }
}