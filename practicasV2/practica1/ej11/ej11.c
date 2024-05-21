#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int ** producto_Escalar_Matriz(int fil, int col, int esc, int **matriz);

int main() {
    int **matriz;
    int fil, col, esc;

    printf("Ingrese:\n\tValor escalar de la matriz: ");
    scanf("%d", &esc);
    printf("\tDimensiones de la matriz\n");
    printf("\t\tFilas: ");
    scanf("%d", &fil);
    printf("\t\tColumnas: ");
    scanf("%d", &col);

    matriz = calloc(fil, sizeof(int *));
    for(int i = 0; i < fil; i++) {
        matriz[i] = malloc(col * sizeof(int));
    }
    matriz = producto_Escalar_Matriz(fil, col, esc, matriz);

    for(int i = 0; i < fil; i++) {
        printf("\t\t\t");
        for (int j = 0; j < col; ++j) {
            printf("\t%d ", matriz[i][j]);
        }
        printf("\n");
    }

    free(matriz);
    return 0;
}

int ** producto_Escalar_Matriz(int fil, int col, int esc, int **matriz) {
    int **newMatrix = matriz;

    srand(time(NULL));

    for(int i = 0; i < fil; i++) {
        for(int j = 0; j < col; ++j) {
            newMatrix[i][j] = (1 + (rand() % 10)) * esc;
        }
    }
    return newMatrix;
}