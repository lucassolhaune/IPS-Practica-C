#include <stdio.h>

int main() {
    int i=5, j[]={1,2,3,4,5,6,7,8,9,10};
    char x = 'a', pal [] ="texto en c";
    int *pi;
    char *pc;

    printf("Sin usar pi\n\tDireccion de i: %p. Valor de i: %d\n", &i, i);
    pi = &i;
    printf("Usando pi\n\tDireccion de i: %p. Valor de i: %d\n", pi, *pi);
    printf("=======================================================\n");
    printf("Sin usar pi:\n");
    for(int p = 0; p < 9; p++) {
        printf("\tJ[%d]\tValor: %d\tDireccion:%p\n", p, j[p], &j[p]);
    }
    pi = j;
    printf("Usando pi:\n");
    for(int p = 0; p < 9; p++) {
        printf("\tJ[%d]\tValor: %d\tDireccion:%p\n", p, *pi, pi);
        pi++;
    }
    printf("=======================================================\n");
    printf("Sin usar pc\n\tDireccion de x: %p\tValor de x: %c\n", &x, x);
    pc = &x;
    printf("Usando pc\n\tDireccion de x: %p. Valor de x: %c\n", pc, *pc);
    printf("=======================================================\n");
    printf("Sin usar pc:\n");
    for(int p = 0; p < 11; p++) {
        printf("\tpal[%d]\tValor: %c\tDireccion: %p\n", p, pal[p], &pal[p]);
    }
    pc = pal;
    printf("Usando pc:\n");
    for(int p = 0; p < 11; p++) {
        printf("\tpal[%d]\tValor: %c\tDireccion: %p\n", p, *pc, pc);
        pc++;
    }
    printf("=======================================================\n");
    printf("Direccion de pi: %p\n", &pi);
    printf("Direccion de pc: %p\n", &pc);

    return 0;
}