//
// Created by user on 17.01.2022.
//

#ifndef LESSON_6_HASHING_MURMURHASH3_H
#define LESSON_6_HASHING_MURMURHASH3_H

#include <inttypes.h>

void MurmurHash3_x86_32 ( const void * key, int len,
                          uint32_t seed, void * out );


void MurmurHash3_x86_128 ( const void * key, const int len,
                           uint32_t seed, void * out );

void MurmurHash3_x64_128 ( const void * key, const int len,
                           uint32_t seed, void * out );


#endif //LESSON_6_HASHING_MURMURHASH3_H
