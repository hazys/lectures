//
// Created by user on 28.12.2021.
//

#ifndef LESSON_6_HASHING_HASHOPENADDRESSING_H
#define LESSON_6_HASHING_HASHOPENADDRESSING_H

#include <string>
#include <vector>

using namespace std;


class HashOpenAddressing {
private:
    vector<pair<string, float>> map;
    float invalid;

public:
    HashOpenAddressing(int size, float invalid);
    ~HashOpenAddressing();
    void put(string key, float value);
    float get(string key);
    void remove(string key);
};


#endif //LESSON_6_HASHING_HASHOPENADDRESSING_H
