/*Que se ingrese una frase en un arreglo y se invierta el orden de la misma guardandose en otro. Mostrar ambos arrays.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_SIZE 100

void inverter(char *phrase, char *invPhrase, int lengh);

int main() {
    char *phrase;
    char *invPhrase;
    int lengh;

    phrase = (char *)malloc(STRING_SIZE * sizeof(char));

    printf("Por favor, ingrese una frase. (Max. %d caracteres).\n", STRING_SIZE);
    fgets(phrase, STRING_SIZE, stdin);

    lengh = strlen(phrase);
    invPhrase = (char *)malloc(lengh * sizeof(char));

    inverter(phrase, invPhrase, lengh);

    printf("Largo: %d\n", lengh);
    printf("%s\n", invPhrase);

    free(phrase);
    free(invPhrase);
    return 0;
}

void inverter(char *phrase, char *invPhrase, int lengh) {
    int k, j;
    j = 0;
    for(int i = (lengh - 1); i >= 0; i--){
        if((phrase[i] == ' ') || (i == 0)){
            k = i + 1;
            if(i == 0){
                k = i;
            }
            do {
                invPhrase[j] = phrase[k];
                j++;
                k++;
            } while((phrase[k] != 32) && (phrase[k] != '\n'));
            invPhrase[j] = ' ';
            j++;
        }
    }
}