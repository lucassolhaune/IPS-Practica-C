/*Se define TipoCiudad como un struct para almacenar la posición de una ciudad en una
representación de dos dimensiones, es decir, en un plano.

Para almacenar varias ciudades, se construirá un vector de TipoCiudad. Se pide
construir una función que, a partir de un vector de TipoCiudad y dado el nombre de
una ciudad, reordene ascendentemente el vector atendiendo a la distancia euclídea
del resto de las ciudades con respecto a la elegida.*/


/*
 * ============================================================================================================
 *                                             MUY IMPORTANTE!!!
 * ============================================================================================================
 *
 * En Unix, compilar con GCC <Nombre del archivo> -lm
 * Esto se debe a que, por alguna razón que desconozco (y aunque lo busqué en google sigo sin entender el motivo),
 * el compilador no detecta la librería <math.h>. Al compilar con -lm, esto queda totalmente solucionado.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Si se quiere modificar la cantidad de ciudades a ingresar o el límite de caracteres en el nombre de la ciudad,
//modifique los siguientes valores.
#define TOTAL_CITIES 3              //Total de ciudades a guardar.
#define MAX_CITY_NAME_LENGTH 50     //Máximo de caracteres para nombre de ciudad.

/**
 * Estructura donde se almacena la coordenada cartesiana de una ciudad.
 * La misma se encuentra guardada bajo el nombre de un nuevo tipo de variable llamado Coordinates.
 */
typedef struct tipoPunto {
    double xAxis;   //Eje x.
    double yAxis;   //Eje y.
} Coordinates;

/**
 * Estructura donde se almacenan el nombre y la estructura contenedora de la coordenada cartesiana de una ciudad.
 * La misma se encuentra guardada bajo el nombre de un nuevo tipo de variable llamado City.
 */
typedef struct tipoCiudad {
    Coordinates point;  //Estructura anidada de la coordenada cartesiana.
    char *name;         //Nombre de la ciudad.
} City;

void citiesDataInput(City *city);
void citiesSwap(City *city, int firstIndex, int secondIndex);
double euclideanDistance(City *city, City refCity);
void citiesComparison(City *city, City refCity);

int main() {
    City *cities = (City *)malloc(TOTAL_CITIES * sizeof(City)); //Array de ciudades reservadas en el heap.
    City *pCities = cities; //Puntero para preservar la primera dirección de memoria al array cities.
    City refCity;           //Ciudad de referencia.

    //Tomo los datos de la ciudad de referencia.
    printf("Ingrese los siguientes datos\n");
    printf("==========================================================\n");
    printf("\tCiudad que desea tomar como punto de referencia\n");
    citiesDataInput(&refCity);

    //Tomo los datos de las ciudades.
    for(int i = 0; i < TOTAL_CITIES; i++) {
        printf("==========================================================\n");
        printf("\tCiudad %d\n", i + 1);
        citiesDataInput(cities);
        cities ++;
    }

    //Ordeno el array de ciudades y lo muestro en pantalla.
    cities = pCities;
    citiesComparison(cities, refCity);
    printf("==========================================================\n");
    printf("Ciudades ordenadas de forma ascendente (menor a mayor distancia), en base a la "
           "ciudad de referencia.\n");
    for(int i = 0; i < TOTAL_CITIES; i++) {
        printf("%d. %s", i + 1, cities->name);
        cities++;
    }

    cities = pCities;
    free(cities);   //Libero espacio reservado en el heap.

    return 0;
}

/**
 * Esta función toma los datos correspondiente de todos los elementos que se encuentran en la estructura
 * de las ciudades, incluida la estructura anidada de coordenadas cartesianas.
 *
 * Antes de finalizar la ejecución de la función, se limpia el buffer para prevenir posibles conflictos sobre el
 * input en futuras ejecuciones de la misma.
 *
 * @param city: Puntero a estructura TipoCiudad (a.k.a City).
 */
void citiesDataInput(City *city) {
    int c;
    //Reservo memoria en el heap para el nombre de la ciudad. Cada espacio inicializado en cero.
    city->name = calloc(MAX_CITY_NAME_LENGTH, sizeof(char));

    printf("\t\tNombre de la ciudad: ");
    fgets(city->name, MAX_CITY_NAME_LENGTH, stdin);
    printf("\t\tCoordenadas Cartesianas\n");
    printf("\t\t\tEje X: ");
    scanf("%le", &city->point.xAxis);
    printf("\t\t\tEje Y: ");
    scanf("%le", &city->point.yAxis);

    //Limpieza de buffer.
    while ((c = getchar()) != '\n' && c != EOF) { }
}

/**
 * La función citiesSwap() realiza durante su ejecución un swap de elementos del array donde están almacenadas las
 * ciudades. Esto será de utilidad al momento de ordenar el array.
 *
 * @param city: Puntero a estructura TipoCiudad (a.k.a City).
 * @param firstIndex: Indice 1.
 * @param secondIndex: Indice 2.
 */
void citiesSwap(City *city, int firstIndex, int secondIndex) {
    City tmp = city[firstIndex];
    city[firstIndex] = city[secondIndex];
    city[secondIndex] = tmp;
}

/**
 * Calcula la distancia euclídea entre una ciudad del array y la de referencia.
 *
 * @param city: Puntero a estructura TipoCiudad (a.k.a City).
 * @param refCity: Estructura TipoCiudad (a.k.a City) que almacena la ciudad de referencia.
 * @return Distancia euclídea entre una ciudad del array y la ciudad de referencia.
 */
double euclideanDistance(City *city, City refCity) {
    //Raíz cuadrada de la suma de los cuadrados de las diferencias de las abscisas y las ordenadas.
    return sqrt((pow((city->point.xAxis - refCity.point.xAxis), 2)) + (pow((city->point.yAxis - refCity.point.yAxis), 2)));
}

/**
 * Compara, a través del algoritmo Bubble Sorting, las distancias euclídeas entre cada ciudad del array.
 *
 * A medida que se comparan entre sí, se realiza swap de elementos de forma tal que el array quede ordenado de
 * manera ascendente, según su distancia euclídea con la ciudad de referencia.
 *
 * @param city: Puntero a estructura TipoCiudad (a.k.a City).
 * @param refCity: Estructura TipoCiudad (a.k.a City) que almacena la ciudad de referencia.
 */
void citiesComparison(City *city, City refCity) {
    double distance1, distance2;

    for(int i = 1; i < TOTAL_CITIES; i++) {
        distance2 = euclideanDistance(&city[i], refCity);
        for(int j = 0; j <= i; j++) {
            distance1 = euclideanDistance(&city[j], refCity);
            if(distance1 > distance2) {
                citiesSwap(city, i, j);
            }
        }
    }
}
