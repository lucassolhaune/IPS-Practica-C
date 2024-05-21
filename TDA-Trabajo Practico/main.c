#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_NAME_LENGTH 14

void insertarPrincipio(char mandato, char *nombre);
void insertarEnPosicion(char mandato, char *nombre, int pos);
void insertarFinal(char mandato, char *nombre);
char *suprimirPrincipio();
char *suprimirEnPosicion(int pos);
char *suprimirFinal();
bool esUnicoNodo();
bool estaVacio();
bool esMiembro(char mandato, char *nombre);
void mostrarListaGeneral();
void mostrarListaChicosBuenos();
void mostrarListaChicosMalos();

struct node {
    char mandato;
    char *nombre;
    struct node *link;
};
struct node *head = NULL;

int main() {
    int menu, pos;
    char subMenu, restart, mandato;
    do {
        char *nombre = malloc(MAX_NAME_LENGTH * sizeof(char));
        system("clear");
        printf("Ingrese:\n");
        printf("0. Salir.\n");
        printf("1. Agregar legisladores.\n");
        if(!(estaVacio())) {    //Si la lista se encuentra vacia, no se muestran las siguientes opciones.
            printf("2. Eliminar legisladores.\n");
            printf("3. Buscar un legislador.\n");
            printf("4. Mostrar lista.\n");
        }
        printf(">> ");
        scanf("%d", &menu);
        getchar();
        if(((estaVacio()) && ((menu != 1) && (menu != 0))) || (menu < 0) || (menu > 4)) {
            printf("\tEl valor ingresado no corresponde con ninguna de las opciones.\n");
            continue;
        }
        switch(menu) {
            case 0:
                return 0;
                //Caso 1: Agregar un legislador a la lista. Se presentan 3 subopciones:
                //  -Agregar al principio de la lista.
                //  -Agregar en una posicion determinada.
                //  -Agregar al final de la lista.
            case 1:
                printf("\tIngrese el nombre del legislador: ");
                fgets(nombre, MAX_NAME_LENGTH, stdin);
                nombre[strcspn(nombre, "\n")] = 0;  //Borra el newline del 'ENTER'
                do {
                    printf("\tIngrese el mandato del legislador [F/D]: ");
                    scanf(" %c", &mandato);
                    getchar();
                    mandato = toupper(mandato);  //Pasa el input del usuario a mayusculas para facilitar la comparacion
                } while(mandato != 'F' && mandato != 'D');

                printf("\n\ta. Agregar al principio de la lista.\n");
                printf("\tb. Agregar en una posicion personalizada de la lista.\n");
                printf("\tc. Agregar al final de la lista.\n");
                printf("\t>> ");
                scanf(" %c", &subMenu);
                getchar();
                switch(subMenu) {
                    case 'a':
                        insertarPrincipio(mandato, nombre);
                        break;
                    case 'b':
                        printf("\n\tIngrese la posicion en que lo quiera agregar: ");
                        scanf("%d", &pos);
                        getchar();
                        insertarEnPosicion(mandato, nombre, pos);
                        break;
                    case 'c':
                        insertarFinal(mandato, nombre);
                        break;
                    default:
                        printf("\n\tEl valor ingresado no corresponde con ninguna de las opciones.\n");
                }
                printf("\n\tResultado de la lista:\n");
                mostrarListaGeneral();
                break;
                //Caso 2: Eliminar un legislador de la lista. Se presentan 3 subopciones:
                //  -Eliminar el primero de la lista.
                //  -Eliminar en una posicion determinada.
                //  -Eliminar el ultimo de la lista.
            case 2:
                printf("\n\tPresione:\n");
                printf("\ta. Eliminar el primer numero de la lista.\n");
                printf("\tb. Eliminar un numero en una posicion personalizada de la lista.\n");
                printf("\tc. Eliminar el ultimo numero de la lista.\n");
                printf("\t>> ");
                scanf(" %c", &subMenu);
                getchar();
                switch(subMenu) {
                    case 'a':
                        printf("\n\tEl legislador %s ha sido eliminado con exito.\n", suprimirPrincipio());
                        break;
                    case 'b':
                        printf("\n\tIngrese la posicion del legislador que quiera eliminar: ");
                        scanf("%d", &pos);
                        getchar();
                        printf("\tEl legislador %s ha sido eliminado con exito.\n", suprimirEnPosicion(pos));
                        break;
                    case 'c':
                        printf("\n\tEl legislador %s ha sido eliminado con exito.\n", suprimirFinal());
                        break;
                    default:
                        printf("\n\tEl valor ingresado no corresponde con ninguna de las opciones.\n");
                }
                printf("\n\tResultado de la lista:\n");
                mostrarListaGeneral();
                break;
                //Caso 3: Se busca y se informa si un legislador se encuentra en un conjunto determinado.
            case 3:
                printf("\n\tIngrese el nombre del legislador que desee buscar: ");
                fgets(nombre, MAX_NAME_LENGTH, stdin);
                nombre[strcspn(nombre, "\n")] = 0;  //Borra el newline del 'ENTER'
                do {
                    printf("\tIngrese el mandato del legislador [F/D]: ");
                    scanf(" %c", &mandato);
                    mandato = toupper(mandato); //Pasa el input del usuario a mayusculas para facilitar la comparacion
                    getchar();
                } while(mandato != 'F' && mandato != 'D');
                if(esMiembro(mandato, nombre)) {
                    printf("%s es miembro del conjunto ", nombre);
                } else {
                    printf("%s no es miembro del conjunto ", nombre);
                }
                if(mandato == 'F') {
                    printf(" chicos buenos.\n");
                } else {
                    printf(" chicos malos.\n");
                }
                break;
                //Caso 4: Se muestra en pantalla la lista de legisladores con 3 opciones:
                //  -Mostrar la lista de legisladores en general, es decir ambos conjuntos.
                //  -Mostrar la lista de legisladores a favor.
                //  -Mostrar la lista de legisladores en contra.
            case 4:
                printf("\n\tPresione:\n");
                printf("\ta. Mostrar lista general.\n");
                printf("\tb. Mostrar lista del conjunto chicos buenos.\n");
                printf("\tc. Mostrar lista del conjunto chicos malos.\n");
                printf("\t>> ");
                scanf(" %c", &subMenu);
                getchar();
                printf("\tMostrando lista ");
                switch(subMenu) {
                    case 'a':
                        printf("general...\n");
                        mostrarListaGeneral();
                        break;
                    case 'b':
                        printf("de chicos buenos...\n");
                        mostrarListaChicosBuenos();
                        break;
                    case 'c':
                        printf("de chicos malos...\n");
                        mostrarListaChicosMalos();
                        break;
                    default:
                        printf("\tEl valor ingresado no corresponde con ninguna de las opciones.\n");
                }
                break;
            default:
                break;
        }
        printf("Desea realizar otra operacion? [Y/N]: ");
        scanf(" %c", &restart);
        getchar();
    } while(restart != 'n' && restart != 'N');

    return 0;
}
/**
 * Funcion para insertar un nodo al comienzo de la lista.
 *
 * Para ello, se crea un nuevo nodo. Luego, se copian los datos ingresados por el usuario hacia el nodo creado y,
 * si la lista se encuentra vacia, hacemos que el nodo no apunte a nada. Caso contrario, el nuevo nodo apunta al nodo
 * que antes se encontraba primero y hacemos que Head apunte hacia este.
 *
 * @param mandato: Variable que almacena si un legislador esta a favor o en contra.
 * @param nombre: Nombre del legislador.
 */
void insertarPrincipio(char mandato, char *nombre) {
    struct node *new = malloc(sizeof(struct node));
    if(new == NULL) {
        printf("Error al agregar un elemento al principio de la lista.\n");
        return;
    }
    new->mandato = mandato;
    new->nombre = nombre;
    if(estaVacio()) {
        new->link = NULL;
        head = new;
        return;
    }
    new->link = head;
    head = new;
}
/**
 * Funcion para insertar nodo en una posicion determinada de la lista.
 *
 * La funcion crea dos nodos: new donde se almacenaran los datos y ptr que apunta al comienzo de la lista.
 * Con el nodo ptr conseguimos desplazarnos por la lista hasta llegar a la posicion deseada e ingresamos el nodo new
 * en la misma.
 *
 * Para ingresar el nodo, hacemos que new apunte al enlace de ptr y que el enlace de ptr ahora apunte a new.
 * De esta forma, quedaria entre los nodos con la posicion indicada.
 *
 * @param mandato: Variable que almacena si un legislador esta a favor o en contra.
 * @param nombre: Nombre del legislador.
 * @param pos: Posicion donde se almacenara el nodo.
 */
void insertarEnPosicion(char mandato, char *nombre, int pos) {
    struct node *new = malloc(sizeof(struct node));
    struct node *ptr = head;
    if(new == NULL) {
        printf("Error al agregar un elemento en la lista.\n");
        return;
    }
    new->mandato = mandato;
    new->nombre = nombre;
    if(estaVacio()) {
        new->link = NULL;
        head = new;
        return;
    }
    //Si queremos guardarlo en la primera posicion, se procede a realizar lo mismo que en la funcion
    //para ingresarlo al principio de la lista.
    if(pos == 1) {
        new->link = head;
        head = new;
        return;
    }
    for(int i = 1; i < pos - 1; i ++) {
        if(ptr->link == NULL) {
            new->link = NULL;
            ptr->link = new;
            return;
        }
        ptr = ptr->link;
    }

    new->link = ptr->link;
    ptr->link = new;
}
/**
 * Funcion para insertar nodo al final de la lista.
 *
 * Crea dos nodos, new para almacenar los datos y ptr que apunta al principio de la lista. Almacena los datos en el nodo
 * new, con su enlace en NULL y nos desplazamos con ptr hacia el ultimo nodo de la lista. Al llegar al mismo, hacemos
 * que ese ultimo nodo ahora apunte al nodo nuevo.
 *
 * @param mandato: Variable que almacena si un legislador esta a favor o en contra.
 * @param nombre: Nombre del legislador.
 */
void insertarFinal(char mandato, char *nombre) {
    struct node *new = malloc(sizeof(struct node));
    struct node *ptr = head;
    if(new == NULL) {
        printf("Error al agregar un elemento al fina de la lista.\n");
        return;
    }
    new->mandato = mandato;
    new->nombre = nombre;
    new->link = NULL;
    if(estaVacio()) {
        head = new;
        return;
    }
    while(ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = new;
}
/**
 * Funcion para eliminar el primer nodo de la lista.
 *
 * Crea un nodo temporal que apunte al nodo que apunta head. Hacemos que head ahora apunte al nodo al que estaba
 * enlazado y eliminamos el nodo al que apunta tmp.
 *
 * @return Nombre del legislador eliminado.
 */
char *suprimirPrincipio() {
    if(estaVacio()) {
        printf("Error al eliminar un elemento. Lista vacia.\n");
        exit(1);
    }
    struct node *tmp = head;
    char *nombre = head->nombre;
    head = head->link;
    free(tmp);
    tmp = NULL;
    return nombre;
}
/**
 * Funcion para eliminar un nodo en una posicion determinada.
 *
 * Crea un nodo ptr que apunta a head para desplazarnos hasta la posicion indicada en pos. Si antes de llegar a dicha
 * posicion se encuentra con el ultimo nodo de la lista, entonces se eliminara el ultimo de la lista. Caso contrario,
 * crea un nuevo nodo tmp que apuntara al nodo que esta enlazado a ptr para luego ser eliminado.
 *
 * @param pos: Posicion del nodo que se eliminara.
 * @return Nombre del legislador eliminado.
 */
char *suprimirEnPosicion(int pos) {
    struct node *ptr = head;
    if(estaVacio()) {
        printf("Error al eliminar un elemento. Lista vacia.\n");
        exit(1);
    }
    for(int i = 1; i < pos - 1; i++) {
        if(ptr->link->link == NULL) {
            if(head->link == NULL) {
                head = NULL;
            }
            char *nombre = ptr->link->nombre;
            ptr->link = NULL;
            free(ptr->link);
            return nombre;
        }
        ptr = ptr->link;
    }
    char *nombre = ptr->link->nombre;
    struct node *tmp = ptr->link;
    ptr->link = ptr->link->link;
    free(tmp);
    tmp = NULL;
    return nombre;
}
/**
 * Funcion que elimina el ultimo nodo de la lista.
 *
 * Se crea el nodo ptr para desplazarse hasta el penultimo nodo de la lista. Al llegar a dicho nodo, se elimina el
 * nodo enlazado a este, que es el ultimo de la lista.
 *
 * @return Nombre del legislador eliminado.
 */
char *suprimirFinal() {
    struct node *ptr = head;
    char *nombre;
    if(estaVacio()) {
        printf("Error al eliminar un elemento. Lista vacia.\n");
        exit(1);
    }
    if(esUnicoNodo()) {
        nombre = ptr->nombre;
        free(head);
        head = NULL;
        return nombre;
    }

    while (ptr->link->link != NULL) {
        ptr = ptr->link;
    }
    nombre = ptr->link->nombre;
    free(ptr->link);
    ptr->link = NULL;
    return nombre;
}
bool esUnicoNodo() {
    if(head->link == NULL) {
        return true;
    }
    return false;
}
/**
 * Funcion que informa si una lista se encuentra vacia.
 * @return True si se encuentra vacia. False si no lo esta.
 */
bool estaVacio() {
    if(head == NULL) {
        return true;
    }
    return false;
}
/**
 * Funcion que informa si un miembro se encuentra ingresado en la lista.
 *
 * Analiza si el mandato y el nombre del legislador ingresados coinciden con algun nodo de la lista.
 *
 * @param mandato: Variable que almacena si un legislador esta a favor o en contra.
 * @param nombre: Nombre del legislador.
 * @return True si se encuentra en la lista. False en caso contrario.
 */
bool esMiembro(char mandato, char *nombre) {
    struct node *tmp = head;
    if(estaVacio()) {
        return false;
    }

    while(tmp) {
        if((tmp->mandato == mandato) && (strcmp(tmp->nombre, nombre) == 0)) {
            return true;
        } else {
            tmp = tmp->link;
        }
    }
    return false;
}
/**
 * Funcion que muestra la lista de legisladores en general, sin importar al conjunto que pertenezcan.
 */
void mostrarListaGeneral() {
    struct node *tmp = head;
    int elementPos;
    if(estaVacio()) {
        printf("\tLa lista esta vacia.\n");
        return;
    }
    elementPos = 1;
    while(tmp) {
        printf("\t%d° - %c - %s\n", elementPos, tmp->mandato, tmp->nombre);
        elementPos++;
        tmp = tmp->link;
    }
}
/**
 * Funcion que muestra solo la lista de legisladores que se encuentran a favor.
 */
void mostrarListaChicosBuenos() {
    struct node *tmp = head;
    int elementPos;
    if(estaVacio()) {
        printf("\tLa lista esta vacia.\n");
        return;
    }
    elementPos = 1;
    while(tmp) {
        if(tmp->mandato == 'F') {
            printf("\t%d° - %c - %s\n", elementPos, tmp->mandato, tmp->nombre);
            elementPos++;
        }
        tmp = tmp->link;
    }
}
/**
 * Funcion que muestra solo la lista de legisladores que se encuentran en contra.
 */
void mostrarListaChicosMalos() {
    struct node *tmp = head;
    int elementPos;
    if(estaVacio()) {
        printf("La lista esta vacia.\n");
        return;
    }
    elementPos = 1;
    while(tmp) {
        if(tmp->mandato == 'D') {
            printf("\t%d° - %c - %s\n", elementPos, tmp->mandato, tmp->nombre);
            elementPos++;
        }
        tmp = tmp->link;
    }
}