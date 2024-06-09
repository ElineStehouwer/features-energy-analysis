#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "json.h"

JSON *bin(JSON * x);

void main_function() {
    //for (size_t i = 0; i < 256; i++) {
    for (JSON* i = json_create_size(0); json_lesser_than(i, json_create_size(256)); json_increment(i)) {
        JSON *casted_i = json_create_number32(json_as_size(i));
        JSON *binstr = bin(casted_i);
        // size_t j = 0;
        // while (json_unequals(json_array_get(binstr, j), json_create_char('\0'))) {
        //     json_print(json_array_get(binstr, j));
        //     // printf("%c", binstr[j]);
        //     // json_increment(j);
        //     j++;
        // }
        for (JSON * i = json_create_size(0); json_lesser_than(i, json_create_size(json_array_size(binstr))); json_increment(i)) {
            free(json_array_get(binstr, json_as_size(i)));
        }
        free(binstr);
        // printf("\n");
        // printf("%s\n", binstr);
    }
}

int main(void)
{
    for (int  i = 0; i < 1; i++) { //7500
        main_function();
    }
}



JSON *bin(JSON * x)
{
    // size_t bits = (x == 0) ? 1 : log10((double) x)/log10((double)2) + 1;
    JSON *bits = json_create_size(json_equals(x, json_create_number32(0))? 1 : log10((double) json_as_number32(x))/log10(2) + 1);
    // char *ret = malloc((bits + 1) * sizeof (char));
    JSON *size_array = json_create_size(json_as_size(bits) + 1);
    // json_assignment(size_array, json_add_numbers(bits, json_create_size(1)));
    JSON **array = (JSON **)malloc(json_as_size(size_array) * sizeof(JSON *));
    for (JSON *i = json_create_size(0); json_lesser_than (i, size_array); json_increment(i)) {
        array[json_as_size(i)] = json_create_char('0');
    }
    JSON *ret = json_create_vector(array, json_as_size(size_array));
    // for (size_t i = 0; i < bits ; i++) {
    for (JSON* i = json_create_size(0); json_lesser_than(i, bits); json_increment(i)) {
       //ret[bits - i - 1] = (x & 1) ? '1' : '0';
        // ret[json_as_size( json_sub_numbers(json_sub_numbers(bits, i), json_create_size(1)))] = new_value;
            json_array_set(ret, json_as_size( json_sub_numbers(json_sub_numbers(bits, i), json_create_size(1))), json_as_number32(json_and_numbers(x, json_create_number32(1)))? json_create_char('1') : json_create_char('0'));
        //x >>= 1;
        json_assignment(x, json_right_shift(x, json_create_number32(1)));
    }
    // ret[json_as_size(bits)] = json_create_char('\0');
        json_array_set(ret, json_as_size(bits), json_create_char('\0'));
    // ret[bits] = '\0';
    return ret;
}
