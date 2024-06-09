#ifndef JSON_H
#define JSON_H
#include <stdbool.h>  // Include to define 'bool' and 'true/false'
#include <stdio.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef struct JSON JSON;
// Function prototypes for JSON management
JSON* json_create_bool(bool b);
JSON* json_create_number(int number);
JSON* json_create_number32(uint32_t number);
JSON* json_create_char(char c);
JSON* json_create_short(short s);
JSON* json_create_size(size_t size);
JSON* json_create_string(const char* str);
JSON* json_create_vector(JSON** array, int size);
JSON* json_create_array(JSON** array);

void json_destroy(JSON* json);
JSON* json_add_numbers(JSON* json1, JSON* json2);
JSON* json_sub_numbers(JSON* json1, JSON* json2);
JSON* json_div_numbers(JSON* json1, JSON* json2);
JSON* json_mul_numbers(JSON* json1, JSON* json2);
JSON* json_and_numbers(JSON* json1, JSON* json2);
JSON* json_or_numbers(JSON* json1, JSON* json2);
JSON* json_right_shift(JSON* json1, JSON* json2);
JSON* json_left_shift(JSON* json1, JSON* json2);
JSON* json_not_number(JSON* json);
JSON* json_negate_number(JSON* json);
JSON* json_tilde(JSON* json);
JSON* json_increment(JSON* json);
JSON* json_decrement(JSON* json);
void json_assignment(JSON* dest, const JSON* src);
bool json_equals(const JSON* a, const JSON* b);
bool json_unequals(const JSON* a, const JSON* b);
bool json_lesser_than(const JSON* a, const JSON* b);
bool json_lesser_than_or_equal(const JSON* a, const JSON* b);
bool json_greater_than(const JSON* a, const JSON* b);
bool json_greater_than_or_equal(const JSON* a, const JSON* b);
void json_print(const JSON* json);


// JSON type query functions
bool json_is_vector(const JSON* json);
// bool json_is_object(const JSON* json);
bool json_is_string(const JSON* json);
bool json_is_number(const JSON* json);
bool json_is_number32(const JSON* json);
bool json_is_char(const JSON* json);
bool json_is_short(const JSON* json);
bool json_is_bool(const JSON* json);
bool json_is_null(const JSON* json);
bool json_is_size(const JSON* json);

// Conversion functions
const char* json_as_string(const JSON* json);
JSON** json_as_vector(const JSON* json);
int json_as_number(const JSON* json);
uint32_t json_as_number32(const JSON* json);
char json_as_char(const JSON* json);
short json_as_short(const JSON* json);
unsigned long json_as_size(const JSON* json);
bool json_as_bool(const JSON* json);

// Array functions
JSON* json_array_get(JSON* json, int index);
int json_array_size(JSON* json);
void json_array_set(JSON* json, int index, JSON* value);
// void json_malloc_array(JSON* json, size_t size);
// void json_realloc_array(JSON* json, size_t size);
// void json_increment_pointer(JSON * json);
// Object functions
// JSON* json_object_get(const JSON* json, const char* key);

#ifdef __cplusplus
}
#endif

#endif
