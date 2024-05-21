#ifndef LIB_LIBRARY_H
#define LIB_LIBRARY_H

#include <stdbool.h>

struct node {
    int data;
    struct node *right;
    struct node *left;
};

struct node *getNewNode(int data);
struct node *insert(struct node *root, int data);
bool isInTheTree(struct node *root, int data);
struct node *findMin(struct node *root);
struct node *findMax(struct node *root);
struct node *delete(struct node *root, int data);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);

#endif //LIB_LIBRARY_H
