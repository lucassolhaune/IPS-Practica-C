#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_SIZE 100

void inverter(const char *phrase, char *tmpPhrase, int lengh);

int main() {
    char *phrase;
    char *tmpPhrase;
    int lengh;

    phrase = (char *)malloc(STRING_SIZE * sizeof(char));

    printf("Por favor, ingrese una frase. (Max. %d caracteres).\n", STRING_SIZE);
    fgets(phrase, STRING_SIZE, stdin);

    lengh = strlen(phrase);
    tmpPhrase = (char *)malloc(lengh * sizeof(char));

    inverter(phrase, tmpPhrase, lengh);
    phrase = tmpPhrase;

    printf("Largo: %d\n", lengh);
    printf("%s\n", phrase);

    free(phrase);
    return 0;
}

void inverter(const char *phrase, char *tmpPhrase, int lengh) {
    int k, j;
    j = 0;
    for(int i = (lengh - 1); i >= 0; i--){
        if((phrase[i] == ' ') || (i == 0)){
            k = i + 1;
            if(i == 0){
                k = i;
            }
            do {
                tmpPhrase[j] = phrase[k];
                j++;
                k++;
            } while((phrase[k] != 32) && (phrase[k] != '\n'));
            tmpPhrase[j] = ' ';
            j++;
        }
    }
}