//
// Created by user on 28.12.2021.
//

#include "HashOpenAddressing.h"
#include "HashList.h"
#include "utils.h"

#define FREE_KEY ""
#define DELETED_KEY " _ "





HashOpenAddressing::HashOpenAddressing(int size, float invalid){
    this->invalid = invalid;
    this->map.resize(size * 2);
}
HashOpenAddressing::~HashOpenAddressing(){

}
void HashOpenAddressing::put(string key, float value){
    int hash = hash_string(key, map.size());
    for (int i=0; i<map.size(); i++){

        int idx = hash + i;
        if (hash + i >=  map.size())
            idx = idx % map.size();

        if (map[idx].first == key){
            map[idx].second = value;
            return;
        }

        if ((map[idx].first == FREE_KEY) or (map[idx].first == DELETED_KEY)){
            auto tmp = pair<string, float>(key, value);
            map[idx] = tmp;
            return;
        }
    }
}
float HashOpenAddressing::get(string key){
    int hash = hash_string(key, map.size());
    for (int i=0; i<map.size(); i++){

        int idx = hash + i;
        if (hash + i >=  map.size())
            idx = idx % map.size();

        auto item = map[idx];

        if (item.first == key){
            return item.second;
        }

        if ((item.first == FREE_KEY)){
            return invalid;
        }
    }

}
void HashOpenAddressing::remove(string key){
    int hash = hash_string(key, map.size());
    for (int i=0; i<map.size(); i++){

        int idx = hash + i;
        if (hash + i >=  map.size())
            idx = idx % map.size();

        auto item = map[idx];

        if (item.first == key){
            auto tmp = pair<string, float>(DELETED_KEY, 0.0);
            map[idx] = tmp;
            return;
        }

        if ((item.first == FREE_KEY)){
            return;
        }
    }
}
