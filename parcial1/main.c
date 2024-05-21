#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_STRING_SIZE 50
#define REPEATED_CHAR 5

char *eco (const char *cadena);
void elimSFinales(char *cad);
int **CrearMatriz(int col , int filas);

int main() {
    char *string = (char *)malloc(MAX_STRING_SIZE * sizeof(char));
    int filas, col;
    int **matriz;

    printf("Ingrese texto:\n");
    fgets(string, MAX_STRING_SIZE, stdin);
    printf("Texto con ultima letra repetida %d veces: %s\n", REPEATED_CHAR, eco(string));
    elimSFinales(string);

    printf("Para crear una matriz, por favor, ingrese:\n\tFilas: ");
    scanf("%d", &filas);
    printf("\tColumnas: ");
    scanf("%d", &col);

    matriz = CrearMatriz(col, filas);

    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    free(matriz);
    free(string);

    return 0;
}
char *eco (const char *cadena) {
    char *modifiedString = (char *)malloc((MAX_STRING_SIZE + REPEATED_CHAR) * sizeof(char));
    int lengh = strlen(cadena);

    int i, j;
    for(int p = 0; p < lengh; p++) {
        modifiedString[p] = cadena[p];
    }
    i = lengh - 1;
    j = i;

    if(cadena[i] == '\n') {
        for(int k = 0; k < REPEATED_CHAR; k++) {
            modifiedString[j] = cadena[i - 1];
            j++;
        }
    }
    return modifiedString;
}
void elimSFinales(char *cad) {
    for(int i = 0; i < strlen(cad); i++) {
        if((cad[i + 1] == 32) && (cad[i] == 's') || ((cad[i + 1] == '\n') && (cad[i] == 's'))) {
            cad[i] = ' ';
        }
    }
    printf("Texto sin 's' en las ultimas letras: %s\n", cad);
}
int **CrearMatriz(int col , int filas) {
    int **matriz = calloc(filas, sizeof(int));

    for(int i = 0; i < filas; i++) {
        matriz[i] = malloc(col * sizeof(int));
        for(int j = 0; j < col; j++) {
            matriz[i][j] = (i + 1) + (j + 1);
        }
    }
    return matriz;
}
