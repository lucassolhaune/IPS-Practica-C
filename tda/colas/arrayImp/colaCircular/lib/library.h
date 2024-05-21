#ifndef LIB_LIBRARY_H
#define LIB_LIBRARY_H

#include <stdbool.h>

void enqueue(int data);
int dequeue();
bool isFull();
bool endOfQueue();
bool isEmpty();
int peek();
int size();
void printCola();

#endif //LIB_LIBRARY_H
