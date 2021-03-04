// License: CC BY-NC-SA 4.0
/*
 * task1.c
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
    for (int i = 0; i < size; i++)
        aScanCheck("Number: ", "%d", &array[i]);
    writeBinary(filename, array, size);

    int * array_read = (int *)calloc(size, sizeof(int));
    readBinary(filename, array_read, size);
    for (int i = 0; i < size; i++)
        printf("[%2i] %3i ", i, array_read[i]);
    printf("\n");

    free(array);
    free(array_read);
    return 0;
}
