// License: CC BY-NC-SA 4.0
/*
 * task3.c
 *
 * Binary files.
 *
 * Written by AlexeyFilich
 * 01 mar 2021
 */

#include <stdio.h>
#include <stdlib.h>

#include "Interactions.h"

void writeBinary(char filename[128], int * array, int size) {
    FILE * file = fopen(filename, "wb+");
    if (!file) {
        printf("Can't open file!\n");
        exit(-1);
    }
    fwrite(array, sizeof(int), size, file);
    fclose(file);
}

void readBinary(char filename[128], int * array, int size) {
    FILE * file = fopen(filename, "rb+");
    if (!file) {
        printf("Can't open file!\n");
        exit(-1);
    }
    fread(array, sizeof(int), size, file);
    fclose(file);
}

int main(int argc, char * argv[]) {
    char filename[128];
    aScanCheck("File name: ", "%s", &filename);

    int size;
    aScanCheck("Size: ", "%d", &size);

    int * array = (int *)calloc(size, sizeof(int));
    readBinary(filename, array, size);
    for (int i = 0; i < size; i++)
        printf("[%2i] %3i ", i, array[i]);
    printf("\n");

    int k, temp;
    aScanCheck("k: ", "%d", &k);

    for (int i = 0; i < k; i++) {
        temp = array[size - 1];
        for (int j = size - 2; j >= 0; j--)
            array[j + 1] = array[j];
        array[0] = temp;
    }

    printf("Rotated:\n");
    for (int i = 0; i < size; i++)
        printf("[%2i] %3i ", i, array[i]);
    printf("\n");

    writeBinary(filename, array, size);

    free(array);
    return 0;
}
