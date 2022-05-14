#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef int list_elem;

typedef struct Node {
    list_elem elem;
    struct Node* next;
} * list;

/* Constructors */
list list_empty(void);
/*
    Crea una lista vacía
*/

void list_addl(list_elem e, list* l);
/*
    Agrega el elemento e al comienzo de la lista l
*/

/* Operations */
bool list_is_empty(list l);
/*
    Devuelve True si l es vacía
*/

void list_tail(list* l);
/*
    Elimina el primer elemento de la lista l
    PRE: not list_is_empty(l)
*/

list_elem list_head(list l);
/*
    Devuelve el primer elemento de la lista l
    PRE: not list_is_empty(l)
*/

void list_addr(list_elem e, list l);
/*
    Agrega el elemento e al final de la lista l
*/

unsigned int list_length(list l);
/*
    Devuelve la cantidad de elementos de la lista l
*/

void list_concat(list l, list l0);
/*
     Agrega al final de l todos los elementos de l0 en el mismo orden
*/

list_elem list_index(list l, unsigned int n);
/*
    Devuelve el n-ésimo elemento de la lista l
    PRE: length(l) > n
*/

void list_take(list l, unsigned int n);
/*
    Deja en l sólo los primeros n elementos, eliminando el resto
*/

void list_drop(list* l, unsigned int n);
/*
    Elimina los primeros n elementos de l
*/

list list_copy(list l);
/*
    Makes a copy of list c. Allocates new memory.
*/

void list_destroy(list l);
/*
   Frees memory for c.
*/

#endif
