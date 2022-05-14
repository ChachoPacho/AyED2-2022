#include <assert.h>
#include <stdio.h>

#include "list.h"

list list_empty(void) {
    list node = malloc(sizeof(list));

    return node;
}

void list_addl(list_elem e, list * l) {
    list node = malloc(sizeof(list));

    node->elem = e;
    node->next = *l;

    *l = node;
}

bool list_is_empty(list l) {
    return l == NULL;
}

void list_tail(list* l) {
    assert(!list_is_empty(*l));

    list node = (*l)->next;

    free(*l);

    *l = node;
}

list_elem list_head(list l) {
    assert(!list_is_empty(l));

    return l->elem;
}

void list_addr(list_elem e, list l) {
    list node = l;

    while (!list_is_empty(node->next)) {
        node = node->next;
    }
    
    node->next = list_empty();
    node->next->elem = e;
}

unsigned int list_length(list l) {
    list node = l;
    unsigned int length = 0;

    while (!list_is_empty(node)) {
        node = node->next;
        length++;
    }
    
    return length;
}

void list_concat(list l, list l0) {
    list node = l;

    while (!list_is_empty(node->next)) {
        node = node->next;
    }

    node->next = l0;
}

list_elem list_index(list l, unsigned int n) {
    list node = l;
    unsigned int i = 0;

    while (!list_is_empty(node) && i < n) {
        node = node->next;
        i++;
    }

    assert(i < n);
    
    return node->elem;
}

void list_take(list l, unsigned int n) {
    list node = l;
    unsigned int i = 0;

    while (!list_is_empty(node) && i < n) {
        node = node->next;
        i++;
    }

    assert(i < n);
    
    list_destroy(node);
}

void list_drop(list* l, unsigned int n) {
    list node;
    unsigned int i = 0;

    while (!list_is_empty((*l)->next) && i < n) {
        node = *l;

        l = &(*l)->next;

        free(node);
    }
}

list list_copy(list l) {
    list node;
    list copy_nodeI;
    list copy_l = list_empty();

    node = l;
    copy_nodeI = copy_l;

    if (!list_is_empty(node)) {
        while (!list_is_empty(node->next)) {
            copy_nodeI->elem = node->elem;
            copy_nodeI->next = list_empty();

            node = node->next;
            copy_nodeI = copy_nodeI->next;
        }

        copy_nodeI->elem = node->elem;
        copy_nodeI->next = NULL;
    }

    return copy_l;
}

void list_destroy(list l) {
    if (!list_is_empty(l)) {
        list node;

        while (!list_is_empty(l->next)) {
            node = l;

            l = l->next;

            free(node);
        }
    }

    free(l);
}