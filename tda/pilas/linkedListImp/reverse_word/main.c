#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define STRING_SIZE 100

struct node {
    char letter;
    struct node *link;
} *top = NULL;

void push(char letter);
char pop();
bool isEmpty();

int main() {
    char *string = malloc(STRING_SIZE * sizeof(char ));

    system("clear");
    printf("Ingrese la palabra o frase que desee invertir: ");
    fgets(string, STRING_SIZE, stdin);
    for (int i = 0; i < strlen(string) - 1; i++) {
        push(string[i]);
    }
    printf("Palabra o frase invertida: ");
    while(!isEmpty()) {
        printf("%c", pop());
    }
    printf("\n");

    return 0;
}
void push(char letter) {
    struct node *element = malloc(sizeof(struct node));
    if(element == NULL) {
        printf("Error al reservar memoria para el nuevo nodo.\n");
        exit(1);
    }
    element->letter = letter;
    element->link = top;
    top = element;
}
char pop() {
    if(isEmpty()) {
        printf("Error. La lista se encuentra vacia.\n");
        exit(1);
    }
    char value = top->letter;
    top = top->link;
    return value;
}
bool isEmpty() {
    if(top == NULL) {
        return true;
    }
    return false;
}