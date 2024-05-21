#include <stdio.h>
#include <string.h>

struct Dias {
    int num;
    char dia[10];
};

int main() {
    char inputDia[7][2];    //Array bidimensional donde se guarda el dia ingresado por teclado.
    struct Dias dias[7];    //Array de dias predefinidos.
    for(int i = 0; i < 7; i++) {
        switch(i) {
            case 0:
                strcpy(dias[i].dia, "Lunes\n");
                dias[i].num = i + 1;
                break;
            case 1:
                strcpy(dias[i].dia, "Martes\n");
                dias[i].num = i + 1;
                break;
            case 2:
                strcpy(dias[i].dia, "Miercoles\n");
                dias[i].num = i + 1;
                break;
            case 3:
                strcpy(dias[i].dia, "Jueves\n");
                dias[i].num = i + 1;
                break;
            case 4:
                strcpy(dias[i].dia, "Viernes\n");
                dias[i].num = i + 1;
                break;
            case 5:
                strcpy(dias[i].dia, "Sabado\n");
                dias[i].num = i + 1;
                break;
            case 6:
                strcpy(dias[i].dia, "Domingo\n");
                dias[i].num = i + 1;
                break;
        }
    }
    int k;          //Contador
    int checkDia;   //Variable de chequeo para definir si coinciden los dos dias.

    //Tomo el input por teclado y comparo si lo ingresado coincide con algun dia predefinido.
    //De ser asi, le aviso al usuario y salgo del loop. Si no encuentra ningun dia que coincida,
    //asigno la variable de chequeo en 1 para luego, informar que no se encontro ese dia.
    printf("Ingrese 7 dias:\n");
    for(int i = 0; i < 7; i++) {
        k = 0;
        printf("> ");
        fgets(&inputDia[i][0], 12, stdin);
        do {
            if(strcmp(dias[k].dia, &inputDia[i][0]) == 0) {
                checkDia = 0;
                printf("Se encuentra en la lista\n");
                break;
            } else {
                checkDia = 1;
            }
            k++;
        } while(k < 7);
        if(checkDia == 1) {
            printf("No se encuentra en la lista.\n");
        }
    }
    return 0;
}