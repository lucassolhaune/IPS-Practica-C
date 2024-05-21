#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 200

int main() {
    FILE *people = fopen("people.txt", "r");
    char *readLine = (char *)malloc(BUF_SIZE * sizeof(char));

    if(people == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(-1);
    }
    while(!feof(people)) {
        fgets(readLine, BUF_SIZE, people);
        puts(readLine);
    }

    fclose(people);
    return 0;
}