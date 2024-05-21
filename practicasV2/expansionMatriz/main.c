#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void expandir(int **matrix, int rows, int columns);
void showMatrix(int **, int, int);
int main() {
    const int rows = 3, columns = 4;
    int **matrix = (int **)malloc(rows * sizeof(int));

    srand(time(NULL));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            matrix[j] = (int *) malloc(columns * sizeof(int));
        }
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            matrix[i][j] = 1 + rand() % 9;
        }
    }

    printf("Matriz original\n");
    showMatrix(matrix, rows, columns);

    expandir(matrix, rows, columns);

    return 0;
}

void expandir(int **matrix, const int rows, const int columns) {
    const int newRows = rows + 1, newColumns = columns + 1;
    int **newMatrix = (int **)malloc(newRows * sizeof(int));

    for(int i = 0; i < newRows; i++) {
        for(int j = 0; j < newColumns; j++) {
            newMatrix[j] = (int *)malloc(newColumns * sizeof(int));
        }
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            newMatrix[i][j] = matrix[i][j];
        }
    }

    for(int i = 0; i < newRows; i++) {
        for(int j = 0; j < newColumns; j++) {
            if(newMatrix[i][j] == 0) {
                newMatrix[i][j] = 1 + rand() % 9;
            }
        }
    }
    printf("Matriz expandida\n");
    showMatrix(newMatrix, newRows, newColumns);
}
void showMatrix(int **matrix, const int rows, const int columns) {
    for(int i = 0; i < rows; i++) {
        printf("\t");
        for(int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}