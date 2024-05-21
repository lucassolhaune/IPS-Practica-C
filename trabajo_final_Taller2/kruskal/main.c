#include <stdio.h>
#include <stdlib.h>
#include "lib/library.h"

int main() {
    int m_Costos[VERTICES][VERTICES];
    rama *arbol = malloc(sizeof(rama));

    //Inicializo los costos en 0
    for(int i = 0; i < VERTICES; i++) {
        for(int j = 0; j < VERTICES; j++) {
            m_Costos[i][j] = 0;
        }
    }

    //INGRESO AUTOMATICO DE COSTOS SEGUN EJEMPLO DEL APUNTE
    m_Costos[0][1] = 6;
    m_Costos[0][2] = 1;
    m_Costos[0][3] = 5;
    m_Costos[1][2] = 5;
    m_Costos[1][4] = 3;
    m_Costos[2][3] = 5;
    m_Costos[2][4] = 6;
    m_Costos[2][5] = 4;
    m_Costos[3][5] = 2;
    m_Costos[4][5] = 6;

    //Ingreso las aristas con sus respectivos costos en la cola de prioridad.
    for(int i = 0; i < VERTICES; i++) {
        for(int j = i + 1; j < VERTICES; j++) {
            if(m_Costos[i][j] != 0) {
                inserta(i + 1, j + 1, m_Costos[i][j], &arbol);
                arbol = arbol->sig;
                arbol = malloc(sizeof(rama));
            }
        }
    }
    //Muestro el arbol completo para chequear el metodo de ordenamiento.
    printArbolCompleto();
    //Llamo a la funcion Kruskal para seleccionar las aristas correspondientes.
    kruskal();
    return 0;
}
