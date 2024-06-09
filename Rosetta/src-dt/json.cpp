/**
Copyright 2010-2015 Bernard van Gastel, bvgastel@bitpowder.com.
This file is standalone and not part of any release.

Bit Powder Libraries is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Bit Powder Libraries is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Bit Powder Libraries.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <functional>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <ostream>
#include <iostream>
#include <cstring>
#include "json_wrap.h"
#include <string.h>


class JSONException : public std::exception {
    const char* reason;
public:
    JSONException(const char* reason) : reason(reason) {
    }
    const char* what() const throw() override {
        return reason;
    }
};

void whatType(JSON::Type type) { 
    if (type == JSON::Type::JSONNull) {
        std::cout << "JSONNull" << std::endl;
    } else if (type == JSON::Type::JSONBool) {
        std::cout << "JSONBool" << std::endl;
    } else if (type == JSON::Type::JSONNumber) {
        std::cout << "JSONNumber" << std::endl;
    } else if (type == JSON::Type::JSONNumber32) {
        std::cout << "JSONNumber32" << std::endl;
    } else if (type == JSON::Type::JSONChar) {
        std::cout << "JSONChar" << std::endl;
    } else if (type == JSON::Type::JSONShort) {
        std::cout << "JSONShort" << std::endl;
    } else if (type == JSON::Type::JSONSize) {
        std::cout << "JSONSize" << std::endl;
    } else if (type == JSON::Type::JSONString) {
        std::cout << "JSONString" << std::endl;
    } else if (type == JSON::Type::JSONArray) {
        std::cout << "JSONArray" << std::endl;
    } else{
        std::cout<< "OTHER TYPE??" << std::endl;
    }
}


    JSON::JSON() : type(JSON::Type::JSONNull) {
    }
    JSON::JSON(bool b) : type(JSON::Type::JSONBool), b(b) {
    }
    JSON::JSON(NumberT number) : type(JSON::Type::JSONNumber), number(number) {
    }
    JSON::JSON(Number32T number32) : type(JSON::Type::JSONNumber32), number32(number32) {
    }
    JSON::JSON(CharT c) : type(JSON::Type::JSONChar), c(c) {
    }
    JSON::JSON(ShortT s) : type(JSON::Type::JSONShort), s(s) {
    }
    JSON::JSON(SizeT size) : type(JSON::Type::JSONSize), size(size) {
    }
    JSON::JSON(const StringT& str) : type(JSON::Type::JSONString), str(str) {
    }
    JSON::JSON(const char* str) : type(JSON::Type::JSONString), str(str) {
    }
    JSON::JSON(const ArrayT array, int size) : type(JSON::Type::JSONArray), array(array), array_size(size) {
    }
    JSON::JSON(const ArrayT array) : type(JSON::Type::JSONArray), array(array) {
    }
    // JSON::JSON(ArrayT&& array, int size) : type(JSON::Type::JSONArray), array(std::move(array)) {
    // }
    // JSON::JSON(const ObjectT& object) : type(JSON::Type::JSONObject), object(object) {
    // }
    // JSON::JSON(ObjectT&& object) : type(JSON::Type::JSONObject), object(std::move(object)) {
    // }
    JSON::~JSON() {
        clear();
    }

    // JSON::JSON(JSON&& b) noexcept;
    // JSON::JSON(const JSON& other) noexcept;
    // JSON& operator=(JSON &&b);
    // JSON& operator=(const JSON& b);
    // bool operator==(const JSON& b) const;

    bool JSON::isVector() const {
        return type == JSON::Type::JSONArray;
    }

    // bool JSON::isObject() const {
    //     return type == JSON::Type::JSONObject;
    // }

    bool JSON::isString() const {
        return type == JSON::Type::JSONString;
    }

    bool JSON::isNumber() const {
        return type == JSON::Type::JSONNumber;
    }

    bool JSON::isNumber32() const {
        return type == JSON::Type::JSONNumber32;
    }

    bool JSON::isChar() const {
        return type == JSON::Type::JSONChar;
    }

    bool JSON::isShort() const {
        return type == JSON::Type::JSONShort;
    }

    bool JSON::isSize() const {
        return type == JSON::Type::JSONSize;
    }

    bool JSON::isBool() const {
        return type == JSON::Type::JSONBool;
    }

    bool JSON::isNull() const {
        return type == JSON::Type::JSONNull;
    }

    const JSON::ArrayT JSON::asVector() const {
        if (!isVector()) {
            whatType(type);
            throw JSONException("not an array");
        }
        return array;
    }

    JSON::ArrayT JSON::asVector() {
        if (!isVector()) {
            whatType(type);
            throw JSONException("not an array");
        }
        return array;
    }

    // const JSON::ObjectT& JSON::asObject() const {
    //     if (!isObject())
    //         throw JSONException("not an object");
    //     return object;
    // }

    // JSON::ObjectT& JSON::asObject() {
    //     if (!isObject())
    //         throw JSONException("not an object");
    //     return object;
    // }

    const std::string& JSON::asString() const {
        if (!isString())
            throw JSONException("not a string");
        return str;
    }

    std::string& JSON::asString() {
        if (!isString())
            throw JSONException("not a string");
        return str;
    }

    JSON::NumberT JSON::asNumber() const {
        if (!isNumber()) {
            whatType(type);
            throw JSONException("not a number");
        }
        return number;
    }

    JSON::Number32T JSON::asNumber32() const {
        if (!isNumber32()) {
            whatType(type);    
            throw JSONException("not a number32");
        }
        return number32;
    }

    JSON::CharT JSON::asChar() const {
        if (!isChar())
            throw JSONException("not a byte");
        return c;
    }

    JSON::ShortT JSON::asShort() const {
        if (!isShort())
            throw JSONException("not a short");
        return s;
    }

    JSON::SizeT JSON::asSize() const {
        if (!isSize())
            throw JSONException("not a size");
        return size;
    }

    bool JSON::asBool() const {
        if (!isBool())
            throw JSONException("not a boolean");
        return b;
    }

    // JSON::operator JSON::ArrayT& () {
    //     return asVector();
    // }

    // JSON::operator ObjectT& () {
    //     return asObject();
    // }

    // operator std::JSON::string() {
    //     return asString();
    // }

    // explicit operator NumberT() {
    //     return asNumber();
    // }

    // explicit operator JSON::bool() {
    //     return asBool();
    // }

    // void JSO::print(std::ostream& out) const;

    // JSON& JSON::operator[](const std::string& lookup) {
    //     return asObject()[lookup];
    // }
    JSON* JSON::operator[](int lookup) {
        if (!isVector())
            {whatType(type); throw JSONException("not an array");}
        if (lookup < 0 || lookup >= array_size) {
            std::string st = "index out of bounds on get operation: ";
            st += std::to_string(lookup);
            st += " >= ";
            st += std::to_string(array_size);
            const int length = st.length();
            char* char_array = new char[length + 1]; 
            strcpy(char_array, st.c_str());
            throw JSONException(char_array);
        }
        return array[lookup];
    }

    int JSON::vectorSize() {
        if (!isVector()) 
            {whatType(type); throw JSONException("not an array");}
        return array_size;
    }

    void JSON::setValue(int index, JSON* value){
        // std::cout << "SET VALUE" << std::endl;
        if (!isVector())
            {whatType(type); throw JSONException("not an array");}
        if (index < 0 || index >= array_size) {
            std::string st = "index out of bounds: ";
            st += std::to_string(index);
            st += " >= ";
            st += std::to_string(array_size);
            const int length = st.length();
            char* char_array = new char[length + 1]; 
            strcpy(char_array, st.c_str());
            throw JSONException(char_array);
        }
        array[index] = value;
    }

    // void JSON::mallocArray(size_t size){
    //     if (!isVector())
    //         throw JSONException("not an array");
    //     //JSON* jj = (JSON *) malloc (size*sizeof(JSON *));
    //     array = (JSON **) malloc(size * sizeof(JSON *)); 
    //     array_size = size;
    // }
    // void JSON::reallocArray(size_t size){
    //     if (!isVector())
    //         throw JSONException("not an array");
    //     array = (JSON **) realloc(*array, size*sizeof(JSON *));
    //     array_size = size; 
    // }
    // void JSON::incrementPointer(){
    //     if (!isVector())
    //         throw JSONException("not a pointer");
    //     array++;
    //     array_size = array_size -1;
    // }
    // void JSON::freeArray(){
    //     if (!isVector())
    //         throw JSONException("not an array");
    //     free(*array);
    // }
    // class iterator {
    //     friend class JSON;
    //     JSON::ArrayT* contents;
    //     unsigned long index;
    //     iterator(JSON::ArrayT* contents, unsigned long index) : contents(contents), index(index) {
    //     }
    //   public:
    //     bool operator==(const iterator& it) const {
    //         return contents == it.contents && index == it.index;
    //     }
    //     bool operator!=(const iterator& it) const {
    //         return !(*this == it);
    //     }
    //     JSON& operator*() const {
    //         return (*contents)[index];
    //     }
    //     iterator& operator++() {
    //         index++;
    //         return *this;
    //     }
    // };
    // iterator begin();
    // iterator end();

template <class T>
inline void destroy(T* object) {
    object->~T();
}

void JSON::clear() {
    if (type == JSON::Type::JSONString)
        destroy(&str);
    else if (type == JSON::Type::JSONArray) {
        // destroy(&array);
        array_size = -1;
    } 
    // else if (type == JSON::Type::JSONObject)
    //     destroy(&object);
    type = JSON::Type::JSONNull;
}

JSON JSON::operator+(const JSON& other) const {
    if (isNumber() && other.isNumber()) {
        return JSON(number + other.number);
    } else if (isChar() && other.isChar()) {
        return JSON(c + other.c);
    } else if (isShort() && other.isShort()){ 
        return JSON(s + other.s);
    } else if (isSize() && other.isSize()) { 
        return JSON(size + other.size);
    } else if (isNumber32() && other.isNumber32()) {
        return JSON(number32 + other.number32);
    } else if ((isNumber() && other.isShort()) ) {
        return JSON(number + other.s);
    } else if(isShort() && other.isNumber()) {
        return JSON(s + other.number);
    } else if (isNumber32() && other.isShort()) {
        return JSON(number32 + other.s);
    } else if (isShort() && other.isNumber32()) {
        return JSON(s + other.number32);
    } else if (isNumber32() && other.isNumber()) {
        return JSON(number32 + other.number);
    } else if (isNumber() && other.isNumber32()) {
        return JSON(number + other.number32);
    } else if (isVector() && other.isNumber()) {
        return JSON(array+other.number, array_size-other.number);
    } else {
        whatType(type);
        whatType(other.type);
        throw JSONException("Cannot perform addition on non-number types");
    }
}

JSON JSON::operator- (const JSON& other) const {
    // std::cout << "SUB" << std::endl;
    if (isNumber() && other.isNumber()) {
        return JSON(number - other.number);
    } else if (isChar() && other.isChar()) {
        return JSON(c - other.c);
    } else if (isShort() && other.isShort()){ 
        return JSON(s - other.s);
    } else if (isSize() && other.isSize()) { 
        return JSON(size - other.size);
    } else if (isNumber32() && other.isNumber32()) {
        return JSON(number32 - other.number32);
    } else if (isNumber() && other.isShort()) {
        return JSON(number - other.s);
    } else if(isShort() && other.isNumber()) {
        return JSON(s - other.number);
    } else if (isNumber32() && other.isShort()) {
        return JSON(number32 - other.s);
    } else if (isShort() && other.isNumber32()) {
        return JSON(s - other.number32);
    } else if (isNumber32() && other.isNumber()) {
        return JSON(number32 - other.number);
    } else if (isNumber() && other.isNumber32()) {
        return JSON(number - other.number32);
    } else if (isNumber32() && other.isSize()){
        return JSON(number32 - other.size);
    } else if (isSize() && other.isNumber32()) {
        return JSON(size - other.number32);
    } else if (isNumber() && other.isSize()){
        return JSON(number - other.size);
    } else if (isSize() && other.isNumber()) {
        return JSON(size - other.number);
    } else {
        throw JSONException("Cannot perform substraction on non-number types");
    }
}

JSON JSON::operator/ (const JSON& other) const{
    if (isNumber() && other.isNumber()) {
        return JSON(number / other.number);
    } else if (isShort() && other.isShort()){ 
        return JSON(s / other.s);
    } else if (isSize() && other.isSize()) { 
        return JSON(size / other.size);
    } else if (isNumber32() && other.isNumber32()) {
        return JSON(number32 / other.number32);
    } else if (isNumber() && other.isShort()) {
        return JSON(number / other.s);
    } else if(isShort() && other.isNumber()) {
        return JSON(s / other.number);
    } else if (isNumber32() && other.isShort()) {
        return JSON(number32 / other.s);
    } else if (isShort() && other.isNumber32()) {
        return JSON(s / other.number32);
    } else if (isNumber32() && other.isNumber()) {
        return JSON(number32 / other.number);
    } else if (isNumber() && other.isNumber32()) {
        return JSON(number / other.number32);
    } else {
        throw JSONException("Cannot perform division on non-number types");
    }
}

JSON JSON::operator* (const JSON& other) const{
    if (isNumber() && other.isNumber()) {
        return JSON(number * other.number);
    } else if (isShort() && other.isShort()){ 
        return JSON(s * other.s);
    } else if (isSize() && other.isSize()) { 
        return JSON(size * other.size);
    } else if (isNumber() && other.isShort()) {
        return JSON(number * other.s);
    } else if (isNumber32() && other.isNumber32()) {
        return JSON(number32 * other.number32);
    }else if(isShort() && other.isNumber()) {
        return JSON(s * other.number);
    } else if (isSize() && other.isNumber()) {
        return JSON(size * other.number);
    } else if (isNumber() * other.isSize()) {
        return JSON(number * other.size);
    } else if (isNumber32() && other.isShort()) {
        return JSON(number32 * other.s);
    } else if (isShort() && other.isNumber32()) {
        return JSON(s * other.number32);
    } else if (isNumber32() && other.isNumber()) {
        return JSON(number32 * other.number);
    } else if (isNumber() && other.isNumber32()) {
        return JSON(number * other.number32);
    } else if (isSize() && other.isNumber32()) {
        return JSON(size * other.number32);
    } else if (isNumber32() * other.isSize()) {
        return JSON(number32 * other.size);
    } else {
        throw JSONException("Cannot perform multiplication on non-number types");
    }
}   

JSON JSON::operator& (const JSON& other) const{
    // std::cout << "AND" << std::endl;
    if (isNumber() && other.isNumber()) {
        return JSON(number & other.number);
    } else if (isShort() && other.isShort()){ 
        return JSON(s & other.s);
    } else if (isSize() && other.isSize()) { 
        return JSON(size & other.size);
    } else if (isNumber32() && other.isNumber32()) {
        return JSON(number32 & other.number32);
    } else if (isNumber() && other.isShort()) {
        return JSON(number & other.s);
    } else if(isShort() && other.isNumber()) {
        return JSON(s & other.number);
    } else if (isNumber32() && other.isShort()) {
        return JSON(number32 & other.s);
    } else if (isShort() && other.isNumber32()) {
        return JSON(s & other.number32);
    } else if (isNumber32() && other.isNumber()) {
        return JSON(number32 & other.number);
    } else if (isNumber() && other.isNumber32()) {
        return JSON(number & other.number32);
    } else {
        whatType(type);
        whatType(other.type);
        throw JSONException("Cannot perform logical and on non-number types");
    }
}

JSON JSON::operator| (const JSON& other) const{
    if (isNumber() && other.isNumber()) {
        return JSON(number | other.number);
    } else if (isShort() && other.isShort()){ 
        return JSON(s | other.s);
    } else if (isSize() && other.isSize()) { 
        return JSON(size | other.size);
    } else if (isNumber32() && other.isNumber32()) {
        return JSON(number32 | other.number32);
    } else if (isNumber() && other.isShort()) {
        return JSON(number | other.s);
    } else if(isShort() && other.isNumber()) {
        return JSON(s | other.number);
    } else if (isNumber32() && other.isShort()) {
        return JSON(number32 | other.s);
    } else if (isShort() && other.isNumber32()) {
        return JSON(s | other.number32);
    } else if (isNumber32() && other.isNumber()) {
        return JSON(number32 | other.number);
    } else if (isNumber() && other.isNumber32()) {
        return JSON(number | other.number32);
    } else {
        throw JSONException("Cannot perform logical or on non-number types");
    }
}

JSON JSON::operator>> (const JSON& other) const {
    if (isNumber() && other.isNumber()) {
        return JSON(number >> other.number);
    } else if (isShort() && other.isShort()){ 
        return JSON(s >> other.s);  
    } else if (isSize() && other.isSize()) { 
        return JSON(size >> other.size);
    } else if (isNumber32() && other.isNumber32()) {
        return JSON(number32 >> other.number32);
    } else if (isNumber() && other.isShort()) {
        return JSON(number >> other.s);
    } else if(isShort() && other.isNumber()) {
        return JSON(s >> other.number);
    } else if (isNumber32() && other.isShort()) {
        return JSON(number32 >> other.s);
    } else if (isShort() && other.isNumber32()) {
        return JSON(s >> other.number32);
    } else if (isNumber32() && other.isNumber()) {
        return JSON(number32 >> other.number);
    } else if (isNumber() && other.isNumber32()) {
        return JSON(number >> other.number32);
    } else if (isNumber32() && other.isSize()) {
        return JSON(number32 >> other.size);
    } else if (isSize() && other.isNumber32()) {
        return JSON(size >> other.number32);
    } else {
        throw JSONException("Cannot perform rightshift on non-number types");
    }
}

JSON JSON::operator<< (const JSON& other) const {
    if (isNumber() && other.isNumber()) {
        return JSON(number << other.number);
    } else if (isShort() && other.isShort()){ 
        return JSON(s << other.s);  
    } else if (isSize() && other.isSize()) { 
        return JSON(size << other.size);
    } else if (isNumber32() && other.isNumber32()) {
        return JSON(number32 << other.number32);
    } else if (isNumber() && other.isShort()) {
        return JSON(number << other.s);
    } else if(isShort() && other.isNumber()) {
        return JSON(s << other.number);
    } else if (isNumber32() && other.isShort()) {
        return JSON(number32 << other.s);
    } else if (isShort() && other.isNumber32()) {
        return JSON(s << other.number32);
    } else if (isNumber32() && other.isNumber()) {
        return JSON(number32 << other.number);
    } else if (isNumber() && other.isNumber32()) {
        return JSON(number << other.number32);
    } else if (isNumber32() && other.isSize()) {
        return JSON(number32 << other.size);
    } else if (isSize() && other.isNumber32()) {
        return JSON(size << other.number32);
    } else if (isNumber() && other.isSize()) {
        return JSON(number << other.size);
    } else if (isSize() && other.isNumber()) {
        return JSON(size << other.number);
    } else {
        throw JSONException("Cannot perform rightshift on non-number types");
    }
}

JSON JSON::operator! () {
    if (type == JSON::Type::JSONBool) {
        return JSON(!b);
    } else if (type == JSON::Type::JSONNumber) {
        return JSON(!number);
    } else if (type == JSON::Type::JSONShort) {
        return JSON(!s);
    } else if (type == JSON::Type::JSONSize) {
        return JSON(!size);
    } else if (type == JSON::Type::JSONChar) {
        return JSON(!c);
    } else if (type == JSON::Type::JSONNumber32) {
        return JSON(!number32);
    } else {
        throw JSONException("Cannot perform logical not on non-boolean, char or number types");
    }
}

JSON JSON::operator- () {
    if (type == JSON::Type::JSONNumber) {
        return JSON(-number);
    } else if (type == JSON::Type::JSONShort) {
        return JSON(-s);
    } else if (type == JSON::Type::JSONSize) {
        return JSON(-size);
    } else if (type == JSON::Type::JSONNumber32) {
        return JSON(-number32);
    } else {
        throw JSONException("Cannot perform negation on non-number types");
    }
}

JSON JSON::operator~ () {
    if (type == JSON::Type::JSONNumber) {
        return JSON(~number);
    } else if (type == JSON::Type::JSONShort) {
        return JSON(~s);
    } else if (type == JSON::Type::JSONSize) {
        return JSON(~size);
    } else if (type == JSON::Type::JSONNumber32) {
        return JSON(~number32);
    } else {
        throw JSONException("Cannot perform tilde on non-number types");
    }
}


JSON JSON::operator++ ()  {
    if (type == JSON::Type::JSONNumber) {
        number = (number + 1);
    } else if (type == JSON::Type::JSONShort){
        s = s + 1;
    } else if (type == JSON::Type::JSONSize) { 
        size = size + 1;
    } else if (type == JSON::Type::JSONNumber32) {
        number32 = number32 + 1;
    } else if(type == JSON::Type::JSONArray) {
        array++;
        array_size = array_size -1;
    } else {
        throw JSONException("Cannot perform addition on non-number types");
    }
    return *this;
}

JSON JSON::operator--(){
    if (type == JSON::Type::JSONNumber) {
        number = (number - 1);
    } else if (type == JSON::Type::JSONShort){
        s = s - 1;
    } else if (type == JSON::Type::JSONSize) { 
        size = size - 1;
    } else if (type == JSON::Type::JSONNumber32) {
        number32 = number32 - 1;
    } else if(type == JSON::Type::JSONArray) {
        array--;
        array_size = array_size + 1;
    } else {
        throw JSONException("Cannot perform addition on non-number types");
    }
    return *this;
}

JSON& JSON::operator=(const JSON& other) {
    if (this == &other)
        return *this;
    clear();
    type = other.type;
    if (type == JSON::Type::JSONBool)
        b = other.b;
    else if (type == JSON::Type::JSONString)
        new (&str) StringT(other.str);
    else if (type == JSON::Type::JSONNumber)
        number = other.number;
    else if (type == JSON::Type::JSONNumber32)
        number32 = other.number32;
    else if (type == JSON::Type::JSONChar)
        c = other.c;
    else if (type == JSON::Type::JSONShort)
        s = other.s;
    else if (type == JSON::Type::JSONSize)
        size = other.size;
    else if (type == JSON::Type::JSONArray){
        array = other.array;
        array_size = other.array_size;   
        // new (&array) ArrayT(other.array);
    }
    // else if (type == JSON::Type::JSONObject)
    //     new (&object) ObjectT(other.object);
    return *this;
}

bool JSON::operator==(const JSON& other) const {
    if (type == other.type) {
        if (type == JSON::Type::JSONNull)
            return true;
        if (type == JSON::Type::JSONBool)
            return b == other.b;
        if (type == JSON::Type::JSONString)
            return str == other.str;
        if (type == JSON::Type::JSONNumber)
            return number == other.number;
        if (type == JSON::Type::JSONNumber32)
            return number32 == other.number32;
        if (type == JSON::Type::JSONChar)
            return c == other.c;
        if (type == JSON::Type::JSONShort)
            return s == other.s;
        if (type == JSON::Type::JSONSize)
            return size == other.size;
        if (type == JSON::Type::JSONArray) //Right now this only checks if the pointer points to the same address
            return array == other.array && array_size == other.array_size;
        // if (type == JSON::Type::JSONObject)
        //     return object == other.object;
    } else if (type == JSON::Type::JSONNumber && other.type == JSON::Type::JSONShort) {
        return number == other.s;
    } else if (type == JSON::Type::JSONShort && other.type == JSON::Type::JSONNumber) {
        return s == other.number;
    } else if (type == JSON::Type::JSONNumber && other.type == JSON::Type::JSONSize) {
        return number == other.size;
    } else if (type == JSON::Type::JSONSize && other.type == JSON::Type::JSONNumber) {
        return size == other.number;
    } else if (type == JSON::Type::JSONSize && other.type == JSON::Type::JSONShort) {
        return size == other.s;
    } else if (type == JSON::Type::JSONShort && other.type == JSON::Type::JSONSize) {
        return s == other.size;
    } else if (type == JSON::Type::JSONNumber32 && other.type == JSON::Type::JSONShort) {
        return number32 == other.s;
    } else if (type == JSON::Type::JSONShort && other.type == JSON::Type::JSONNumber32) {
        return s == other.number32;
    } else if (type == JSON::Type::JSONNumber32 && other.type == JSON::Type::JSONSize) {
        return number32 == other.size;
    } else if (type == JSON::Type::JSONSize && other.type == JSON::Type::JSONNumber32) {
        return size == other.number32;
    } else if (type == JSON::Type::JSONNumber && other.type == JSON::Type::JSONNumber32) {
        return number == other.number32;
    } else if (type == JSON::Type::JSONNumber32 && other.type == JSON::Type::JSONNumber) {
        return number32 == other.number;
    }
    return false;
}

bool JSON::operator< (const JSON& other) const {
    if (type == other.type) {
        if (type == JSON::Type::JSONNull)
            return false;
        if (type == JSON::Type::JSONBool)
            return b < other.b;
        if (type == JSON::Type::JSONString)
            return str < other.str;
        if (type == JSON::Type::JSONNumber)
            return number < other.number;
        if (type == JSON::Type::JSONNumber32)
            return number32 < other.number32;
        if (type == JSON::Type::JSONChar)
            return c < other.c;
        if (type == JSON::Type::JSONShort)
            return s < other.s;
        if (type == JSON::Type::JSONSize)
            return size < other.size;
        if (type == JSON::Type::JSONArray) //Right now this only checks if the pointer points to the same address
            return array_size < other.array_size;
    } else if (type == JSON::Type::JSONNumber && other.type == JSON::Type::JSONShort) {
        return number < other.s;
    } else if (type == JSON::Type::JSONShort && other.type == JSON::Type::JSONNumber) {
        return s < other.number;
    } else if (type == JSON::Type::JSONNumber && other.type == JSON::Type::JSONSize) {
        return number < other.size;
    } else if (type == JSON::Type::JSONSize && other.type == JSON::Type::JSONNumber) {
        return size < other.number;
    } else if (type == JSON::Type::JSONSize && other.type == JSON::Type::JSONShort) {
        return size < other.s;
    } else if (type == JSON::Type::JSONShort && other.type == JSON::Type::JSONSize) {
        return s < other.size;
    } else if (type == JSON::Type::JSONNumber32 && other.type == JSON::Type::JSONShort) {
        return number32 < other.s;
    } else if (type == JSON::Type::JSONShort && other.type == JSON::Type::JSONNumber32) {
        return s < other.number32;
    } else if (type == JSON::Type::JSONNumber32 && other.type == JSON::Type::JSONSize) {
        return number32 < other.size;
    } else if (type == JSON::Type::JSONSize && other.type == JSON::Type::JSONNumber32) {
        return size < other.number32;
    } else if (type == JSON::Type::JSONNumber && other.type == JSON::Type::JSONNumber32) {
        return number < other.number32;
    } else if (type == JSON::Type::JSONNumber32 && other.type == JSON::Type::JSONNumber) {
        return number32 < other.number;
    }
    return false;
}

bool JSON::operator> (const JSON& other) const{
    if (type == other.type) {
        if (type == JSON::Type::JSONNull)
            return false;
        if (type == JSON::Type::JSONBool)
            return b > other.b;
        if (type == JSON::Type::JSONString)
            return str > other.str;
        if (type == JSON::Type::JSONNumber)
            return number > other.number;
        if (type == JSON::Type::JSONNumber32)
            return number32 > other.number32;
        if (type == JSON::Type::JSONChar)
            return c > other.c;
        if (type == JSON::Type::JSONShort)
            return s > other.s;
        if (type == JSON::Type::JSONSize)
            return size > other.size;
        if (type == JSON::Type::JSONArray) //Right now this only checks if the pointer points to the same address
            return array_size > other.array_size;
    } else if (type == JSON::Type::JSONNumber && other.type == JSON::Type::JSONShort) {
        return number > other.s;
    } else if (type == JSON::Type::JSONShort && other.type == JSON::Type::JSONNumber) {
        return s > other.number;
    } else if (type == JSON::Type::JSONNumber && other.type == JSON::Type::JSONSize) {
        return number > other.size;
    } else if (type == JSON::Type::JSONSize && other.type == JSON::Type::JSONNumber) {
        return size > other.number;
    } else if (type == JSON::Type::JSONSize && other.type == JSON::Type::JSONShort) {
        return size > other.s;
    } else if (type == JSON::Type::JSONShort && other.type == JSON::Type::JSONSize) {
        return s > other.size;
    } else if (type == JSON::Type::JSONNumber32 && other.type == JSON::Type::JSONShort) {
        return number32 > other.s;
    } else if (type == JSON::Type::JSONShort && other.type == JSON::Type::JSONNumber32) {
        return s > other.number32;
    } else if (type == JSON::Type::JSONNumber32 && other.type == JSON::Type::JSONSize) {
        return number32 > other.size;
    } else if (type == JSON::Type::JSONSize && other.type == JSON::Type::JSONNumber32) {
        return size > other.number32;
    } else if (type == JSON::Type::JSONNumber && other.type == JSON::Type::JSONNumber32) {
        return number > other.number32;
    } else if (type == JSON::Type::JSONNumber32 && other.type == JSON::Type::JSONNumber) {
        return number32 > other.number;
    }
    return false;
}


JSON& JSON::operator=(JSON &&other) {
    clear();
    type = other.type;
    if (type == JSON::Type::JSONBool)
        b = other.b;
    else if (type == JSON::Type::JSONString)
        new (&str) StringT(std::move(other.str));
    else if (type == JSON::Type::JSONNumber)
        number = other.number;
    else if (type == JSON::Type::JSONArray){
        array = other.array;
        array_size = other.array_size;
    }    
        // new (&array) ArrayT(std::move(other.array));
    // else if (type == JSON::Type::JSONObject)
    //     new (&object) ObjectT(std::move(other.object));
    return *this;
}

JSON::JSON(const JSON& other) noexcept :
type(other.type) {
    if (type == JSON::Type::JSONBool)
        b = other.b;
    else if (type == JSON::Type::JSONString)
        new (&str) StringT(other.str);
    else if (type == JSON::Type::JSONNumber)
        number = other.number;
    else if (type == JSON::Type::JSONNumber32)
        number32 = other.number32;
    else if (type == JSON::Type::JSONChar)
        c = other.c;
    else if (type == JSON::Type::JSONShort)
        s = other.s;
    else if (type == JSON::Type::JSONSize)
        size = other.size;
    else if (type == JSON::Type::JSONArray){
        array = other.array;
        array_size = other.array_size;
        //new (&array) ArrayT(other.array);
    }
    // else if (type == JSON::Type::JSONObject)
    //     new (&object) ObjectT(other.object);
}

JSON::JSON(JSON &&other) noexcept :
type(other.type) {
    if (type == JSON::Type::JSONBool)
        b = other.b;
    else if (type == JSON::Type::JSONString)
        new (&str) StringT(std::move(other.str));
    else if (type == JSON::Type::JSONNumber)
        number = other.number;
    else if (type == JSON::Type::JSONNumber32)
        number32 = other.number32;
    else if (type == JSON::Type::JSONChar)
        c = other.c;
    else if (type == JSON::Type::JSONShort)
        s = other.s;
    else if (type == JSON::Type::JSONSize)
        size = other.size;
    else if (type == JSON::Type::JSONArray){
        array = other.array;
        array_size = other.array_size;
        // new (&array) ArrayT(std::move(other.array));
    }
    // else if (type == JSON::Type::JSONObject)
    //     new (&object) ObjectT(std::move(other.object));
}

void JSON::print(std::ostream& out) const {
    if (type == JSON::Type::JSONNull)
        out << "null";
    if (type == JSON::Type::JSONBool)
        out << (b ? "true" : "false");
    if (type == JSON::Type::JSONNumber)
        out << number;
    if (type == JSON::Type::JSONNumber32)
        out << number32;
    if (type == JSON::Type::JSONChar)
        out << c;
    if (type == JSON::Type::JSONShort)
        out << s;
    if (type == JSON::Type::JSONSize)
        out << size;
    if (type == JSON::Type::JSONString)
        out << '"' << str << '"';
    if (type == JSON::Type::JSONArray) {
        out << "[";
        (*array[0]).print(out);
        for (size_t i = 1; i < array_size; i++) {
            out << ",";
            (*array[i]).print(out);
        }
        // bool first = true;
        // for (auto& it : array) {
        //     if (!first)
        //         out << ",";
        //     it.print(out);
        //     first = false;
        // }
        out << "]";
    }
    // if (type == JSON::Type::JSONObject) {
    //     out << "{";
    //     bool first = true;
    //     for (auto& it : object) {
    //         if (!first)
    //             out << ",";
    //         out << "\"" << it.first << "\":";
    //         it.second.print(out);
    //         first = false;
    //     }
    //     out << "}";
    // }
    // out << "\n";
}

// JSON::iterator begin() {
//     return {isVector() ? &array : nullptr, 0};
// }

// JSON::iterator JSON::end() {
//     return isVector() ? iterator(&array, array.size()) : iterator(nullptr, 0);
// }

namespace std {
inline std::ostream& operator<< (std::ostream& out, const JSON& json) {
    json.print(out);
    return out;
}
}

// #include <gtest/gtest.h>

// namespace tests {

// TEST(Parser, JSONGenerateString) {
//     JSON expectedObject = JSON::ObjectT{{"aNumber",1.0},{"bNumber",2.0}};

//     expectedObject["noNumber"] = "-";

//     expectedObject["foo2"] = JSON::ArrayT{"foo","bar"};

//     JSON expectedVector = JSON::Array();
//     expectedVector.asVector().push_back("bar");
//     expectedObject["foo"] = expectedVector;

//     std::stringstream ss;
//     ss << expectedObject;
//     EXPECT_EQ("{\"aNumber\":1,\"bNumber\":2,\"foo\":[\"bar\"],\"foo2\":[\"foo\",\"bar\"],\"noNumber\":\"-\"}", ss.str());
// }

// }
