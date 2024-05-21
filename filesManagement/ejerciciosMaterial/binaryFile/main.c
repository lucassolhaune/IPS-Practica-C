#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 150

typedef struct record {
    char *textLine;
} Record;

int main() {
    FILE *fPointer = fopen("familia.txt", "r");
    FILE *fPointer2 = fopen("copia_familia.bin", "wb");
    Record *dataRecord = (Record *)malloc(10 * sizeof(Record));
    Record *pDataRecord = dataRecord;
    int totalLines = 0, writeCheck, readCheck;

    if((fPointer == NULL) || (fPointer2 == NULL)) {
        printf("Error al abrir el/los archivos\n");
        exit(-1);
    }
    while(!feof(fPointer)) {
        dataRecord->textLine = (char *)malloc(BUF_SIZE * sizeof(char));
        fgets(dataRecord->textLine, BUF_SIZE, fPointer);
        writeCheck = (int)fwrite(dataRecord, sizeof(Record), 1, fPointer2);
        if(writeCheck != 1) {
            printf("Error al escribir en el archivo binario.\n");
            exit(-1);
        }
        totalLines ++;
        dataRecord ++;
    }
    dataRecord = pDataRecord;
    fclose(fPointer2);
    fPointer2 = fopen("copia_familia.bin", "rb");

    for(int i = 0; i < totalLines; i++) {
        readCheck = (int)fread(dataRecord, sizeof(Record), 1, fPointer2);
        if(readCheck != 1) {
            printf("Error al leer en el archivo binario.\n");
            exit(-1);
        }
        printf("%s", dataRecord->textLine);
        dataRecord ++;
    }
    dataRecord = pDataRecord;
    free(dataRecord);
    fclose(fPointer);
    fclose(fPointer2);

    return 0;
}