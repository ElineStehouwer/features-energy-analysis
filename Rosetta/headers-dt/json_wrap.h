// JSON.h

#ifndef JSON_WRAP_H
#define JSON_WRAP_H

#include <functional>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <ostream>
#include <iostream>
#include <cstdint>

class JSON {
public:
    using StringT = std::string;
    using ArrayT = JSON** ;//std::vector<JSON>;
    // using ObjectT = std::map<Key, JSON>;
    using NumberT = int;
    using Number32T = uint32_t;
    using CharT = char;
    using ShortT = short;
    using SizeT = size_t;

    JSON();
    explicit JSON(bool b);
    JSON(NumberT number);
    JSON(Number32T number);
    JSON(const StringT& str);
    JSON(const char* str);
    JSON(const ArrayT array, int size);
    JSON(const ArrayT array);
    // JSON(ArrayT&& array, int size);
    // JSON(const ObjectT& object);
    // JSON(ObjectT&& object);
    JSON(CharT c);
    JSON(ShortT s);
    JSON(SizeT size_t);
    ~JSON();

    JSON(JSON&& other) noexcept;
    JSON(const JSON& other) noexcept;
    JSON operator+ (const JSON& other) const;
    JSON operator- (const JSON& other) const;
    JSON operator/ (const JSON& other) const;
    JSON operator* (const JSON& other) const;
    JSON operator& (const JSON& other) const;
    JSON operator| (const JSON& other) const;
    JSON operator>> (const JSON& other) const;
    JSON operator<< (const JSON& other) const;
    JSON& operator=(JSON&& other);
    JSON& operator=(const JSON& other);
    bool operator==(const JSON& other) const;
    bool operator< (const JSON& other) const;
    bool operator> (const JSON& other) const;
    JSON operator++ ();
    JSON operator--();
    JSON operator! ();
    JSON operator- ();
    JSON operator~ ();

    bool isVector() const;
    // bool isObject() const;
    bool isString() const;
    bool isNumber() const;
    bool isNumber32() const;
    bool isBool() const;
    bool isNull() const;
    bool isChar() const;
    bool isShort() const;
    bool isSize() const;

    const ArrayT asVector() const;
    ArrayT asVector();
    // const ObjectT& asObject() const;
    // ObjectT& asObject();
    const std::string& asString() const;
    std::string& asString();
    NumberT asNumber() const;
    Number32T asNumber32() const;
    bool asBool() const;
    CharT asChar() const;
    ShortT asShort() const;
    SizeT asSize() const;

    void print(std::ostream& out) const;

    // JSON& operator[](const std::string& lookup);
    JSON* operator[](int lookup);
    int vectorSize();
    void setValue(int index, JSON* value);
    // void mallocArray (size_t size);
    // void reallocArray(size_t size);
    void incrementPointer ();
    // void freeArray();
    // class iterator;
    // iterator begin();
    // iterator end();
    enum class Type {JSONNull, JSONBool, JSONString, JSONNumber, JSONNumber32, JSONArray, JSONChar, JSONShort, JSONSize};

private:
    Type type;
    union {
        bool b;
        StringT str;
        NumberT number;
        Number32T number32;
        ArrayT array;
        // ObjectT object;
        CharT c;
        ShortT s;
        SizeT size;
    };
    int array_size = -1;

    void clear();
};

// // Define JSON::iterator class
// class JSON::iterator {
//     friend class JSON;
//     ArrayT* contents;
//     size_t index;

//     iterator(ArrayT* contents, size_t index) : contents(contents), index(index) {}

// public:
//     bool operator==(const iterator& other) const {
//         return contents == other.contents && index == other.index;
//     }

//     bool operator!=(const iterator& other) const {
//         return !(*this == other);
//     }

//     JSON& operator*() const {
//         return (*contents)[index];
//     }

//     iterator& operator++() {
//         ++index;
//         return *this;
//     }
// };

#endif // JSON_H
