//
// Created by user on 19.01.2022.
//

#include "BinaryIndexedTree.h"

BinaryIndexedTree::BinaryIndexedTree(int size) {
    data.resize(size);
}


BinaryIndexedTree::~BinaryIndexedTree() {

}

int BinaryIndexedTree::_sum(int right){
    //int x = right - 1;
    int x = right;
    int res = 0;
    while (x >= 0){
        res += data[x];
        x = (x & (x + 1)) - 1;
    }
    return res;
}

int BinaryIndexedTree::sum(int from, int to){
    return _sum(to) - _sum(from);
}
int BinaryIndexedTree::inc(int index, int value){
    int i = index;
    while (i < data.size()){
        data[i] += value;
        i = i | (i + 1);
    }
}


