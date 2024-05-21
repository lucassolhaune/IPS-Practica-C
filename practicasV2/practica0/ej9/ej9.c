#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STRING_SIZE 100

int vocalsCounter(char *string, int lengh);

int main() {
    char *string;
    int lengh;

    string = (char *)malloc(STRING_SIZE * sizeof(char));

    printf("Por favor, ingrese texto a continuacion.\n");
    fgets(string, STRING_SIZE, stdin);

    lengh = strlen(string);

    printf("El total de vocales en su texto es de %d\n", vocalsCounter(string, lengh));

    return 0;
}

int vocalsCounter(char *string, int lengh) {
    int vocals = 0;
    for(int i = 0; i < lengh; i ++) {
        string[i] = tolower(string[i]);
        if((string[i] == 'a') || (string[i] == 'e') || (string[i] == 'i') || (string[i] == 'o') ||(string[i] == 'u')) {
            vocals ++;
        }
    }
    return vocals;
}