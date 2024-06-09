#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define setSafe(array, index, size, value) {\
    if (index < 0 || index >= size) {\
        fprintf(stderr, "Error: Index out of bounds\n");\
        exit(EXIT_FAILURE);\
    }\
    array[index] = value;\
}

#define getSafe(array, index, size) ({\
    if (index < 0 || index >= size) {\
        fprintf(stderr, "Error: Index out of bounds\n");\
        exit(EXIT_FAILURE);\
    }\
    array[index];\
})

void *getArrayValueSafe(void *array, size_t index, size_t size, size_t element_size) {
    if (index < 0 || index >= size) {
        fprintf(stderr, "Error: Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    // Calculate the offset in bytes
    size_t offset = index * element_size;

    // Cast the void pointer to the appropriate type and add the offset
    void *address = (char *)array + offset;

    // Return the pointer to the element
    return address;
}

void setArrayValueSafe(void *array, size_t index, size_t size, size_t element_size, void *value) {

    // Check if the index is within bounds
    if (index < 0 || index >= size) {
        fprintf(stderr, "Error: Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    // Calculate the offset in bytes
    size_t offset = index * element_size;

    // Cast the void pointer to the appropriate type and add the offset
    void *address = (char *)array + offset;

    // Copy the value to the memory location
    memcpy(address, value, element_size);
}

void sieve(int *, int);

void main_function() {
    // int *array, n=10000;
    int n=10001;
    // array =(int *)malloc(n*sizeof(int));
    int array [10001];
    sieve(array,n);
}

int main(int argc, char **argv)
{
    for (int i = 0; i < 1; i++) { //3000
        main_function();
    }
    return 0;
}

void sieve(int *a, int n)
{
    int i=0, j=0;

    for(i=2; i<n; i++) {
        // a[i] = 1;
        // setArrayValueSafe(a, i, n, sizeof(int), (int[]){1});
        setSafe(a, i, n, 1);
    }

    for(i=2; i<n; i++) {
        // if(a[i] == 1) {
        if(getSafe(a, i, n) == 1) {
            for(j=i; (i*j)<n; j++) {
                // a[(i*j)] = 0;
                // setArrayValueSafe(a, (i*j), n, sizeof(int), (int[]){0});
                setSafe(a, (i*j), n, 0);
            }
        }
    }

    // for(i=2; i<n; i++) {
    //     // if(a[i] == 1)
    //     if(*(int *) getArrayValueSafe(a, i, n, sizeof(int)) == 1)
    //         printf("%d ", i);
    // }
    // printf("\n");
}
