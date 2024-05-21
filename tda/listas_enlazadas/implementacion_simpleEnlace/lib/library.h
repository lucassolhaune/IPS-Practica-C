#ifndef LIB_LIBRARY_H
#define LIB_LIBRARY_H

#include <stdbool.h>

void add_at_beg(int data);
void add_at_pos(int data, int pos);
void add_at_end(int data);
int del_beg();
int del_pos(int pos);
int del_last();
bool isEmpty();
void printList();

#endif //LIB_LIBRARY_H
