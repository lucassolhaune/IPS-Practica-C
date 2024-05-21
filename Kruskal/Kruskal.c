#include "kruskal.h"

/**
 * @brief Esta funcion inicializa ambos conjuntos: Encabezamiento y Nombre
 * @param A Nombre del conjunto
 * @param x Vertice
 * @param C Conjunto Encabezamiento y Nombres
*/
void inicial(tipo_nombre A, tipo_elemento x, conjunto_CE* C) {
    C->nombres[x].nombre_conjunto = A;
    C->nombres[x].siguiente_elemento = 0;
    C->encabezamientos_conjuntos[A].cuenta = 1;
    C->encabezamientos_conjuntos[A].primer_elemento = x;
}

/**
 * La funcion es llamada desde Kruskal, toma como parametro dos conjuntos y los une en uno.
 * @param A Conjunto Vertice A
 * @param B Conjunto Vertice B
 * @param C Conjuntos Encabezamiento y Nombres
 */
void combina(tipo_nombre A, tipo_nombre B, conjunto_CE* C) {
    //A es el conjunto mas grande, combina B dendro de A
    if (C->encabezamientos_conjuntos[A].cuenta > C->encabezamientos_conjuntos[B].cuenta) {
        int i = C->encabezamientos_conjuntos[B].primer_elemento;

        /* Encuentra el final de B, cambiando los nombres de los conjuntos
         * por A conforme se avanza
         */
        for (int j = 0; j < VERTICES - 1; j++) {
            C->nombres[i].nombre_conjunto = A;
            i = C->nombres[i].siguiente_elemento;
        }

        //Agrega a la lista A al final de la B y llama A al resultado
        //Ahora i es el indice del ultimo elemento de B
        C->nombres[i].nombre_conjunto = A;
        C->nombres[i].siguiente_elemento = C->encabezamientos_conjuntos[A].primer_elemento;
        C->encabezamientos_conjuntos[A].primer_elemento = C->encabezamientos_conjuntos[B].primer_elemento;
        C->encabezamientos_conjuntos[A].cuenta = (C->encabezamientos_conjuntos[A].cuenta) + (C->encabezamientos_conjuntos[B].cuenta);

        //B es al menos, tan grande como A
    }
    else {
        int i = C->encabezamientos_conjuntos[A].primer_elemento;

        for (int j = 0; j < VERTICES - 1; j++) {
            C->nombres[i].nombre_conjunto = A;
            i = C->nombres[i].siguiente_elemento;
        }

        C->nombres[i].nombre_conjunto = B;
        C->nombres[i].siguiente_elemento = C->encabezamientos_conjuntos[B].primer_elemento;
        C->encabezamientos_conjuntos[B].primer_elemento = C->encabezamientos_conjuntos[A].primer_elemento;
        C->encabezamientos_conjuntos[B].cuenta = (C->encabezamientos_conjuntos[A].cuenta) + (C->encabezamientos_conjuntos[B].cuenta);
    }
}

/**
 * Esta funcion devuelve el nombre del conjunto perteneciente del vertice v.
 * @param x Vertice
 * @param C Conjuntos Encabezamientos y Nombres
 * @return Nombre del conjunto perteneciente del vertice v
 */
tipo_nombre encuentra(int x, conjunto_CE* C) {
    return C->nombres[x].nombre_conjunto;
}

/**
 * @brief La funcion Kruskal es la encargada de, dado un arbol con aristas organizadas por sus costos, analizar si es posible
 * incluir la arista de menor peso sin que forme un ciclo.
 * El ciclo se detecta cuando dos vertices pertenecen al mismo conjunto. Es decir, la funcion compara los conjuntos
 * que pertenecen los vertices, si son distintos llama a la funcion combina() y los inserta en otro arbol llamado T.
 * 
 * @param grafo 
*/
void kruskal(rama* grafo) {
    rama* T = (rama*)malloc(sizeof(rama));
    arista* a = (arista*)malloc(sizeof(arista));
    T->a = a;

    //Conjunto V agrupado en un conjunto de componentes tipo conjunto_CE
    conjunto_CE* componentes = (conjunto_CE*)malloc(sizeof(conjunto_CE));

    //Cantidad actual de componentes
    int comp_n = VERTICES;

    //Asigna el valor inicial a cada componente
    for (int i = 0; i < VERTICES - 1; i++) {
        int comp = i;
        inicial(comp, i, componentes);
    }

    while (comp_n > 1) {
        rama* b = pop(&grafo);
 //       arista* a = b->a;

        tipo_nombre u = encuentra(b->a->u, componentes);
        tipo_nombre v = encuentra(b->a->v, componentes);

        if (u != v) {
            //La arista 'a' conecta dos componentes diferentes
            combina(b->a->u, b->a->v, componentes);
            push(&T, b->a);
            comp_n--;
        }
    }
    imprimir(T);
}

/**
 * @brief Funcion que crea un nuevo nodo
 * @param a Arista
 * @return Nuevo nodo
*/
rama* newNode(arista* a) {
    rama* temp = (rama*)malloc(sizeof(rama));
    temp->a = a;
    temp->siguiente_elemento = NULL;

    return temp;
}

/**
 * @brief Agrega un elemento a la cola de prioridad
 * @param head Puntero a la cola de prioridad
 * @param aristaNueva Elemento a agregar en la cola
*/
void push(rama** head, arista* aristaNueva) {
    rama* actual = (*head);
    rama* nuevoNodo = newNode(aristaNueva);

    if ((*head)->a->costo == 0) {
        (*head) = nuevoNodo;
    }
    else if ((*head)->a->costo > aristaNueva->costo) {
        nuevoNodo->siguiente_elemento = (*head);
        (*head) = nuevoNodo;
    }
    else {
        while
            (actual->siguiente_elemento != NULL && actual->siguiente_elemento->a->costo < aristaNueva->costo) {
            actual = actual->siguiente_elemento;
        }
        nuevoNodo->siguiente_elemento = actual->siguiente_elemento;
        actual->siguiente_elemento = nuevoNodo;
    }
}

/**
 * @brief Saca el elemento con maxima prioridad de la cola
 * @param head Puntero a la cola de prioridad
 * @return Cola con el elemento eliminado
*/
rama* pop(rama** head) {
    rama* b = (*head);
    (*head) = (*head)->siguiente_elemento;

    return b;
}

/**
 * @brief Imprime el grafo
 * @param head Grafo a imprimir
*/
void imprimir(rama* head) {
    rama* actual = head;

    if (head != NULL) {
        while (actual != NULL) {
            printf("\t%d, %d-%d\n", actual->a->costo, actual->a->u + 1, actual->a->v + 1);
            actual = actual->siguiente_elemento;
        }
    }
    else {
        printf("\nNada que mostrar, la lista esta vacia\n\n");
    }
}

/**
 * @brief Inicializa la arista
 * @param u Vertice 1
 * @param v Vertice 2
 * @param costo Costo de la arista
 * @return Arista inicializada
*/
arista* iniciaArista(int u, int v, int costo) {
    arista* a = (arista*)malloc(sizeof(arista));
    a->costo = costo;
    a->u = u;
    a->v = v;
    return a;
}
int main() {
    int m_Costos[VERTICES][VERTICES];
    rama* grafo = malloc(sizeof(rama));
    arista* a = malloc(sizeof(arista));
    grafo->a = a;

    //Inicializo los costos en 0
    for (int i = 0; i < VERTICES; i++) {
        for (int j = 0; j < VERTICES; j++) {
            m_Costos[i][j] = 0;
        }
    }

//COMENTAR PARA INGRESAR COSTOS POR TECLADO
    m_Costos[0][1] = 6;
    m_Costos[0][2] = 1;
    m_Costos[0][3] = 5;
    m_Costos[1][2] = 5;
    m_Costos[1][4] = 3;
    m_Costos[2][3] = 5;
    m_Costos[2][4] = 6;

//DESCOMENTAR PARA INGRESAR COSTOS POR TECLADO
/*    printf("\nIngrese los datos requeridos del grafo en cuestion\n");
    for (int i = 0; i <= VERTICES - 1; i++) {
        for (int j = i + 1; j <= VERTICES - 1; j++) {
            printf("\t- costo de la arista entre vertices %d y %d: ", i+1, j+1);
            scanf(" %d", &m_Costos[i][j]);
        }
    }
*/
    for (int i = 0; i <= VERTICES - 1; i++) {
        for (int j = i + 1; j <= VERTICES - 1; j++) {
            if (m_Costos[i][j] != 0) {
                arista* a = iniciaArista(i, j, m_Costos[i][j]);
                push(&grafo, a);
            }
        }
    }
    
    printf("Grafo original:\n");
    imprimir(grafo);

    printf("Subgrafo desarrollado por kruskal:\n");
    kruskal(grafo);

    return 0;
}
