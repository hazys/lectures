//
// Created by user on 06.01.2022.
//

#include "RangeTreeOperation.h"

int RangeTreeOperation::roundUP(int x){
    unsigned int p, dp;
    for(p=1<<((sizeof(unsigned int)<<2)-1), dp=sizeof(unsigned int)<<1; dp; dp>>=1) {
        if(p==x) return p;
        else p = p<x ? p<<dp : p>>dp;
    }
    return p>=x ? p : p<<1;
}



void RangeTreeOperation::_set(int idx, int val, int x, int lx, int rx){

}
int RangeTreeOperation::_sum(int l, int r, int x, int lx, int rx){

}
RangeTreeOperation::RangeTreeOperation(int size){

}
RangeTreeOperation::~RangeTreeOperation(){

}
void RangeTreeOperation::set(int idx, int value){

}
int RangeTreeOperation::sum(int from, int to){

}
void RangeTreeOperation::add(int from, int to, int value){

}
int RangeTreeOperation::get(int idx){

}
