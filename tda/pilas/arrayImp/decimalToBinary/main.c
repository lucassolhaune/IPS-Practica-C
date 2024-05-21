#include <stdio.h>
#include "../implementacion1/lib/library.h"

void conversion(int num);

int main() {
    int number;

    printf("Ingrese el numero que desee convertir a binario: ");
    scanf("%d", &number);
    conversion(number);

    return 0;
}
void conversion(int num) {
    int remainder, posCounter;
    while(num != 0) {
        remainder = num % 2;
        push(remainder);
        num = num / 2;
    }
    posCounter = 1;
    if(num >= 0) {
        printf("0");
    } else {
        printf("1");
    }
    while(top != -1) {
        posCounter++;
        printf("%d", pop());
        if(posCounter == 4) {
            printf(" ");
        }
    }
    printf("\n");
}