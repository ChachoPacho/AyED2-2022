#include <stdio.h>    /* printf(), scanf() */
#include <stdbool.h>  /* tipo bool         */
#include <assert.h>   /* assert() */

struct max_min_result {
    int max_value;
    int min_value;
    unsigned int max_position;
    unsigned int min_position;
};

struct max_min_result compute_max_min(int array[], unsigned int length)
{
    assert(length > 0);
    array = array;
    struct max_min_result result = { array[0], array[0], 0, 0 };

    // IMPLEMENTAR
    int value;

    for (unsigned int i = 1; i < length; i++) {
        value = array[i];

        if (value > result.max_value) {
            result.max_value = value;
            result.max_position = i;
        } else if (value < result.min_value) {
            result.min_value = value;
            result.min_position = i;
        }
    }

    return result;
}

int main(void)
{
    // PEDIR AL USUARIO QUE INGRESE LOS ELEMENTOS DEL ARREGLO.
    unsigned int arraySize = 0;
    int arrayItemValue;

    printf("Longitud del array: ");
    scanf("%u", &arraySize);
    printf("\n");

    int array[arraySize];

    for (unsigned int i = 0; i < arraySize; i++) {
        printf("Array Item Nº%u: ", i);
        scanf("%d", &arrayItemValue);

        array[i] = arrayItemValue;
    }

    printf("\n");

    struct max_min_result result = compute_max_min(array, arraySize);
    printf("Máximo: %d\n", result.max_value);
    printf("Posición del máximo: %u\n", result.max_position);
    printf("Mínimo: %d\n", result.min_value);
    printf("Posición del mínimo: %u\n", result.min_position);
    return 0;
}

