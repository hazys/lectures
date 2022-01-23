//
// Created by user on 28.12.2021.
//

#include "CuckooHashing.h"

CuckooHashing::CuckooHashing(int size, float invalid): hash1(size), hash2(size){
    map1.resize(size);
    map2.resize(size);
    this->invalid = invalid;
}

CuckooHashing::~CuckooHashing(){

}


bool CuckooHashing::_shift(string key, float value){
    //int start_h1 = hash1.hash(key);
    //int start_h2 = hash2.hash(key);

    auto item = pair<string, float>(key, value);
    bool fl = false;

    int h1 = hash1.hash(item.first);
    if (map1[h1].first == ""){
        map1[h1] = item;
        return true;
    }

    int h2 = hash2.hash(item.first);
    if (map2[h2].first == ""){
        map2[h2] = item;
        return true;
    }

    if (fl)
        swap(map1[h1], item);
    else
        swap(map2[h2], item);
    fl = !fl;


    while (item.first != key){

        h1 = hash1.hash(item.first);
        if (map1[h1].first == ""){
            map1[h1] = item;
            return true;
        }

        h2 = hash2.hash(item.first);
        if (map2[h2].first == ""){
            map2[h2] = item;
            return true;
        }

        if (fl)
            swap(map1[h1], item);
        else
            swap(map2[h2], item);
        fl = !fl;

    }


    if (fl)
        swap(map1[h1], item);
    else
        swap(map2[h2], item);
    fl = !fl;

    while (item.first != key){

        h1 = hash1.hash(item.first);
        if (map1[h1].first == ""){
            map1[h1] = item;
            return true;
        }

        h2 = hash2.hash(item.first);
        if (map2[h2].first == ""){
            map2[h2] = item;
            return true;
        }

        if (fl)
            swap(map1[h1], item);
        else
            swap(map2[h2], item);
        fl = !fl;

    }



    return false;

}



void CuckooHashing::rebuild(string key, float value){
    vector<pair<string, float>> tmp;
    pair<string, float> null("", 0.0);
    for (int i = 0; i < map1.size(); i++){
        if (map1[i].first != "")
            tmp.push_back(map1[i]);
        if (map2[i].first != "")
            tmp.push_back(map2[i]);
    }
    tmp.push_back(pair<string, float>(key, value));

    bool fl = false;
    while (!fl){
        fl = true;
        hash1 = RandomHashFunctionString(map1.size());
        hash2 = RandomHashFunctionString(map2.size());
        for (int i = 0; i < map1.size(); i++){
            map1[i] = null;
            map2[i] = null;
        }
        for (int i = 0; i < tmp.size(); i++){
        fl &= _shift(tmp[i].first, tmp[i].second);
        if (!fl)
            break;
        }
    }
}


void CuckooHashing::put(string key, float value){
    auto item = pair<string, float>(key, value);

    int hash = hash1.hash(key);
    if (map1[hash].first == "") {
        map1[hash] = item;
        return;
    }

    hash = hash2.hash(key);
    if (map2[hash].first == ""){
        map2[hash] = item;
        return;
    }

    rebuild(key, value);
}


float CuckooHashing::get(string key){
    int hash = hash1.hash(key);
    if (map1[hash].first == key)
        return map1[hash].second;

    hash = hash2.hash(key);
    if (map2[hash].first == key)
        return map2[hash].second;

    return invalid;
}

void CuckooHashing::remove(string key){
    int hash = hash1.hash(key);
    if (map1[hash].first == key){
        map1[hash] = pair<string, float>("", 0.0);
        return;
    }
    hash = hash2.hash(key);
    if (map2[hash].first == key) {
        map2[hash] = pair<string, float>("", 0.0);
        return;
    }
}