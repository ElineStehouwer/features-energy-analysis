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

void main_function (){
  char is_open[100] = { 0 };
  int pass, door;

  /* do the 100 passes */
  for (pass = 0; pass < 100; ++pass)
    for (door = pass; door < 100; door += pass+1) {
        char negation = !getSafe(is_open, door, 100); //!(*(char *) getArrayValueSafe(is_open, door, 100, sizeof(char)));
        // setArrayValueSafe(is_open, door, 100, sizeof(char), &negation);
        setSafe(is_open, door, 100, negation);
        //is_open[door] = !is_open[door];
    }

  /* output the result */
  // for (door = 0; door < 100; ++door)
  //   printf("Door %d is %s\n", door+1, (*(char *) getArrayValueSafe(is_open, door, 100, sizeof(char))? "Open" : "Closed"));

}

int main()
{

  for (int i = 0; i < 1; i++) { //120000000
    main_function();
  }

  return 0;
}
