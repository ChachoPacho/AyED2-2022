#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000


static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

unsigned int data_from_file(
    const char *path,
    unsigned int indexes[],
    char letters[],
    unsigned int max_size
) {
    if (path == NULL) {
        printf("NO SE PUEDE LEER EL ARCHIVO");
        return 0;
    }

    FILE* pointer = fopen(path, "rt");
    unsigned int i = 0;

    while (!feof(pointer) && i < max_size) {
        fscanf(pointer, "%u '%c'\n", &indexes[i], &letters[i]);
        i++;
    }

    fclose(pointer);

    return i;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    filepath = argv[argc - 1];

    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length = data_from_file(filepath, indexes, letters, MAX_SIZE);

    for (unsigned i = 0; i < length; i++) {
        if (MAX_SIZE <= indexes[i]) {
            return EXIT_FAILURE;
        }
        sorted[indexes[i]] = letters[i];
    }

    dump(sorted, length);

    return EXIT_SUCCESS;
}