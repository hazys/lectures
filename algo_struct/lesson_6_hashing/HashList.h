//
// Created by user on 18.12.2021.
//

#ifndef LESSON_6_HASHING_HASHLIST_H
#define LESSON_6_HASHING_HASHLIST_H

#include <string>
#include <vector>
#include <list>

using namespace std;

class HashList {
private:
    vector<list<pair<string, float>>> map;
    int size;
    float invalid;
public:
    HashList(int size, float invalid);
    ~HashList();
    void put(string key, float value);
    float get(string key);
    void remove(string key);

};


#endif //LESSON_6_HASHING_HASHLIST_H
