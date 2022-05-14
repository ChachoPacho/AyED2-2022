/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

unsigned int array_from_file(int array[]) {
    //your code here!!!

    int length;
    printf("Longitud del array: ");
    scanf("%d", &length);
    
    for (int i = 0; i < length; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &array[i]);
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


int main() {
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array);
    
    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
