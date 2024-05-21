#ifndef PILASLIB_LIBRARY_H
#define PILASLIB_LIBRARY_H

#include <stdbool.h>

extern int top;

void push(int data);
int pop();
bool isFull();
bool isEmpty();
int peek();
int size();
void printStack();

#endif //PILASLIB_LIBRARY_H
