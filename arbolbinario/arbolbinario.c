#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbolbinario.h"

void inserta (arbol **A, int x){
	if(*A == NULL){
		*A = (arbol*)malloc(sizeof(arbol));
		(*A)->dato = x;
		(*A)->h_izq = NULL;
		(*A)->h_der = NULL;
	}else{
		if(x < (*A)->dato){
			inserta (&((*A)->h_izq), x);
		}else{
			if(x > (*A)->dato){
				inserta (&((*A)->h_der), x);
			}
		}
	}
}
int es_miembro (arbol *A, int x){
	if(A == NULL){
		return -1;
	}else{
		if(A->dato == x){
			return 1;
		}else{
			if(A ->dato < x){
				return es_miembro (A->h_izq, x);
			}else{
				return es_miembro (A->h_der, x);
			}
		}
	}
}

int suprime_min(arbol**A){
	int v_ref;
	if((*A)->h_izq == NULL){
		v_ref = (*A)->dato;
		arbol *tmp = *A;
		*A = (*A)->h_der;
		free(tmp);
		return v_ref;
	}else{
		return suprime_min(&((*A)->h_izq));
	}
}

void suprime (arbol **A, int x){
	if(*A != NULL){
		if(x < (*A)->dato){
			suprime(&((*A)->h_izq), x);
		}else{
			if(x > (*A)->dato){
				suprime(&((*A)->h_der), x);
				//Lo encontre
			}else{
				if((*A)->h_izq == NULL && (*A)->h_der == NULL){
					arbol *tmp = *A;
					*A = NULL;
					free(tmp);
				}else{
					if((*A)->h_izq == NULL){
						arbol *tmp = *A;
						*A = (*A)->h_der;
						free(tmp);
					}else{
						if((*A)->h_der == NULL){
							arbol *tmp = *A;
							*A = (*A)->h_izq;
							free(tmp);
						}else{ // Ambos hijos estan presentes
								(*A)->dato = suprime_min(&((*A)->h_der));
						}
					}
				}
			}
		}
	}
}

int main (){
	arbol *raiz;
	raiz = NULL;
	inserta(&raiz, 10);
	inserta(&raiz, 5);
	inserta(&raiz, 18);
	inserta(&raiz, 16);
	inserta(&raiz, 3);

	if(es_miembro(raiz, 5) == 1){
		printf("El elemento buscado existe en el arbol\n");
	}else{
		printf("No existe\n");
	}
	if(es_miembro(raiz, 124) == 1){
		printf("El elemento buscado existe en el arbol\n");
	}else{
		printf("No existe\n");
	}
	
return 0;
}