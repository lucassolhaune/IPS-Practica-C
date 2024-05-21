#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct matrix {
    int rows, columns;
    int **matrix;
} Matrix;
void reserveMatrixMemory(Matrix *matrix);
void randomValuesForMatrix(Matrix *matrix);
void showMatrix(Matrix *matrix);
void matrixGenerator(Matrix *matrix);
void sumMatrices(Matrix *matrix_1, Matrix *matrix_2, Matrix *sumResultMatrix);
int rowsComparison(Matrix *matrix_1, Matrix *matrix_2);
int columnsComparison(Matrix *matrix_1, Matrix *matrix_2);
int main() {
    Matrix *biDimensionMatrix = calloc(2, sizeof(Matrix));
    Matrix *pBiDimensionMatrix = biDimensionMatrix;
    Matrix *summedMatrices = calloc(1, sizeof(Matrix));

    srand(time(NULL));

    for(int i = 0; i < 2; i++) {
        printf("Matriz %d\n", i + 1);
        printf("\tFilas: ");
        scanf("%d", &biDimensionMatrix->rows);
        printf("\tColumnas: ");
        scanf("%d", &biDimensionMatrix->columns);

        matrixGenerator(biDimensionMatrix);

        biDimensionMatrix ++;
    }
    biDimensionMatrix = pBiDimensionMatrix;

    summedMatrices->rows = rowsComparison(&biDimensionMatrix[0], &biDimensionMatrix[1]);
    summedMatrices->columns = columnsComparison(&biDimensionMatrix[0], &biDimensionMatrix[1]);

    reserveMatrixMemory(summedMatrices);

    sumMatrices(&biDimensionMatrix[0], &biDimensionMatrix[1], summedMatrices);

    printf("Matriz resultado de la suma\n");
    showMatrix(summedMatrices);

    biDimensionMatrix = pBiDimensionMatrix;
    free(biDimensionMatrix);

    return 0;
}
void reserveMatrixMemory(Matrix *matrix) {
    matrix->matrix = (int **)malloc((matrix->rows * matrix->columns) * sizeof(int));

    for(int j = 0; j < matrix->rows; j++) {
        matrix->matrix[j] = calloc(matrix->rows, sizeof(int));
        for(int k = 0; k < matrix->columns; k++) {
            matrix->matrix[k] = calloc(matrix->columns, sizeof(int));
        }
    }
}
void randomValuesForMatrix(Matrix *matrix) {
    for(int j = 0; j < matrix->rows; j++) {
        for(int k = 0; k < matrix->columns; k++) {
            matrix->matrix[j][k] = rand() % 10;
        }
    }
}
void showMatrix(Matrix *matrix) {
    for(int j = 0; j < matrix->rows; j++) {
        printf("\t\t");
        for(int k = 0; k < matrix->columns; k++) {
            printf("%d ", matrix->matrix[j][k]);
        }
        printf("\n");
    }
}
void matrixGenerator(Matrix *matrix) {
    reserveMatrixMemory(matrix);
    randomValuesForMatrix(matrix);
    showMatrix(matrix);
}

void sumMatrices(Matrix *matrix_1, Matrix *matrix_2, Matrix *sumResultMatrix) {
    for(int i = 0; i < sumResultMatrix->rows; i++) {
        for(int j = 0; j < sumResultMatrix->columns; j++) {
            sumResultMatrix->matrix[i][j] = matrix_1->matrix[i][j] + matrix_2->matrix[i][j];
        }
    }
}
int rowsComparison(Matrix *matrix_1, Matrix *matrix_2) {
    if(matrix_1->rows != matrix_2->rows) {
        if (matrix_1->rows > matrix_2->rows) {
            return matrix_1->rows;
        } else if (matrix_2->rows > matrix_1->rows) {
            return matrix_2->rows;
        }
    }
    return matrix_1->rows;
}
int columnsComparison(Matrix *matrix_1, Matrix *matrix_2) {
    if(matrix_1->columns != matrix_2->columns) {
        if(matrix_1->columns > matrix_2->columns) {
            return matrix_1->columns;
        } else if(matrix_2->columns > matrix_1->columns) {
            return matrix_2->columns;
        }
    }
    return matrix_1->columns;
}
