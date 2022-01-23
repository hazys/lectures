//
// Created by user on 06.01.2022.
//

#include "RangeTree.h"



int round2UP(int x){
    unsigned int p, dp;
    for(p=1<<((sizeof(unsigned int)<<2)-1), dp=sizeof(unsigned int)<<1; dp; dp>>=1) {
        if(p==x) return p;
        else p = p<x ? p<<dp : p>>dp;
    }
    return p>=x ? p : p<<1;
}

int roundUP2(int x)
{
    x = x - 1;
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    return x + 1;
}


RangeTree::RangeTree(int size){
    this->size = size;
    this->size2 = round2UP(size);
    this->tree.resize(size2 + size2 - 1);

}
RangeTree::~RangeTree(){

}

void RangeTree::_set(int idx, int val, int x, int lx, int rx){
    if (rx - lx == 1) {
        tree[x] = val;
    } else {
        int m = (lx + rx) / 2;
        if (idx < m)
            _set(idx, val, 2 * x + 1, lx, m);
        else
            _set(idx, val, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

}

void RangeTree::set(int idx, int value){
    _set(size2 + idx - 1, value, 0, size2 - 1, size2 + size2 - 1);

}

int RangeTree::_sum(int l, int r, int x, int lx, int rx){
    if ((l >= rx) or (lx >= r))
        return 0;
    if((l <= lx) and (rx <= r))
        return tree[x];
    int m = (lx + rx) / 2;
    int s1 =  _sum(l, r, 2 * x + 1, lx, m);
    int s2 =  _sum(l, r, 2 * x + 2, m, rx);
    return s1 + s2;


}


int RangeTree::sum(int from, int to){
    return _sum(from, to, 0, 0, size2 - 1);

}