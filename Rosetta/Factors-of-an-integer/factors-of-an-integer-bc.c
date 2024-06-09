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

typedef struct {
    int *list;
    short count;
} Factors;

void xferFactors( Factors *fctrs, int *flist, int flix )
{
    int ix, ij;
    int newSize = fctrs->count + flix;
    if (newSize > flix)  {
        fctrs->list = realloc( fctrs->list, newSize * sizeof(int));
    }
    else {
        fctrs->list = malloc(  newSize * sizeof(int));
    }
    for (ij=0,ix=fctrs->count; ix<newSize; ij++,ix++) {

        // fctrs->list[ix] = flist[ij];
        //setArrayValueSafe(fctrs->list, ix, newSize, sizeof(int), (int *) getArrayValueSafe(flist, ij, 301, sizeof(int) ));
        setSafe(fctrs->list, ix, newSize, getSafe(flist, ij, 301))
    }
    fctrs->count = newSize;
}

Factors *factor( int num, Factors *fctrs)
{
    int flist[301], flix;
    int new_value;
    int dvsr;
    flix = 0;
    fctrs->count = 0;
    free(fctrs->list);
    fctrs->list = NULL;
    for (dvsr=1; dvsr*dvsr < num; dvsr++) {
        if (num % dvsr != 0) continue;
        if ( flix == 300) {
            xferFactors( fctrs, flist, flix );
            flix = 0;
        }
        // flist[flix++] = dvsr;
        // setArrayValueSafe(flist, flix++, 301, sizeof(int), &dvsr);
        setSafe(flist, flix, 301, dvsr);
        flix++;
        // flist[flix++] = num/dvsr;
        new_value = num/dvsr;
        // setArrayValueSafe(flist, flix++, 301, sizeof(int), &new_value);
        setSafe(flist, flix, 301, new_value);
        flix++;
    }
    if (dvsr*dvsr == num)
        // flist[flix++] = dvsr;
        // setArrayValueSafe(flist, flix++, 301, sizeof(int), &dvsr);
        setSafe(flist, flix, 301, dvsr);
        flix++;
    if (flix > 0)
        xferFactors( fctrs, flist, flix );

    return fctrs;
}

void main_function() {
    int nums2factor[] = { 2059, 223092870, 3135, 45 };
    const int no_of_num = 4;
    Factors ftors = { NULL, 0};
    char sep;
    int i,j;

    for (i=0; i<4; i++) {
        // factor( nums2factor[i], &ftors );
        // factor( *(int *) getArrayValueSafe(nums2factor, i, no_of_num, sizeof(int)), &ftors );
        factor(getSafe(nums2factor, i, no_of_num), &ftors);
        // printf("\nfactors of %d are:\n  ", nums2factor[i]);
        // printf("\nfactors of %d are:\n  ", *(int *) getArrayValueSafe(nums2factor, i, no_of_num, sizeof(int)));
        // sep = ' ';
        // for (j=0; j<ftors.count; j++) {
        //     // printf("%c %d", sep, ftors.list[j]);
        //     printf("%c %d", sep, *(int *) getArrayValueSafe(ftors.list, j, ftors.count, sizeof(int)));
        //     sep = ',';
        // }
        // printf("\n");
    }
}

int main(int argc, char*argv[])
{
    for (int i = 0; i < 1; i++) {//400000
        main_function();
    }
    return 0;
}
