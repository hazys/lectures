//
// Created by user on 17.01.2022.
//

#include <cmath>
#include "BloomFilter.h"
#include "MurmurHash3.h"



#define LOG2 log(2)

BloomFilter::BloomFilter(int items_number, float false_prob){
    items = items_number;
    probality = false_prob;
    bit_size = get_size(items_number, false_prob);
    size_128 = new_size(bit_size);
    hash_count = get_hash_count(bit_size, items_number);
    bytes = new char [size_128 / 16];
}

BloomFilter::~BloomFilter(){
    delete [] bytes;
}

void BloomFilter::add(string item){
    char tmp[16];
    for (int i = 0; i < size_128 / 16 ; i++){
        MurmurHash3_x64_128(item.c_str(), item.size(), i, &tmp);
        for (int j = 0; j < 16; j++)
            bytes[128 * i + j] = tmp[j] | bytes[128 * i + j];
    }
}


bool BloomFilter::check(string item){
    char tmp[16];
    for (int i = 0; i < size_128 / 16 ; i++){
        MurmurHash3_x64_128(item.c_str(), item.size(), i, &tmp);
        for (int j = 0; j < 16; j++)
            if ((tmp[j] & bytes[128 * i + j]) != bytes[128 * i + j])
                return false;
    }
    return true;
}

int BloomFilter::get_size(int items_number, float false_prob){
    float m = -(items_number * log(false_prob)) / (LOG2 * LOG2);
    return int(m);
}

/*
int new_size(int items_number){
    if (items_number % 128 == 0)
        return  items_number;
    else
        return 128 * (items_number / 128 + 1);
}
*/



int BloomFilter::get_hash_count(int bit_array_size, int items_numbers){
    float k = (bit_array_size / items_numbers) * LOG2;
    return int(k);
}


