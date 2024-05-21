#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MATRIX_SIZE 9

int main() {
    int **matrix = (int **)malloc(MATRIX_SIZE * sizeof(int));
    int diagonalSize = sqrt(MATRIX_SIZE);
    int *diagonal = (int *)malloc(diagonalSize * sizeof(int));
    int sum;

    srand(time(NULL));

    for(int i = 0; i < diagonalSize; i++) {
        matrix[i] = malloc(sizeof(int));
        for(int j = 0; j < diagonalSize; j++) {
            matrix[j] = malloc(sizeof(int));
        }
    }

    for(int i = 0; i < diagonalSize; i++) {
        for(int j = 0; j < diagonalSize; j++) {
            matrix[i][j] = 1 + rand() % 9;
        }
    }
    printf("Matriz original\n");

    for(int i = 0; i < diagonalSize; i++) {
        printf("\t");
        for(int j = 0; j < diagonalSize; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < diagonalSize; i++) {
        diagonal[i] = matrix[i][i];
    }
    sum = diagonal[0];

    for(int i = 1; i < diagonalSize; i++) {
        sum += diagonal[i];
    }
    printf("Traza de la matriz: %d\n", sum);

    printf("Matriz transpuesta\n");

    for(int i = 0; i < diagonalSize; i++) {
        printf("\t");
        for(int j = 0; j < diagonalSize; j++) {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }

    return 0;
}
