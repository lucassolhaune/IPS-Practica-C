#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 100
void separateName(const char *singleLine, char *name, int lineLength);
void separateSurname(const char *singleLine, char *surname, int lineLength);
int main() {
    FILE *fPointer1 = fopen("familia.txt", "r");
    FILE *fPointer2 = fopen("familiaInv.txt", "w");
    char *singleLine = (char *)malloc(BUF_SIZE * sizeof(char));
    int lineLength;

    while(!feof(fPointer1)) {
        char *name = (char *)malloc(BUF_SIZE * sizeof(char));
        char *surname = (char *)malloc(BUF_SIZE * sizeof(char));

        fgets(singleLine, BUF_SIZE, fPointer1);
        lineLength = (int)strlen(singleLine) - 1;

        separateName(singleLine, name, lineLength);
        separateSurname(singleLine, surname, lineLength);

        fprintf(fPointer2, "%s %s\n", surname, name);
    }
    fclose(fPointer1);
    fclose(fPointer2);
    return 0;
}
void separateName(const char *singleLine, char *name, int lineLength) {
    for(int i = 0; i < lineLength; i++) {
        if(singleLine[i] == ' ') {
            for(int k = 0; k < i; k++) {
                name[k] = singleLine[k];
            }
            break;
        }
    }
}
void separateSurname(const char *singleLine, char *surname, int lineLength) {
    for(int i = lineLength - 1; i >= 0; i--) {
        if(singleLine[i] == ' ') {
            int j = 0;
            if(singleLine[lineLength] == '\n') {
                for(int k = i + 1; k < lineLength; k++) {
                    surname[j] = singleLine[k];
                    j++;
                }
            } else {
                for(int k = i + 1; k <= lineLength; k++) {
                    surname[j] = singleLine[k];
                    j++;
                }
            }
            break;
        }
    }
}

