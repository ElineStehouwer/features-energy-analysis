#include <stdio.h>
#include "json.h"

void sieve(JSON *, JSON *);

void main_function() {
    // int n=10000;
    JSON* n = json_create_number(10001);
    JSON* array [10001];
    for (JSON *i = json_create_number(0); json_lesser_than(i, n); json_increment(i)) {
        array[json_as_number(i)] = json_create_number(0);
    }
    JSON* dyn_array = json_create_vector(array, json_as_number(n));
    sieve(dyn_array,n);
    for (JSON * i = json_create_size(0); json_lesser_than(i, json_create_size(json_array_size(dyn_array))); json_increment(i)) {
            free(json_array_get(dyn_array, json_as_size(i)));
    }
    free(n);
    free(dyn_array);
}

int main(int argc, char **argv)
{
    for (int i =0; i< 1; i++) { //3000
        main_function();
    }
    return 0;
}

void sieve(JSON *a, JSON * n)
{
    // int i=0, j=0;
    // printf("Sieve of Eratosthenes\n");
    JSON* i = json_create_number(0);
    JSON* j = json_create_number(0);

    // for(i=2; i<n; i++) {
    for(json_assignment(i, json_create_number(2)); json_lesser_than(i, n); json_increment(i)) {
        // a[i] = 1;
        json_array_set(a, json_as_number(i), json_create_number(1));
    }

    // for(i=2; i<n; i++) {
    for(json_assignment(i, json_create_number(2)); json_lesser_than(i, n); json_increment(i)) {
        // if(a[i] == 1) {
        if(json_equals(json_array_get(a, json_as_number(i)), json_create_number(1))){
            // for(j=i; (i*j)<n; j++) {
            for(json_assignment(j, i); json_lesser_than(json_mul_numbers(i,j), n); json_increment(j)) {
                // a[(i*j)] = 0;
                json_array_set(a, json_as_number(json_mul_numbers(i,j)), json_create_number(0));
            }
        }
    }
    // printf("Sieve of Eratosthenes\n");


    // for(i=2; i<n; i++) {
    // for(json_assignment(i, json_create_number(2)); json_lesser_than(i, n); json_increment(i)) {
    //     if(json_equals(json_array_get(a, json_as_number(i)), json_create_number(1))){
    //         // printf("%d ", i);
    //         json_print(i);
    //         printf(" ");
    //     }
    // }
    // printf("\n");
}
