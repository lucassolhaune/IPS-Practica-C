#include "library.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * Esta funcion genera un nuevo nodo para el arbol.
 * @param data
 * @return nodo
 */
struct node *getNewNode(int data) {
    struct node *newElement = malloc(sizeof(struct node));
    newElement->data = data;
    newElement->right = NULL;
    newElement->left = NULL;
    return newElement;
}
struct node *insert(struct node *root, int data) {
    if(root == NULL) {
        root = getNewNode(data);
    } else if(data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}
bool isInTheTree(struct node *root, int data) {
    if(root == NULL) {
        return false;
    } else if(data == root->data) {
        return true;
    } else if(data < root->data){
        isInTheTree(root->left, data);
    } else {
        return isInTheTree(root->right, data);
    }
    return 0;
}

struct node *findMin(struct node *root) {
    while(root->left != NULL) {
        root = root->left;
    }
    return  root;
}
struct node *findMax(struct node *root) {
    while(root->right != NULL) {
        root = root->right;
    }
    return root;
}
struct node *delete(struct node *root, int data) {
    if(root == NULL) {
        printf("Error al eliminar un elemento del arbol. Se encuentra vacio.\n");
        return root;
    }
    if(!isInTheTree(root, data)) {
        printf("El elemento que desea eliminar no se pudo encontrar en el arbol.\n");
        return root;
    } else if(data < root->data) {
        root->left = delete(root->left, data);
    }  else if(data > root->data) {
        root->right = delete(root->right, data);
    } else {
        //Si el nodo no tiene hijos:
        if (root->right == NULL && root->left == NULL) {
            free(root);
            root = NULL;
        }
        //Si el nodo tiene un solo hijo del lado izquierdo:
        else if (root->right == NULL) {
            struct node *tmp = root;
            root = root->left;
            free(tmp);
        }
        //Si el nodo tiene un solo hijo del lado derecho:
        else if (root->left == NULL) {
            struct node *tmp = root;
            root = root->right;
            free(tmp);
        }
        //Si el nodo tiene 2 hijos:
        else if (root->right != NULL && root->left != NULL) {
            struct node *tmp = findMin(root->right);
            root->data = tmp->data;
            root->right = delete(root->right, tmp->data);
        }
    }
    return root;
}
void preorder(struct node *root) {
    if(root == NULL) {
        return;
    }
    printf("\t%d\n",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    printf("\t%d\n",root->data);
    inorder(root->right);
}
void postorder(struct node *root) {
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("\t%d\n", root->data);
}
