#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define setSafe(array, index, size, value) {\
    if (index < 0 || index >= size) {\
        fprintf(stderr, "Error: Index out of bounds\n");\
        exit(EXIT_FAILURE);\
    }\
    array[index] = value;\
}

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


int hailstone(int n, int *arry, int arry_size)
{
    int hs = 1;

    while (n!=1) {
        hs++;
        if (arry) {
            // *arry++ = n;
            // setArrayValueSafe(arry, 0, arry_size, sizeof(int), &n);
            printf("n=%d\n", n);
            setSafe(arry, 0, arry_size, n);
            arry++;
            arry_size--;        
        }
        n = (n&1) ? (3*n+1) : (n/2);
    }
    if (arry) {
            // *arry++ = n;
            // setArrayValueSafe(arry, 0, arry_size, sizeof(int), &n);
            printf("n=%d\n", n);
            setSafe(arry, 0, arry_size, n);
            arry++;
            arry_size--;        
    }
    return hs;
}

void main_function() {
    int j, hmax = 0;
    int jatmax =0, n = 0;
    // int *arry;

    for (j=1; j<100000; j++) {
       n = hailstone(j, NULL, 0);
       if (hmax < n) {
           hmax = n;
           jatmax = j;
       }
    }
    n = hailstone(27, NULL, 0);
    // arry = malloc(n*sizeof(int));
    // int arry[227];
    // n = hailstone(27, arry, n);

    // printf("[ %d, %d, %d, %d, ...., %d, %d, %d, %d] len=%d\n",
    //     arry[0],arry[1],arry[2],arry[3],
    //     arry[n-4], arry[n-3], arry[n-2], arry[n-1], n);
    // printf("[ %d, %d, %d, %d, ...., %d, %d, %d, %d] len=%d\n", 
    //     *(int *)getArrayValueSafe(arry, 0, n, sizeof(int)),
    //     *(int *)getArrayValueSafe(arry, 1, n, sizeof(int)),
    //     *(int *)getArrayValueSafe(arry, 2, n, sizeof(int)),
    //     *(int *)getArrayValueSafe(arry, 3, n, sizeof(int)),
    //     *(int *)getArrayValueSafe(arry, n-4, n, sizeof(int)),
    //     *(int *)getArrayValueSafe(arry, n-3, n, sizeof(int)),
    //     *(int *)getArrayValueSafe(arry, n-2, n, sizeof(int)),
    //     *(int *)getArrayValueSafe(arry, n-1, n, sizeof(int)),
    //     n);

    // printf("Max %d at j= %d\n", hmax, jatmax);
    // free(arry);
}

int main()
{
    for (int i = 0; i < 1; i++) { //1500
            main_function();
    }

    return 0;
}
