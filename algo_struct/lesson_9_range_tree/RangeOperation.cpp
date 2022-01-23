//
// Created by user on 06.01.2022.
//

#include "RangeOperation.h"


int ro_round2UP(int x){
    unsigned int p, dp;
    for(p=1<<((sizeof(unsigned int)<<2)-1), dp=sizeof(unsigned int)<<1; dp; dp>>=1) {
        if(p==x) return p;
        else p = p<x ? p<<dp : p>>dp;
    }
    return p>=x ? p : p<<1;
}


RangeOperation::RangeOperation(int size){
    this->size = size;
    this->size2 = ro_round2UP(size);
    this->tree.resize(size2 + size2 - 1);
}
RangeOperation::~RangeOperation(){

}

int RangeOperation::_get(int i, int d, int x, int lx, int rx){
    if (rx - lx == 1) {
        return tree[x] + d;
    } else {
        int m = (lx + rx) / 2;
        if (i < m)
            return _get(i, d + tree[x], 2 * x + 1, lx, m);
        else
            return _get(i, d + tree[x], 2 * x + 2, m, rx);
    }
}
void RangeOperation::_add(int l, int r, int v, int x, int lx, int rx){
    if ((lx >= r) or (l >= rx))
        return;
    if ((l <= lx) and (rx <= r)){
        tree[x] += v;
        return;
    }
    int m = (lx + rx) / 2;
    _add(l, r, v, 2 * x + 1, lx, m);
    _add(l, r, v, 2 * x + 2, m, rx);
}

void RangeOperation::add(int from, int to, int value){
    _add(size2 + from - 1, size2 + to, value, 0, size2 - 1, size2 + size2 - 1);
}

int RangeOperation::get(int idx){
    return _get(size2 + idx - 1, 0, 0, size2 - 1, size2 + size2 - 1);
}
