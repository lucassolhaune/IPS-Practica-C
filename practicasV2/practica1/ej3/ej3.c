#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUANTITY 10

int main() {
    int *numList;
    int *pNumList;
    int *pLastPos;

    numList =(int *)malloc(NUM_QUANTITY * sizeof(int));
    pNumList = numList;
    pLastPos = &numList[NUM_QUANTITY - 1];

    srand(time(NULL));
    for(int i = 0; i < NUM_QUANTITY; i++) {
        *numList = rand()%NUM_QUANTITY;
        numList++;
    }
    numList = pNumList;
    for(int i = 0; i < NUM_QUANTITY - 1; i++) {
        printf("%d, ", *numList);
        numList++;
    }
    printf("%d\n", *numList);
    numList = pLastPos;

    for(int i = 0; i < NUM_QUANTITY - 1; i++) {
        printf("%d, ", *numList);
        numList--;
    }
    printf("%d\n", *numList);
    numList = pNumList;
    free(numList);
    return 0;
}