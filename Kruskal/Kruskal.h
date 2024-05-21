#ifndef KRUSKAL
#define KRUSKAL

#include <stdio.h>
#include <stdlib.h>

typedef int tipo_nombre;
typedef int tipo_elemento;
typedef int vertice;

#define VERTICES 5

typedef struct ARISTA {
	vertice u;
	vertice v;
	int costo;
} arista;

typedef struct RAMA {
	arista* a;
	struct RAMA* siguiente_elemento;
} rama;

typedef struct ENCABEZADO {
	int cuenta;
	int primer_elemento;
} encabezado;

typedef struct NOMBRE {
	tipo_nombre nombre_conjunto;
	int siguiente_elemento;
} nombre;

typedef struct CONJUNTO_CE {
	nombre nombres[VERTICES];
	encabezado encabezamientos_conjuntos[VERTICES];
} conjunto_CE;

void inicial(tipo_nombre A, tipo_elemento x, conjunto_CE* C);
void combina(tipo_nombre A, tipo_nombre B, conjunto_CE* C);
tipo_nombre encuentra(int x, conjunto_CE* C);
void kruskal(rama* V);

//Cola de prioridad
void imprimir(rama* head);
void push(rama** edges_set, arista* a);
rama* newNode(arista* a);
rama* pop(rama** head);

arista* iniciaArista(int u, int v, int costo);

#endif
