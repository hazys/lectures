//
// Created by user on 18.12.2021.
//

#include "HashList.h"
#include "utils.h"


HashList::HashList(int size, float invalid){
    this->size = size;
    this->map.resize(size);
    this->invalid = invalid;
}


HashList::~HashList(){

}


void HashList::put(string key, float value){
    int hash = hash_string(key, size);

    if (map[hash].size() == 0)
        map[hash].push_back(pair<string, float>(key, value));
    else{
        for (auto i = map[hash].begin(); i != map[hash].end(); i++)
            if(i->first == key){
                i->second = value;
                return;
            }
        map[hash].push_back(pair<string, float>(key, value));
    }
}

float HashList::get(string key){
    int hash = hash_string(key, size);
    if (map[hash].size() == 0)
        return invalid;
    if (map[hash].size() == 1)
        if(map[hash].begin()->first == key)
            return  map[hash].begin()->second;
        else
            return invalid;
    for (auto i = map[hash].begin(); i != map[hash].end(); i++)
        if(i->first == key)
            return i->second;
    return invalid;
}

void HashList::remove(string key){
    int hash = hash_string(key, size);
    if (map[hash].size() == 0)
        return;
    for (auto i = map[hash].begin(); i != map[hash].end(); i++)
        if(i->first == key) {
            map[hash].erase(i);
            return;
        }
}
