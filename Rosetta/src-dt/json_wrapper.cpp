#include "json.h"
#include "json_wrap.h"

#include "json.h"

extern "C" {

JSON* json_create_bool(bool b) {
    return new JSON(b);
}

JSON* json_create_number(int number) {
    return new JSON(number);
}

JSON* json_create_number32(uint32_t number){
    return new JSON(number);
}

JSON* json_create_char(char c){
    return new JSON(c);
}

JSON* json_create_short(short s){
    return new JSON(s);
}

JSON* json_create_size(size_t size){
    return new JSON(size);
}

JSON* json_create_string(const char* str) {
    return new JSON(str);
}

JSON* json_create_vector(JSON** array, int size) {
    return new JSON(array, size);
}

JSON* json_create_array(JSON** array){
    return new JSON(array);
}

void json_destroy(JSON* json) {
    delete json;
}
JSON* json_add_numbers(JSON* json1, JSON* json2) {
    return new JSON(*json1 + *json2);
}

JSON* json_sub_numbers(JSON* json1, JSON* json2){
    return new JSON (*json1 - *json2);
}

JSON* json_div_numbers(JSON* json1, JSON* json2){
    return new JSON (*json1 / *json2);
}

JSON* json_mul_numbers(JSON* json1, JSON* json2){
    return new JSON (*json1 * *json2);
}

JSON* json_and_numbers(JSON* json1, JSON* json2){
    return new JSON (*json1 & *json2);
}

JSON* json_or_numbers(JSON* json1, JSON* json2){
    return new JSON (*json1 | *json2);
}

JSON* json_right_shift(JSON* json1, JSON* json2){
    return new JSON (*json1 >> *json2);
}

JSON* json_left_shift(JSON* json1, JSON* json2){
    return new JSON (*json1 << *json2);
}

JSON* json_negate_number(JSON* json){
    return new JSON(!*json);
}

JSON* json_not_number(JSON* json){
    return new JSON(-*json);
}

JSON* json_tilde(JSON* json){
    return new JSON(~*json);
}

JSON* json_increment(JSON* json){
    JSON saved = *json;
    ++(*json);
    return new JSON(saved);
}

JSON* json_decrement(JSON* json){
    JSON saved = *json;
    --(*json);
    return new JSON(saved);
}

void json_assignment(JSON* dest, const JSON* src) {
    *dest = *src;
}

bool json_equals(const JSON* a, const JSON* b) {
    return (*a == *b);
}

bool json_unequals(const JSON* a, const JSON* b){
    return !(*a == *b);
}

bool json_lesser_than(const JSON* a, const JSON* b){
    return (*a < *b);
}

bool json_lesser_than_or_equal(const JSON* a, const JSON* b){
    return (*a < *b) || (*a == *b);
}

bool json_greater_than(const JSON* a, const JSON* b){
    return (*a > *b);
}

bool json_greater_than_or_equal(const JSON* a, const JSON* b){
    return (*a > *b) || (*a == *b);
}

void json_print(const JSON* json) {
    json->print(std::cout); // Print to standard output (console)
}

bool json_is_vector(const JSON* json) {
    return json->isVector();
}

// bool json_is_object(const JSON* json) {
//     return json->isObject();
// }

bool json_is_string(const JSON* json) {
    return json->isString();
}

bool json_is_number(const JSON* json) {
    return json->isNumber();
}

bool json_is_number32(const JSON* json){
    return json->isNumber32();
}

bool json_is_char(const JSON* json) {
    return json->isChar();
}

bool json_is_short(const JSON* json) {
    return json->isShort();
}

bool json_is_size(const JSON* json) {
    return json->isSize();
}

bool json_is_bool(const JSON* json) {
    return json->isBool();
}

bool json_is_null(const JSON* json) {
    return json->isNull();
}

const char* json_as_string(const JSON* json) {
    return json->asString().c_str();
}

JSON** json_as_vector(const JSON* json){
    return json->asVector();
}

int json_as_number(const JSON* json) {
    return json->asNumber();
}

uint32_t json_as_number32(const JSON* json){
    return json->asNumber32();
}

char json_as_char(const JSON* json){
    return json->asChar();
}

short json_as_short(const JSON* json){
    return json->asShort();
}

unsigned long json_as_size(const JSON* json){
    return json->asSize();
}

bool json_as_bool(const JSON* json) {
    return json->asBool();
}

JSON* json_array_get(JSON* json, int index){
    return (*json)[index];
}

int json_array_size(JSON* json){
    return json->vectorSize();
}

void json_array_set(JSON* json, int index, JSON* value){
    JSON * place = json_array_get(json, index);
    *place = *value;
    // json->setValue(index, value);
}

// void json_malloc_array(JSON* json, size_t size){
//     json->mallocArray(size);
// }

// void json_realloc_array(JSON* json, size_t size){
//     json->reallocArray(size);
// }

// void json_increment_pointer(JSON * json){
//     json->incrementPointer();
// }

} // extern "C"