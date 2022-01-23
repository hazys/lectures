//
// Created by user on 28.12.2021.
//

#ifndef LESSON_6_HASHING_CUCKOOHASHING_H
#define LESSON_6_HASHING_CUCKOOHASHING_H



#include <string>
#include <vector>
#include "RandomHashFunction.h"


using namespace std;


class CuckooHashing {
private:
    vector<pair<string, float>> map1;
    vector<pair<string, float>> map2;
    RandomHashFunctionString hash1;
    RandomHashFunctionString hash2;
    float invalid;

    bool _shift(string key, float value);
    void rebuild(string key, float value);
public:
    CuckooHashing(int size, float invalid);
    ~CuckooHashing();
    void put(string key, float value);
    float get(string key);
    void remove(string key);
};


#endif //LESSON_6_HASHING_CUCKOOHASHING_H
