#include <stdio.h>
#include <stdlib.h>
#define DAYS 3

void rainData(int *month);
void rainStats(int *month, int *maxRain, int *minRain, int *average);

int main() {
    int *month;
    int maxRain, minRain, average;

    month = (int *)malloc(DAYS * sizeof(int));
    maxRain = 0;
    average = 0;

    printf("Ingrese la cantidad en milimetros de agua caida en el mes\n");
    rainData(month);

    minRain = month[0];
    rainStats(month, &maxRain, &minRain, &average);

    printf("En el dia que mas llovio, hubo un total de %dml de agua\n", maxRain);
    printf("En el dia que menos llovio, hubo un total de %dml de agua\n", minRain);
    printf("En el mes, cayo un promedio de %dml de agua\n", average);

    return 0;
}

void rainData(int *month) {
    for(int i = 0; i < DAYS; i++) {
        printf("Dia %d\t> ", i+1);
        scanf("%d", &month[i]);
    }
}

void rainStats(int *month, int *maxRain, int *minRain, int *average) {
    int sum = 0;

    for(int i = 0; i < DAYS; i++) {
        if(month[i] > *maxRain) {
            *maxRain = month[i];
        } else if(month[i] < *minRain) {
            *minRain = month[i];
        }
    }
    for (int i = 0; i < DAYS; i++) {
        sum += month[i];
    }
    *average = sum / DAYS;
}
