#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fPointer = fopen("familia.txt", "r");
    int charReader;
    if(fPointer == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(-1);
    }
    while(!feof(fPointer)) {
        charReader = getc(fPointer);
        if((char)charReader != EOF) {
            printf("%c", (char)charReader);
        }
    }
    printf("\n");
    fclose(fPointer);
    return 0;
}
