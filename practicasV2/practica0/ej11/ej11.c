#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_SIZE 100

void mayusCounter(char *string, int lengh, int *mayus);

int main() {
    char *string;
    int mayus, lengh;

    string = (char *)malloc(STRING_SIZE * sizeof(char));
    printf("Por favor, ingrese texto\n");
    fgets(string, STRING_SIZE, stdin);

    lengh = strlen(string);
    mayus = 0;
    mayusCounter(string, lengh, &mayus);

    printf("En el texto ingresado se encontraron %d letras en mayusculas.\n", mayus);
    return 0;
}

void mayusCounter(char *string, int lengh, int *mayus) {
    for(int i = 0; i < lengh; i++) {
        if((string[i] >= 65) && (string[i] <= 90)) {
            *mayus = *mayus + 1;
        }
    }
}
