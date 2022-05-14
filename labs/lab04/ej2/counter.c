#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

unsigned int COUNT_START_AT = 0;

counter counter_init(void) {
    counter c;
    
    c = malloc(sizeof(struct _counter));

    c->count = COUNT_START_AT;

    assert(counter_is_init(c));

    return c;
}

void counter_inc(counter c) {
    c->count++;
}

bool counter_is_init(counter c) {
    return c->count == COUNT_START_AT;
}

void counter_dec(counter c) {
    //assert(counter_is_init(c));

    c->count--;
}

counter counter_copy(counter c) {
    counter copy_c = counter_init();

    copy_c->count = c->count;

    return copy_c;
}

void counter_destroy(counter c) {
    free(c);
}
