#include <stdio.h>
#include <stdlib.h>
#include "lib/library.h"

int main() {
    char restart;
    int option, num;
    struct node *root = NULL;

    do {
        system("clear");
        printf("Ingrese una opcion a realizar en el arbol:\n");
        printf("\t1. Añadir un numero.\n");
        printf("\t2. ELiminar un numero.\n");
        printf("\t3. Mostrar arbol.\n");
        printf("\t4. Buscar un numero.\n");
        printf("\t5. Mostrar el valor maximo.\n");
        printf("\t6. Mostrar el valor minimo.\n");
        scanf("%d", &option);

        system("clear");
        switch (option) {
            case 1:
                system("clear");
                printf("Ingrese el numero que quiera agregar: ");
                scanf("%d", &num);
                root = insert(root, num);
                break;
            case 2:
                system("clear");
                printf("Ingrese el numero que desee eliminar: ");
                scanf("%d", &num);
                root = delete(root, num);
                break;
            case 3:
                system("clear");
                printf("Inorder:\n");
                inorder(root);
                printf("Preorder:\n");
                preorder(root);
                printf("Postorder:\n");
                postorder(root);
                break;
            case 4:
                system("clear");
                printf("Ingrese el numero que quiera buscar: ");
                scanf("%d", &num);
                if(isInTheTree(root, num)) {
                    printf("El numero %d se encuentra en el arbol.\n", num);
                } else {
                    printf("El numero %d no se ha encontrado en el arbol.\n", num);
                }
                break;
            case 5:
                system("clear");
                printf("El numero maximo del arbol es el %d\n", findMax(root)->data);
                break;
            case 6:
                system("clear");
                printf("El numero minimo del arbol es el %d\n", findMin(root)->data);
                break;
            default:
                printf("El valor ingresado no corresponde con ninguna de las opciones.\n");
                break;
        }
        printf("Desea realizar otra operacion [Y/N]: ");
        scanf(" %c", &restart);
    } while(restart != 'n' && restart != 'N');
    return 0;
}
