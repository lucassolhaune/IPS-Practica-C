#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include <time.h>

typedef struct tiempo{
	int anio, mes, dia, hora, minuto, segundo;
} Tiempo;

typedef struct {
	char *nombre;
	Tiempo ultima_mod;
} Archivo;

void dateCreator(Tiempo *t1, Tiempo *t2);

int compara_tiempos(Tiempo *t1, Tiempo * t2);

void listGen(Archivo *lista, int i, int n);

void showList(Archivo *lista);

void ordena_alfa(Archivo * lista, int n);

void ordena_temporal(Archivo * lista, int n);


int main() {
	Tiempo t1, t2; //Variables qeu almacenan 2 fechas distintas.
	Archivo *lista;
	Archivo *pArchivo; //Variable para guardar el puntero original de la lista.
	int n, menu, orden, timeComparison; // "n" guarda la cantidad de elementos de una lista. "menu" se usa para realizar una operacion elegida por el usuario. "orden" es usada para elegir de que forma ordenar la lista.
	char restart; //Variable para reiniciar el programa.

	srand(time(0));

	do {
		printf("\nIngrese:\n\t1- Para realizar una comparacion entre 2 fechas.\n\t2- Para ordenar una lista de archivos.\n\t> ");
		scanf("%d", &menu);

		//Si el usuario ingresa 1, compara 2 fechas.
		if(menu == 1) {
			printf("\nA continuacion se le pediran varios datos basados en el tiempo.\nGracias por su paciencia.\n");
			printf("\nPor favor, introduzca la siguiente informacion:\n");

			//Ingresa todos los datos de ambas fechas.
			dateCreator(&t1, &t2);

			//Muestro resultado de la comparacion entre ambas fechas.
			timeComparison = compara_tiempos(&t1, &t2);
			printf("El resultado es %d.\n", timeComparison);

			if(timeComparison == 1) {
				printf("\nFecha 1 es anterior a Fecha 2.\n");
			}


			else if(timeComparison == -1) {
				printf("\nFecha 1 es posterior a Fecha 2.\n");
			}

			else if(timeComparison == 0) {
				printf("\nFecha 1 es igual a fecha 2.\n");
			}

		//Si ingresa 2, ordena una lista de archivos.
		} else if (menu == 2) {
			printf("\nIngrese la cantidad de archivos que desee cargar en la lista: ");
			scanf("%d", &n);

			//getchar() para resolver conflictos entre scanf() y fgets()
			getchar();

			lista = (Archivo *)malloc(n * sizeof(Archivo));

			//Guardo el puntero original de *lista.
			pArchivo = lista;

			//Genero la lista de archivos con sus respectivos nombres y fechas de modificacion.
			for(int i = 1; i <= n; i++) {
				listGen(lista, i, n);
				*lista ++;
			}

			//Regreso *lista a su posicion original-
			lista = pArchivo;

			//Elijo el orden de la lista de archivos.
			printf("\nIngrese:\n\t1- Para mostrar los archivos en orden default.\n\t2- Para ordenar los archivos en orden alfabetico.\n\t3- Para ordenar los archivos segun su ultima fecha de modificacion.\n\t> ");
			scanf("%d", &orden);

			//Si se ingresa 1, los archivos se muestran en el orden que fueron ingresados.
			if(orden == 1) {
				printf("\nArchivos en orden default:\n");
				for(int i = 1; i <= n; i++) {
					showList(lista);
					*lista ++;
				}

			//Si el usuario ingresa 2, la lista de archivos se ordena por orden alfabetico.
			} else if(orden == 2) {
				ordena_alfa(lista, n);

			//Si se elije la opcion 3, se ordena por su fecha de modificacion.
			} else if(orden == 3) {
				ordena_temporal(lista, n);

			//Si se ingresa cualquier opcion distinta a las mencionadas, el programa sale con codigo de error.
			} else {
				printf("\nValor incorrecto. Vuelva a ejecutar el programa.\n");
				exit(EXIT_FAILURE);
			}

			lista = pArchivo;

			//Libero memoria reservada en el heap.
			free(lista);
			lista = NULL;

		} else {
			printf("\nValor incorrecto. Vuelva a ejecutar el programa.\n");
			exit(EXIT_FAILURE);
		}

	printf("\nDesea reintentar? [y/n] : ");
	scanf(" %c", &restart);
	getchar();

	//Opcion de reiniciar el programa.
	} while (restart == 'y' || restart == 'Y');

	return 0;
}

/**
 * Esta funcion toma datos detallados sobre una fecha ingresados por el usuario.
 * Tambien se verifica que el usuario haya ingresado los datos de manera correcta.
 *
 * Luego de que el usuario carga todos los datos, se muestra con un formato especifico
 * para un mejor orden de los mismos.
 *
 * @param Tiempo *t1, Tiempo *t2: Pasaje por referencia a variables del tipo Tiempo.
 */
void dateCreator(Tiempo *t1, Tiempo *t2) {
	//Tomo los datos de la primer fecha.
	printf("\n===============================");
	printf("\n\t\tTiempo 1\n");
	printf("===============================\n");

	printf("\n\t\t\tAnio: ");
	scanf("%d", &t1->anio);

	printf("\t\t\tMes: ");
	scanf("%d", &t1->mes);

	while((t1->mes < 1) || (t1->mes > 12)) {
		printf("\t\t\tIngrese un mes correcto: ");
		scanf("%d", &t1->mes);
	}

	printf("\t\t\tDia: ");
	scanf("%d", &t1->dia);

	while((t1->dia < 1) || (t1->dia > 31)) {
		printf("\t\t\tIngrese un dia correcto: ");
		scanf("%d", &t1->dia);
	}

	printf("\t\t\tHora (formato 24hs): ");
	scanf("%d", &t1->hora);

	while(t1->hora > 24) {
		printf("\t\t\tIngrese un horario correcto: ");
		scanf("%d", &t1->hora);
	}

	printf("\t\t\tMinuto: ");
	scanf("%d", &t1->minuto);

	while(t1->minuto > 59) {
		printf("\t\t\tIngrese minutos correctos: ");
		scanf("%d", &t1->minuto);
	}

	printf("\t\t\tSegundo: ");
	scanf("%d", &t1->segundo);

	while(t1->segundo > 59) {
		printf("\t\t\tIngrese segundos correctos: ");
		scanf("%d", &t1->segundo);
	}

	//Tomo los datos de la segunda fecha.
	printf("===============================\n");
	printf("\n\t\tTiempo 2\n");
	printf("===============================\n");

	printf("\n\t\t\tAnio: ");
	scanf("%d", &t2->anio);

	printf("\t\t\tMes: ");
	scanf("%d", &t2->mes);

	while((t2->mes < 1) || (t2->mes > 12)) {
		printf("\t\t\tIngrese un mes correcto: ");
		scanf("%d", &t2->mes);
	}

	printf("\t\t\tDia: ");
	scanf("%d", &t2->dia);

	while((t2->dia < 1) || (t2->dia > 31)) {
		printf("\t\t\tIngrese un dia correcto: ");
		scanf("%d", &t2->dia);
	}

	printf("\t\t\tHora (formato 24hs): ");
	scanf("%d", &t2->hora);

	while(t2->hora > 24) {
		printf("\t\t\tIngrese un horario correcto: ");
		scanf("%d", &t2->hora);
	}

	printf("\t\t\tMinuto: ");
	scanf("%d", &t2->minuto);

	while(t2->minuto > 59) {
		printf("\t\t\tIngrese minutos correctos: ");
		scanf("%d", &t2->minuto);
	}

	printf("\t\t\tSegundo: ");
	scanf("%d", &t2->segundo);

	while(t2->segundo > 59) {
		printf("\t\t\tIngrese segundos correctos: ");
		scanf("%d", &t2->segundo);
	}

	// Muestro las dos fechas ingresadas de forma ordenada para que pueda ser leida facilmente.
	printf("\n========================================================");
	printf("\nFecha 1 (YY/MM/DD):  %d/%d/%d - %d:%d.%d\n", t1->anio, t1->mes, t1->dia, t1->hora, t1->minuto, t1->segundo);
	printf("\nFecha 2 (YY/MM/DD):  %d/%d/%d - %d:%d.%d\n", t2->anio, t2->mes, t2->dia, t2->hora, t2->minuto, t2->segundo);
	printf("\n========================================================");
}

/**
 * Esta funcion compara las 2 fechas ingresadas por el usuario.
 *
 * @param Tiempo *t1, Tiempo *t2: Pasaje por referencia a variables del tipo Tiempo.
 *
 * @return 1 si *t1 es anterior a *t2
 * @return 0 si *t1 es igual a *t2
 * @return -1 si *t1 es posterior a *t2
 */

int compara_tiempos(Tiempo *t1, Tiempo *t2) {
	if(t1->anio == t2->anio) {
		if(t1->mes == t2->mes) {
			if(t1->dia == t2->dia) {
				if(t1->hora == t2->hora) {
					if(t1->minuto == t2->minuto) {
						if(t1->segundo == t2->segundo) {
							return 0;
						}
						else if(t1->segundo > t2->segundo) {
							return -1;
						}
						else if(t1->segundo < t2->segundo) {
							return 1;
						}
					}
					else if(t1->minuto > t2->minuto) {
						return -1;
					}
					else if(t1->minuto < t2->minuto) {
						return 1;
					}
				}
				else if(t1->hora > t2->hora) {
					return -1;
				}
				else if(t1->hora < t2->hora) {
					return 1;
				}
			}
			else if(t1->dia > t2->dia) {
				return -1;
			}
			else if(t1->dia < t2->dia) {
				return 1;
			}
		}
		else if(t1->mes > t2->mes) {
			return -1;
		}
		else if(t1->mes < t2->mes) {
			return 1;
		}
	}
	else if(t1->anio > t2->anio) {
		return -1;
	}
	else if(t1->anio < t2->anio) {
		return 1;
	}

}

/**
 * La siguiente funcion genera archivos a partir de datos cargados por el usuario como la cantidad de archivos de la lista y nombres
 * de los mismos. Las fechas de modificacion son generadas de forma aleatoria.
 *
 * @param Archivo *lista: puntero a estructura del tipo Archivo.
 * @param int n: variable que contiene la cantidad de archivos de la lista.
 * @param int i: contador para mostrar el numero de archivo a ingresar.
 */
void listGen(Archivo *lista, int i, int n) {

	lista->nombre = (char *)malloc(100 * sizeof(char));

	printf("Ingrese nombre del archivo %d: ", i);
	fgets(lista->nombre,100,stdin);

	lista->ultima_mod.anio = 2000 + (rand() % 22);
	lista->ultima_mod.mes = 1 + (rand() % 12);
	lista->ultima_mod.dia = 1 + (rand() % 30);
	lista->ultima_mod.hora = rand() % 24;
	lista->ultima_mod.minuto = rand() % 60;
	lista->ultima_mod.segundo = rand() % 60;

}

/**
 * Funcion para mostrar los datos de los archivos con un formato prolijo y ordenado.
 * @param Archivo *lista: puntero a estructura del tipo Archivo.
 * @param int i: contador para mostrar el numero de archivo.
 */
void showList(Archivo *lista) {
	printf("%d/%d/%d-%d:%d.%d\t%s",lista->ultima_mod.dia, lista->ultima_mod.mes, lista->ultima_mod.anio,
	lista->ultima_mod.hora, lista->ultima_mod.minuto, lista->ultima_mod.segundo, lista->nombre);
}

/**
 * La funcion ordena alfabeticamente los archivos de la lista basados en sus respectivos nombres.
 * Para ordenar los mismos, se recorre la lista desde el primer elemento hasta el ultimo comparando los nombres
 * con la funcion strcmp(), que devuelve un numero positivo si el primer nombre es mayor que el segundo, 0 si los nombres son iguales
 * o un numero negativo si el primer nombre es menor que el segundo.
 *
 * Teniendo esto ultimo en cuenta, evaluamos si el primer nombre es mayor que el segundo. En caso de que esto se cumpla, se intercambian
 * los archivos entre si. Estas comparaciones e intercambios se realizan continuamente hasta que toda la lista se encuentre ordenada
 * en orden alfabetico.
 *
 * @param Archivo *lista: puntero a estructura del tipo Archivo.
 * @param int n: variable que contiene la cantidad de archivos de la lista.
 */
void ordena_alfa(Archivo *lista, int n) {
	int comparison; //Variable para guardar el resultado de strcmp().
	bool disordered; //Variable que se utiliza como flag.
	char* nombreArchivoPrev; //Variable donde se guarda el nombre del archivo anterior en la lista.
	char* nombreArchivoCurr; //Variable donde se guarda el nombre del archivo actual en la lista.
	char* nombreArchivoTemp; //Variable para guardar un nombre de forma temporal para realizar el intercambio.

	do {
		disordered = false;

		for(int i = 0; i < n; i++) {

			// Primer elemento de la lista, no hay nada que comparar.
			if (i == 0) {
				continue;
			}

			nombreArchivoPrev = lista[i-1].nombre;
			nombreArchivoCurr = lista[i].nombre;

			//Comparo nombres.
			comparison = strcmp(nombreArchivoPrev, nombreArchivoCurr);

			//Evaluo si el primer nombre es mayor que el segundo. De ser asi,
			//realizo un intercambio de posiciones entre ellos.
			if(comparison > 0) {
				nombreArchivoTemp = nombreArchivoCurr;
				lista[i].nombre = nombreArchivoPrev;
				lista[i-1].nombre = nombreArchivoTemp;

				disordered = true;
			}
		}

	} while(disordered);

	printf("\nLista ordenada:\n");

	//Muestro la lista ordenada alfabeticamente.
	for(int i = 1; i <= n; i++) {
		showList(lista);
		*lista ++;
	}
}

/**
 * Esta funcion ordena los archivos por fecha.
 *
 * @param Archivo *lista: puntero a estructura del tipo Archivo.
 * @param int n: variable que contiene la cantidad de archivos de la lista.
 */
void ordena_temporal(Archivo *lista, int n) {
	bool disordered;
	int comparison;
	Tiempo tmp;
	Tiempo fechaPrev;
	Tiempo fechaCurr;

	do {
		disordered = false;

		for(int i = 0; i < n; i++) {
			if(i == 0) {
				continue;
			}

			fechaPrev = lista[i - 1].ultima_mod;
			fechaCurr = lista[i].ultima_mod;

			comparison = compara_tiempos(&fechaPrev, &fechaCurr);
			if(comparison == 1) {
				tmp = fechaCurr;
				lista[i].ultima_mod = fechaPrev;
				lista[i - 1].ultima_mod = fechaCurr;
				disordered = true;
			}
		}

	} while(disordered);

	printf("\nLista ordenada:\n");

	//Muestro la lista ordenada por su fecha de modificacion.
	for(int i = 1; i <= n; i++) {
		showList(lista);
		*lista ++;
	}

}
