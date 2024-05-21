#include <stdio.h>
#include <stdlib.h>
#include "lib/library.h"

int main() {
    int menu, data, pos;
    char subMenu, restart, option;
    system("clear");
    printf("\t\tInstrucciones de uso.\nEl programa consiste en crear una lista compuesta de numeros, totalmente "
           "personalizable a gustos del cliente.\nEl programa guiara su uso a traves de varios menus y submenus que el "
           "usuario debera completar de acuerdo a sus preferencias.\nPor favor, si desea continuar presione la tecla "
           "X. De lo contrario el programa finalizara.\n");
    scanf(" %c", &option);
    if(option != 'x' && option != 'X') {
        exit(1);
    }
    do {
        system("clear");
        printf("Ingrese:\n");
        printf("1. Agregar elementos.\n");
        printf("2. Eliminar elementos.\n");
        printf("3. Mostrar lista.\n");
        printf(">> ");
        scanf("%d", &menu);
        system("clear");

        switch(menu) {
            case 1:
                printf("Presione:\n");
                printf("a. Agregar al principio de la lista.\n");
                printf("b. Agregar en una posicion personalizada de la lista.\n");
                printf("c. Agregar al final de la lista.\n");
                printf(">> ");
                scanf(" %c", &subMenu);
                system("clear");
                switch(subMenu) {
                    case 'a':
                        printf("Ingrese el numero que desea agregar: ");
                        scanf("%d", &data);
                        add_at_beg(data);
                        printf("Resultado de la lista:\n");
                        printList();
                        break;
                    case 'b':
                        printf("Ingrese el numero que desea agregar: ");
                        scanf("%d", &data);
                        printf("Ingrese la posicion en que lo quiera agregar: ");
                        scanf("%d", &pos);
                        add_at_pos(data, pos);
                        printf("Resultado de la lista:\n");
                        printList();
                        break;
                    case 'c':
                        printf("Ingrese el numero que desea agregar: ");
                        scanf("%d", &data);
                        add_at_end(data);
                        printf("Resultado de la lista:\n");
                        printList();
                        break;
                    default:
                        printf("El valor ingresado no corresponde con ninguna de las opciones.\n");
                }
                break;
            case 2:
                printf("Presione:\n");
                printf("a. Eliminar el primer numero de la lista.\n");
                printf("b. Eliminar un numero en una posicion personalizada de la lista.\n");
                printf("c. Eliminar el ultimo numero de la lista.\n");
                printf(">> ");
                scanf(" %c", &subMenu);
                system("clear");
                switch(subMenu) {
                    case 'a':
                        printf("El numero %d ha sido eliminado con exito.\n", del_beg());
                        printf("Resultado de la lista:\n");
                        printList();
                        break;
                    case 'b':
                        printf("Ingrese la posicion del numero que quiera eliminar: ");
                        scanf("%d", &pos);
                        printf("El numero %d ha sido eliminado con exito.\n", del_pos(pos));
                        printf("Resultado de la lista:\n");
                        printList();
                        break;
                    case 'c':
                        printf("El numero %d ha sido eliminado con exito.\n", del_last());
                        printf("Resultado de la lista:\n");
                        printList();
                        break;
                    default:
                        printf("El valor ingresado no corresponde con ninguna de las opciones.\n");
                }
                break;
            case 3:
                printf("Mostrando lista en pantalla.\n");
                printList();
                break;
            default:
                printf("El valor ingresado no corresponde con ninguna de las opciones.\n");
        }
        printf("Desea realizar otra operacion? [Y/N]: ");
        scanf(" %c", &restart);
    } while(restart != 'n' && restart != 'N');

    return 0;
}
