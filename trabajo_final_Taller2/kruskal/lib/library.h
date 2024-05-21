#ifndef LIB_LIBRARY_H
#define LIB_LIBRARY_H

#define VERTICES 6

typedef int vertice;
typedef int tipo_nombre;
typedef int tipo_elemento;

typedef struct Arista {
    vertice u;
    vertice v;
    int costo;
} arista;

typedef struct Rama {
    arista a;
    struct Rama *sig;
} rama;

typedef struct Encabezado {
    int cuenta;
    int primerElemento;
} encabezado;

typedef struct Nombre {
    tipo_nombre nombreConjunto;
    int sigElemento;
} nombre;

typedef struct Conjunto_combina_encuentra {
    nombre nombres[VERTICES];
    encabezado encabezamientosConjunto[VERTICES + 1];
} conjunto_CE;

void inicial(tipo_nombre, tipo_elemento, conjunto_CE *);
void combina(tipo_nombre, tipo_nombre, conjunto_CE *);
int encuentra(int, conjunto_CE *);
void kruskal();
void inserta(int, int, int, rama **);
arista sacar_min();
void printArbolCompleto();

#endif //LIB_LIBRARY_H
