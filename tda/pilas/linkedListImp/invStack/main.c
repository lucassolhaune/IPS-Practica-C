#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *link;
};
void push(int data, struct node **top);
int pop(struct node **top);
bool isEmpty(struct node *top);
void print(struct node *top);
void pushPop(struct node **top1, struct node **top2);
void reverseStack(struct node **top);
int main() {
    int input;
    char option;
    struct node *top = NULL;

    system("clear");
    printf("Ingrese los numeros que desee agregar al top.\n");
    do {
        printf("\t>>> ");
        scanf("%d", &input);
        push(input, &top);
        printf("Desea agregar otro numero? [Y/N]: ");
        scanf(" %c", &option);
    } while(option != 'n' && option != 'N');
    system("clear");

    reverseStack(&top);

    return 0;
}
void push(int data, struct node **top) {
    struct node *newNode = malloc(sizeof(struct node));
    if(newNode == NULL) {
        printf("Error. No se pudo reservar memoria para el nuevo nodo.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = *top;
    *top = newNode;
}
int pop(struct node **top) {
    struct node *tmp;
    int value;
    if(isEmpty(*top)) {
        printf("Error. El stack se encuentra vacio.\n");
        exit(1);
    }
    tmp = *top;
    value = tmp->data;
    *top = (*top)->link;
    return value;
}
bool isEmpty(struct node *top) {
    if(top == NULL) {
        return 1;
    } else {
        return 0;
    }
}
void print(struct node *top) {
    struct node *tmp = top;
    if(isEmpty(top)) {
        printf("Error. El stack se encuentra vacio.\n");
        exit(1);
    }
    while(tmp) {
        printf("\t\t");
        printf("%d", tmp->data);
        printf("\n");
        tmp = tmp->link;
    }
}
void pushPop(struct node **top1, struct node **top2) {
    while(*top1 != NULL) {
        push(pop(top1), top2);
    }
}
void reverseStack(struct node **top) {
    struct node *tmpTop1 = NULL;
    struct node *tmpTop2 = NULL;

    printf("Stack Original:\n");
    print(*top);
    printf("=================================\n");

    pushPop(top, &tmpTop1);
//    printf("Stack temporal 1:\n");
//    print(tmpTop1);
    pushPop(&tmpTop1, &tmpTop2);
//    printf("Stack temporal 2:\n");
//    print(tmpTop2);
    pushPop(&tmpTop2, top);
    printf("Stack original invertido:\n");
    print(*top);
}
