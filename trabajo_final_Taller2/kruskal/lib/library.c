#include <stdio.h>
#include <stdlib.h>
#include "library.h"

rama *head = NULL;
rama *tail = NULL;
rama *tmp = NULL;
rama *prevTmp = NULL;

/**
 * Esta funcion inicializa ambos conjuntos: Encabezamiento y Nombre
 */
void inicial(tipo_nombre A, tipo_elemento v, conjunto_CE * C) {
    C->nombres[v].nombreConjunto = A;
    C->nombres[v].sigElemento = 0;
    C->encabezamientosConjunto[A].cuenta = 1;
    C->encabezamientosConjunto[A].primerElemento = v;
}
/**
 * La funcion es llamada desde Kruskal, toma como parametro dos conjuntos y los une en uno.
 * @param A Conjunto Vertice A
 * @param B Conjunto Vertice B
 * @param C Conjuntos Encabezamiento y Nombres
 */
void combina(tipo_nombre A, tipo_nombre B, conjunto_CE * C) {
    int i;
    if(C->encabezamientosConjunto[A].cuenta > C->encabezamientosConjunto[B].cuenta) {
        i = C->encabezamientosConjunto[B].primerElemento;
        do {
            C->nombres[i].nombreConjunto = A;
            i = C->nombres[i].sigElemento;
        } while(C->nombres[i].sigElemento != 0);
        C->nombres[i].nombreConjunto = A;
        C->nombres[i].sigElemento = C->encabezamientosConjunto[A].primerElemento;
        C->encabezamientosConjunto[A].cuenta = C->encabezamientosConjunto[A].cuenta + C->encabezamientosConjunto[B].cuenta;
    } else {
        i = C->encabezamientosConjunto[A].primerElemento;
        do {
            C->nombres[i].nombreConjunto = B;
            i = C->nombres[i].sigElemento;
        } while(C->nombres[i].sigElemento != 0);
        C->nombres[i].nombreConjunto = B;
        C->nombres[i].sigElemento = C->encabezamientosConjunto[B].primerElemento;
        C->encabezamientosConjunto[B].cuenta = C->encabezamientosConjunto[B].cuenta + C->encabezamientosConjunto[A].cuenta;
    }
}
/**
 * Esta funcion devuelve el nombre del conjunto perteneciente del vertice v.
 * @param v Vertice
 * @param C Conjuntos Encabezamientos y Nombres
 * @return Nombre del conjunto perteneciente del vertice v
 */
int encuentra(int v, conjunto_CE * C) {
    return C->nombres[v].nombreConjunto;
}
/**
 * La funcion Kruskal es la encargada de, dado un arbol con aristas organizadas por sus costos, analizar si es posible
 * incluir la arista de menor peso sin que forme un ciclo.
 *
 * El ciclo se detecta cuando dos vertices pertenecen al mismo conjunto. Es decir, la funcion compara los conjuntos
 * que pertenecen los vertices, si son distintos llama a la funcion combina() y los inserto en otro arbol llamado T.
 */
void kruskal() {
    rama *T = malloc(sizeof(rama));
    arista a;
    conjunto_CE componentes;
    int comp_n, comp_sig, comp_u, comp_v;

    comp_sig = 0;
    comp_n = VERTICES;
    for(int v = 0; v < VERTICES; v++) {
        comp_sig = comp_sig + 1;
        inicial(comp_sig, v, &componentes);
    }
    printf("El subgrafo desarrollado por kruskal es el siguiente:\n");
    while(comp_n > 1) {
        a = sacar_min();
        comp_u = encuentra(a.u, &componentes);
        comp_v = encuentra(a.v, &componentes);
        if(comp_u != comp_v) {
            combina(comp_u, comp_v, &componentes);
            comp_n = comp_n - 1;
            inserta(a.u, a.v, a.costo, &T);
            printf("(%d, %d) - %d\n", T->a.u, T->a.v, T->a.costo);
            T = T->sig;
            T = malloc(sizeof(rama));
        }
    }
}
/**
 * La funcion inserta() añade las aristas que se pasen como parametro a una cola de prioridad.
 * Para ello se declararon 4 variables globales:
 *      Head: Apunta a la arista con menor costo, es decir, a la primera de la cola
 *      Tail: Apunta a la ultima arista (la que mayor costo tiene)
 *      Tmp y PrevTmp: dos punteros temporales para insertar una arista que se encuentre en el medio entre Head y Tail
 *
 * @param vertice_a
 * @param vertice_b
 * @param costo
 * @param arbol
 */
void inserta(int vertice_a, int vertice_b, int costo, rama **arbol) {
    (*arbol)->a.u = vertice_a;
    (*arbol)->a.v = vertice_b;
    (*arbol)->a.costo = costo;
    (*arbol)->sig = NULL;

    //Si Head no apunta a nada, significa que la cola esta vacia y, por ende, head y tail apuntarian al mismo elemento.
    if(head == NULL) {
        head = *arbol;
        tail = *arbol;
        return;
    }
    //Si el costo del arbol es menor o igual al apuntado por head, entonces apunto el link de arbol a head, y head al
    //nuevo nodo.
    if((*arbol)->a.costo <= head->a.costo) {
        (*arbol)->sig = head;
        head = (*arbol);
        return;
    //Si el costo del arbol es mayor a la cola, hago que el link de la cola apunte al nuevo arbol y que este nodo sea
    //la cola.
    } else if((*arbol)->a.costo > tail->a.costo) {
        tail->sig = (*arbol);
        tail = (*arbol);
        return;
    }
    //Comparo los costos entre este nodo y los que ya se encuentran almacenados en la cola. Si el costo del nodo
    //se encuentra entre otros dos costos, lo inserto en el medio de ambos.
    tmp = head->sig;
    prevTmp = head;
    while(prevTmp->sig != NULL) {
        if(((*arbol)->a.costo > prevTmp->a.costo) && ((*arbol)->a.costo <= tmp->a.costo)) {
            (*arbol)->sig = tmp;
            prevTmp->sig = (*arbol);
            return;
        }
        prevTmp = tmp;
        tmp = tmp->sig;
    }
}
/**
 * Esta funcion elimina la arista apuntada por Head. Para ello, guardo esa arista en otra variable, apunto head a
 * el nodo siguiente, y retorno la arista guardada en la nueva variable.
 * @return primer nodo de la cola.
 */
arista sacar_min() {
    if(head == NULL) {
        printf("La cola se encuentra vacia.\n");
        exit(1);
    }
    arista aristaSelec = head->a;
    head = head->sig;
    return aristaSelec;
}
/**
 * Esta funcion funciona para mostrar la cola de prioridad entera, es decir, sin aplicar el algoritmo de Kruskal.
 */
void printArbolCompleto() {
    if(head == NULL) {
        printf("El arbol esta vacio.\n");
        return;
    }
    rama *ptr = head;
    printf("Grafo original:\n");
    while(ptr) {
        printf("(%d - %d, %d)\n", ptr->a.u, ptr->a.v, ptr->a.costo);
        ptr = ptr->sig;
    }
}