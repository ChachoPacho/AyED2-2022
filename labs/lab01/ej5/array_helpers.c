#include "array_helpers.h"
#include "mybool.h"
#include <stdio.h>

unsigned int array_from_file(int array[],
           const char *filepath) {
    //your code here!!!

    FILE * file = fopen(filepath, "r");
    unsigned int length;
    fscanf(file, "%u", &length);
    
    for (unsigned int i = 0; i < length; i++) {
        fscanf(file, "%d", &array[i]);
    }
    
    return length;
}

void array_dump(int a[], unsigned int length) {
    //your code here!!!!!
    printf("[");

    for (unsigned int i = 0; i < length; i++)
    {
        printf("%d", a[i]);
        if (i != length - 1)
        {
            printf(", ");
        }
        
    }
    
    printf("]\n");
}

mybool array_is_sorted(int a[], unsigned int length) {
    for (unsigned int i = 0; i < length - 1; i++)
    {
       if (a[i] > a[i + 1]) return false;
    }
    
    return true;
}