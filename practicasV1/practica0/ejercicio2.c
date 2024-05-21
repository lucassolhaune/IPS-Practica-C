#include <stdio.h>

/**
 * ==================================Consigna=========================================
 * Escriba un programa que lea por teclado diez numeros enteros distintos de
 * cero y a continuacion lea una secuencia de valores enteros indicando si estan
 * entre los diez valores leıdos. Cuando se lea el valor cero, el programa finalizara.
 * ===================================================================================
 */ 


/**
 * Input de los numeros de la lista.
 * Devuelve mensaje de error si se ingresa el numero 0 a la lista.
 * @param listNum Array vacio de 10 posiciones.
 */
void genList(int *listNum) {
    printf("Ingrese una lista de 10 numeros distintos de 0:\n");
    for(int i = 0; i < 10; i++) {
        printf("\t*> ");
        scanf("%d", &listNum[i]); 
        while(listNum[i] == 0) {
            printf("\tValor incorrecto. Intente nuevamente.\n"); 
            printf("\t*> ");
            scanf("%d", &listNum[i]);
        }
    }
}

/**
 * Muestra la lista de numeros ingresadas por el usuario.
 * @param listNum Array 10 posiciones con valores ingresados por teclado.
 */ 
void showList(int *listNum) {
    printf("\nLa lista de numeros ingresados es: ");
    for(int i = 0; i < 10; i++) {
        printf("%d", listNum[i]);
        //Luego de mostrar el ultimo numero del array, se ingresa un NewLine.
        //Sino, se escribe una coma entre numero y numero.
        if(i < 9) {
            printf(" , ");
        }
        else {
            printf("\n");
        }
    }
}

/**
 * Compara el numero que ingrese el usuario con la lista e imprime en pantalla
 * un mensaje indicando si el mismo se encuentra dentro de la lista.
 * @param listNum Array 10 posiciones con valores ingresados por teclado.
 * @param introducedNum Numero aleatorio ingresado por el usuario por fuera de la lista.
 */
void isInTheList( int *listNum, int introducedNum){
    for(int i = 0; i < 10; i++) {
        if(introducedNum == listNum[i]) {
            printf("%d esta en la lista.\n", introducedNum);
            break;
        }
    }
}

int main() {
    
    //Array para guardar los 10 numeros.
    int listNum[10];

    //Numero aleatorio que escribe el usaurio luego de la creacion de la lista.
    int userNum; 

    genList(listNum);
    showList(listNum);

    printf("Ingrese numeros aleatorios.\n");
    printf("\t0 = Exit.\n");
    do {
        printf("\t*> ");        
        scanf("%d", &userNum);
        isInTheList(listNum, userNum);
    } while(userNum != 0);

    return 0;
}



