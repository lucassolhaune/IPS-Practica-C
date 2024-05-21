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
        printf("\t1. Agregar un numero.\n");
        printf("\t2. Eliminar un numero.\n");
        printf("\t3. Obtener el valor del ultimo numero ingresado.\n");
        printf("\t4. Obtener el total de numeros almacenados en la lista.\n");
        printf("\t5. Mostrar la lista.\n");
        printf("\t6. Salir.\n");
        printf("> ");
        scanf("%d", &menu);
        switch (menu) {
            case 1:
                if(!isFull()) {
                    printf("Ingrese el elemento que desea agregar: ");
                    scanf("%d", &element);
                    push(element);
                } else {
                    printf("No se pueden agregar mas elementos a la lista.\n");
                }
                break;
            case 2:
                if(!isEmpty()) {
                    printf("Numero %d eliminado correctamente.\n", pop());
                } else {
                    printf("Lista vacia. No se pueden eliminar mas elementos.\n");
                }
                break;
            case 3:
                printf("El ultimo elemento en el stack es el numero %d.\n", peek());
                break;
            case 4:
                printf("La lista tiene un total de %d elementos.\n", size());
                break;
            case 5:
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