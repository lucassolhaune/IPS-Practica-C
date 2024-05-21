//Trabajo de Leandro Gomez, comision 1.

#include <stdio.h>

/**
 * Estructura de la fraccion.
 */ 
typedef struct {
    int numerador, denominador;
} fraccion;

int mcd(fraccion *);

fraccion reduce(fraccion *); 

void muestraFraccion(fraccion);

int main() {
    fraccion f1 = {140, 26};
    fraccion f2 = {380, 44};
    fraccion f3 = {830, 675};
    muestraFraccion(reduce(&f1));
    muestraFraccion(reduce(&f2));
    muestraFraccion(reduce(&f3));

    return 0;
}

/**
 * Realiza calculos intermedios para definir el maximo comun divisor: 
 * 
 * Se divide el numerador con el denominador y el resto de dicha division es guardado dentro de la variable 'rest'. 
 * Luego se intercambian los valores de la siguiente manera: El numero que se encontraba en el denominador pasa al numerador, 
 * y el resto de la division toma el lugar del denominador.
 *  
 * @param fn Puntero a fraccion definida en main().
 * @return Resto de la division con valores intercambiados.
 */ 
int mcd(fraccion *fn) {
    int rest;

    //Guardo el resto de la division entre el numerador y el denominador.
    rest = fn->numerador % fn->denominador;

    //Intercambio de valores.
    fn->numerador = fn->denominador; 
    fn->denominador = rest; 

    return rest;
}

/**
 * Finaliza el calculo del mcd y reduce la fraccion: 
 * 
 * Ejecuta la funcion mcd() hasta que el resto sea igual a 0. 
 * Luego, se crea una nueva fraccion cuyo numerador y denominador van a ser divididos por el resultado final del mcd. 
 * 
 * Nota: El resultado final del mcd, es el ultimo valor que tiene el numerador cuando 'rest' es igual a 0. 
 * 
 * @param fn Puntero a fraccion definida en main().
 * @return Fraccion reducida.
 */ 
fraccion reduce(fraccion *fn) {
    int rest;

    //Conservo los valores originales del numerador y denominador.
    int initialNum = fn->numerador;
    int initialDen = fn->denominador;

    //Realizo los calculos de la funcion mcd() hasta que 'rest' sea igual a 0. 
    do {
        rest = mcd(fn);
    } while(rest > 0);

    //Defino e inicializo la nueva fraccion reducida, a partir de divisiones del numerador y denominador con el resultado final del mcd.
    fraccion redFraction = {initialNum / fn->numerador, initialDen / fn->numerador};

    return redFraction;
}

/**
 * Muestra la fraccion reducida.
 * @param redFraction Fraccion reducida.
 */  
void muestraFraccion(fraccion redFraction) {
    printf("\nFraccion reducida: %d / %d\n", redFraction.numerador, redFraction.denominador);
}
