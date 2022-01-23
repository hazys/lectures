#include <iostream>
#include "utils.h"
#include "HashList.h"
#include "HashOpenAddressing.h"
#include "RandomHashFunction.h"
#include "CuckooHashing.h"
#include "BloomFilter.h"
#include <chrono>
using namespace std;
using namespace std::chrono;



std::string gen_random(const int len) {
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}


int main() {



    HashList hash(100, -1);

    /*
    hash.put("мама", 1.0);
    hash.put("мыла", 2.0);
    hash.put("рама", 3.0);

    std::cout << hash.get("мыла") << std::endl;
    hash.remove("мыла");
    std::cout << hash.get("мыла") << std::endl;
    std::cout << hash.get("мама") << std::endl;
    std::cout << hash.get("рама") << std::endl;
     */


    HashOpenAddressing hash_open(100, -1);

    /*
    hash_open.put("мама", 1.0);
    hash_open.put("мыла", 2.0);
    hash_open.put("рама", 3.0);

    std::cout << hash_open.get("мыла") << std::endl;
    hash_open.remove("мыла");
    std::cout << hash_open.get("мыла") << std::endl;
    std::cout << hash_open.get("мама") << std::endl;
    std::cout << hash_open.get("рама") << std::endl;
     */


    /*
    for(int i=0; i<100; i++){
        hash.put(gen_random(10), (float)i);
        hash_open.put(gen_random(10), (float)i);
    }


    int tmp;
    auto start = high_resolution_clock::now();
    for(int i = 0; i < 1000000; i++)
        tmp = hash.get("мама");
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "time 1: " << duration.count() << endl;

    start = high_resolution_clock::now();
    for(int i = 0; i < 1000000; i++)
        tmp = hash_open.get("мама");
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "time 2: " << duration.count() << endl;



    CuckooHashing chash(10, -1);


    for (int i=0; i<15; i++)
        chash.put(to_string(i), i);
    chash.put("10307", 1);
    chash.put("20308", 1);


    for(int i=0; i<15; i++)
        cout << chash.get(to_string(i)) << endl;
        */

    BloomFilter bloomFilter(100, 0.05);
    bloomFilter.add("мама");
    cout << bloomFilter.get_size(1000000, 0.001) << endl;
    cout << bloomFilter.check("мама") << endl;
    cout << bloomFilter.check("папа") << endl;



    return 0;
}
