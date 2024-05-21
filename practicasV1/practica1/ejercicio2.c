#include <stdio.h>

/**
 * ===================================Consigna====================================
 * Escriba un programa que defina las siguientes variables:
 *      int i=5, j[]={1,2,3,4,5,6,7,8,9,10};
 *      char x = 'a', pal [] ="texto en c";
 *      int *pi;
 *      char *pc;
 * 
 * 1. Mostrar la dirección de “i” y su valor.
 * 2. Mostrar los mismos valores a través del puntero “pi”.
 * 3. Recorrer el vector “j” mostrando para cada elemento, su dirección y su valor.
 * 4. Recorra el vector accediendo a través del puntero “pi” y usando álgebra de
 *    punteros.
 * 5. Repita lo mismo con las variables char, el arreglo y el puntero.
 * 6. Finalmente muestre la dirección donde se almacenan ambos punteros.
 * 
 * Genere una salida del tipo:
 * --------------------------------------------------------------
 * |     Por Variable: 'i' Valor: 5 Dirección: 13FF5C           |
 * |     Por Puntero: 'pi' Valor: 5 Dirección: 13FF5C           |
 * |     Por Variable: 'j[0]' Valor: 1 Dirección: 13FF2C        |
 * |     Por Puntero: ' pi(=&j)+0' Valor: 1 Dirección: 13FF2C   |
 * |     Por Variable: 'j[1]' Valor: 2 Dirección: 13FF30        |
 * |     Por Puntero: 'pi(=&j)+1' Valor: 2 Dirección: 13FF30    |
 * |     …                                                      |
 * |     Por Variable: 'x' Valor: a Dirección: 13FF23           |
 * |     Por Puntero: 'pc' Valor: a Dirección: 13FF23           |
 * |     Por Variable: 'pal[0]' Valor: t Dirección: 13FF0C      |
 * |     Por Puntero: 'pc(=&pal)+0' Valor: t Dirección: 13FF0C  |
 * |     Por Variable: 'pal[1]' Valor: e Dirección: 13FF0D      |
 * |     Por Puntero: ' pc(=&pal)+1' Valor: e Dirección: 13FF0D |
 * |     …                                                      |
 * |     Dirección de *pi: 13FF00 De *pc: 13FEF4                |
 * --------------------------------------------------------------
 * 
 *  =============================================================================
 */

int main() {

    int i = 5;
    int *pi;
    int j[] = {1,2,3,4,5,6,7,8,9,10};
    char x = 'a';
    char pal [] = "texto en c";
    char *pc;

    pi = &i;
    printf("\nPor Variable: 'i'\tValor: %d\tDireccion: %p\n", i, &i);  
    printf("Por Puntero: 'pi'\tValor: %d\tDireccion: %p\n", *pi, pi);
    printf("===========================================================================\n");

    pi = j;
    for(i = 0; i < 10; i++) {
        printf("Por Variable: 'j[%d]'     \tValor: %d\tDireccion: %p\n", i, j[i], &j[i]);
        printf("Por Puntero:  'pi(=&j)+%d'\tValor: %d\tDireccion: %p\n", i, *pi, pi);
        printf("****************************************************************************\n");
        pi++;
    }


    pc = &x;
    printf("\nPor Variable: 'x'\tValor: %c\tDireccion: %p\n", x, &x);  
    printf("Por Puntero: 'pc'\tValor: %c\tDireccion: %p\n", *pc, pc);
    printf("===========================================================================\n");
    pc = pal;
    for(int i = 0; i < 11; i++) {
        printf("Por Variable:   'pal[%d]'\tValor: %c\tDireccion: %p\n", i, pal[i], &pal[i]);  
        printf("Por Puntero: 'pc(=&pal)+%d'\tValor: %c\tDireccion: %p\n", i, *pc, pc);
        printf("**************************************************************************\n");
        pc++;
    }

    printf("\nDirección de *pi: %p. De *pc: %p\n", &pi, &pc);
    
    return 0;

}