// euclides .c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numerador, denominador;
} fraccion ;

int mcd(fraccion *); // calcula el minimo comun divisor y lo retorna
fraccion reduce(fraccion *); // retorna la fraccion reducida
void muestraFraccion(fraccion); // imprime por pantalla los valores
int main () {
    fraccion f1 = {140, 26};
    fraccion f2 = {380, 44};
    fraccion f3 = {830, 675};

    printf("Fracciones reducidas:\n");
    printf("%d/%d >> ", f1.numerador, f1.denominador);
    muestraFraccion(reduce(&f1));
    printf("%d/%d >> ", f2.numerador, f2.denominador);
    muestraFraccion(reduce(&f2));
    printf("%d/%d >> ", f3.numerador, f3.denominador);
    muestraFraccion(reduce(&f3));

    return 0;
}
int mcd(fraccion *fx) {
    int a, b, r;
    if(fx->numerador > fx->denominador) {
        a = fx->numerador;
        b = fx->denominador;
    } else {
        a = fx->denominador;
        b = fx->numerador;
    }

    while(b != 0) {
        r = div(a, b).rem;
        a = b;
        b = r;
    }
    return a;
}
fraccion reduce(fraccion *fx) {
    fraccion reducedFrac = *fx;

    reducedFrac.numerador = fx->numerador / (mcd((fx)));
    reducedFrac.denominador = fx->denominador / (mcd((fx)));

    return reducedFrac;
}

void muestraFraccion(fraccion reducedFx) {
    printf("%d/%d\n", reducedFx.numerador, reducedFx.denominador);
}