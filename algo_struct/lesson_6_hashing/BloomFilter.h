//
// Created by user on 17.01.2022.
//

#ifndef LESSON_6_HASHING_BLOOMFILTER_H
#define LESSON_6_HASHING_BLOOMFILTER_H

#include <string>
#include <boost/dynamic_bitset.hpp>

using namespace std;
using namespace boost;

class BloomFilter {
private:
    float probality;
    int items;
    int bit_size;
    int size_128;
    int hash_count;
    char* bytes;
public:
    BloomFilter(int items_number, float false_prob);
    ~BloomFilter();

    void add(string item);
    bool check(string item);
    int get_size(int items_number, float false_prob);
    int new_size(int items_number){
        if (items_number % 128 == 0)
            return  items_number;
        else
            return 128 * (items_number / 128 + 1);
    }
    int get_hash_count(int bit_array_size, int items_numbers);
};


#endif //LESSON_6_HASHING_BLOOMFILTER_H
