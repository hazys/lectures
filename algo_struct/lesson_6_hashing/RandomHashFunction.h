//
// Created by user on 18.12.2021.
//

#ifndef LESSON_6_HASHING_RANDOMHASHFUNCTION_H
#define LESSON_6_HASHING_RANDOMHASHFUNCTION_H

#include "string"

using namespace std;

class RandomHashFunction {
private:
    unsigned a, b, max_value;
public:
    RandomHashFunction(int max_value);
    ~RandomHashFunction();

    int hash(int x);
};


class RandomHashFunctionString {
private:
    unsigned a, b, max_value;
public:
    RandomHashFunctionString(int max_value);
    ~RandomHashFunctionString();

    int hash(string x);
};


#endif //LESSON_6_HASHING_RANDOMHASHFUNCTION_H
