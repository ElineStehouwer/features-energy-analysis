#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <gc/gc.h>
#include <string.h>


#define malloc(x) GC_MALLOC(x)
#define calloc(n,x) GC_MALLOC((n)*(x))
#define realloc(p,x) GC_REALLOC((p),(x))
#define free(x) (x) = NULL

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
    // Calculate the offset in bytes
    size_t offset = index * element_size;

    // Check if the index is within bounds
    if (index < 0 || index >= size) {
        fprintf(stderr, "Error: Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    // Cast the void pointer to the appropriate type and add the offset
    void *address = (char *)array + offset;

    // Copy the value to the memory location
    memcpy(address, value, element_size);
}

char *bin(uint32_t x);

void main_function() {
    for (size_t i = 0; i < 256; i++) {
        char *binstr = bin(i);
        // printf("%s\n", binstr);
        free(binstr);
    }
}

int main(void)
{
    for (int i =0; i < 1; i++){//3000000
        main_function();
    }
}


char *bin(uint32_t x)
{
    size_t bits = (x == 0) ? 1 : log10((double) x)/log10((double)2) + 1;
    char *ret = malloc((bits + 1) * sizeof (char));
    char new_value;
    for (size_t i = 0; i < bits ; i++) {
       new_value = (x & 1) ? '1' : '0';
       //setArrayValueSafe(ret, bits-i-1, (bits + 1) * sizeof (char), sizeof(char), &new_value); //ret[bits - i - 1] = (x & 1) ? '1' : '0';
       setSafe(ret, bits-i-1, bits+1, new_value);
       x >>= 1;
    }
    new_value = '\0';
    // setArrayValueSafe(ret, bits, (bits + 1) * sizeof (char), sizeof(char), &new_value); // ret[bits] = '\0';
    setSafe(ret, bits, bits+1, new_value);
    return ret;
}
