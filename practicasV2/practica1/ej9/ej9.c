#include <stdio.h>
#include <stdlib.h>
int **identityMatrix(int arrayDimensions);

int main() {
    int arrayDimensions;
    int **array;
    
    printf("Ingrese las dimensiones que desee que tenga la matriz identidad: ");
    scanf("%d", &arrayDimensions);

    array = identityMatrix(arrayDimensions);
    for(int i = 0; i < arrayDimensions; i++) {
        for(int j = 0; j < arrayDimensions; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int **identityMatrix(int arrayDimensions) {
    int **identityMatrix = calloc(arrayDimensions, sizeof(int *));

    for(int i = 0; i < arrayDimensions; i++) {
        identityMatrix[i] = malloc(arrayDimensions * sizeof(int));
        for(int j = 0; j < arrayDimensions; j++) {
            if(i == j) {
                identityMatrix[i][j] = 1;
            } else {
                identityMatrix[i][j] = 0;
            }
        }
    }
    return identityMatrix;
}