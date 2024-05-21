#include <stdio.h>
#include <string.h>
#include "string_tools.h"

#define TAM 90

int main() {
    char frase[TAM];
    printf("Ingrese la frase: ");
    readLine(frase,TAM);
    printf("%s\n",frase);
 
    int i = strlen(frase);
    int aux;
    for(i; i >= 0; i--) {
        if(frase[i] == ' ') {
            aux = i+1;
            while(frase[aux] != ' '){
                if(aux == strlen(frase))
                    break;
                printf("%c",frase[aux]);
                aux++;
            }
            printf(" ");
        }
        if(i == 0) {
            aux = i;
            while(frase[aux] != ' ') {
                printf("%c",frase[aux]);
                aux++;
            }
        }
    }
    printf("\n");
    return 0;
}
