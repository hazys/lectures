//
// Created by user on 20.01.2022.
//

#include "SparseTable.h"
#include <cmath>

SparseTable::SparseTable(int array[], int size){

    int depth = (int)(log2(size) + 1);
    table.resize(size);
    for(int i=0; i<size; i++)
        table[i].resize(depth);
    this->size = size;

    for (int i = 0; i < size; i++)
        table[i][0] = array[i];

    for (int j = 1; (1 << j) <= size; j++) {
        for (int i = 0; (i + (1 << j) - 1) < size; i++) {
            int idx = i + (1 << (j - 1));
            if (table[i][j - 1] < table[idx][j - 1])
                table[i][j] = table[i][j - 1];
            else
                table[i][j] = table[idx][j - 1];
        }
    }
}

SparseTable::~SparseTable(){
}

int SparseTable::min(int from, int to){
    int j = (int)log2(to - from + 1);

    if (table[from][j] <= table[to - (1 << j) + 1][j])
        return table[from][j];

    else
        return table[to - (1 << j) + 1][j];
}