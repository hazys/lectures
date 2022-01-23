//
// Created by user on 06.01.2022.
//

#include "RangeTreeNoRec.h"

int round2UP2(int x)
{
    x = x - 1;
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    return x + 1;
}

RangeTreeNoRec::RangeTreeNoRec(int size){
    this->size = size;
    this->size2 = round2UP2(size);
    this->tree.resize(size2 + size2 - 1);

}
RangeTreeNoRec::~RangeTreeNoRec(){

}



void RangeTreeNoRec::set(int idx, int value){
    int x = idx + size2 - 1;
    int delta = value - tree[x];
    while (x >= 0){
        tree[x] += delta;
        x = (x + 1) / 2 - 1;

    }

}




int RangeTreeNoRec::sum(int from, int to){
    from = size2 - 1 + from;
    to = size2 - 1 + to;
    int res = 0, r1 = 0, r2 = 0;
    while (from <= to){
        if (from % 2 == 0){
            //r1 = r1 + tree[from]
            res += tree[from];
        }
        from = from / 2;
        if (to % 2 == 1){
            //r2 = tree[to] + r2;
            res += tree[to];
        }
        to = to / 2 - 1;
    }
    return res ;
}