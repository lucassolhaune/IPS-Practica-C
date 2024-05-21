#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef enum { MAYUSCULAS, MINUSCULAS } may_min;

int strLargo(const char *origen);
int strVacio(const char *origen);
void strCopia(char *destino, const char *origen);
char* reverse(char *string);
void strIzq(char *destino, const char *origen);
void strDer(char *destino, const char *origen);
void strAmbos(char *destino, const char *origen);
void strMayMin(char *destino, const char *origen, may_min m);

int main(){
    char *text1 =" Sera Cierto ?? ";
    int largo=strLargo(text1)+1;
    char *result = (char *)malloc (largo);
    char* reves;

    if(result == NULL)
        return -1;

    printf("La cadena: ");
    puts(text1);

    printf("Se encuentra: %s\n",(strVacio(text1) ? "No vacia" : "Vacia"));
    printf("Largo : %d\n", strLargo(text1));
    strCopia(result,text1);
    printf("Copia : [%s]\n", result);

    strIzq(result,text1);
    printf("Sin blancos a la Izq:");
    puts(result);

    strDer(result,text1);
    printf("Der : [%s]\n", result);

    strAmbos(result,text1);
    printf("Ambos: [%s], sin blancos al principio ni al final.\n", result);

    strMayMin(result,text1, MAYUSCULAS);
    printf("Mayusculas : [%s]\n", result);
    strMayMin(result,text1, MINUSCULAS);
    printf("Minusculas : [%s]\n", result);

    reves=reverse(text1);
    printf("La cadena: %s invertida queda: %s\n",text1, reves);

    return 0;
}

int strLargo(const char *origen) {
    return strlen(origen);
}
int strVacio(const char *origen) {
    if(strlen(origen) > 0) {
        return 1;
    } else {
        return 0;
    }
}
void strCopia(char *destino, const char *origen) {
    for(int i = 0; i <= (strlen(origen) + 8); i++) {
        destino[i] = origen[i];
    }
}
char* reverse(char *string) {
    char *invertido;
    int k, j;

    invertido = (char *)malloc(strlen(string) * sizeof(char));
    j = 0;

    for(int i = (strlen(string) - 2); i >= 0; i++) {
        if((string[i] == ' ') || (i == 0)){
            k = i + 1;
            if(i == 0){
                k = i;
            }
            do {
                invertido[j] = string[k];
                j++;
                k++;
            } while((string[k] != 32) && (string[k] != '\n'));
            invertido[j] = ' ';
            j++;
        }
    }
    return invertido;
}
void strIzq(char *destino, const char *origen) {
    int j = 0;

    for(int i = 0; i <= (strlen(origen) + 8); i++) {
        if(origen[i] != 32) {
            do {
                destino[j] = origen[i];
                j++;
                i++;
            } while(origen[i] != '\0');
            break;
        }
    }
}
void strDer(char *destino, const char *origen) {
    int j = strLargo(origen);

    for(int i = 0; i <= (strlen(origen) + 8); i++) {
        if (origen[i] != 32) {
            do {
                destino[j] = origen[i];
                j--;
                i--;
            } while (i != 0);
            break;
        }
    }
}
void strAmbos(char *destino, const char *origen) {
    int spacesR, spacesL;
    spacesR = 0;
    spacesL = 0;

    for(int i = strlen(origen) - 1; i >= 0; i++) {
        if(origen[i] == 32) {
            spacesR++;
        } else {
            break;
        }
    }
    for(int i = 0; i < (strlen(origen)); i++) {
        if(*origen == 32) {
            spacesL++;
        } else {
            break;
        }
    }
    int p = 0;
    for(int i = spacesL; i < (strlen(origen) - spacesL); i++) {
        destino[p] = origen[i];
        p++;
    }
}
void strMayMin(char *destino, const char *origen, may_min m) {
    for(int i = 0; i <= (strlen(origen) + 8); i++) {
        if (m == MAYUSCULAS) {
            *destino = toupper(*origen);
        } else {
            *destino = tolower(*origen);
        }
        origen++;
        destino++;
    }
}
