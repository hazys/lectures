//
// Created by user on 07.12.2021.
//

#include "DisjointSetArray.h"

DisjointSetArray::DisjointSetArray(int size) {
    sets.resize(size);
    for (int i=0; i<size; i++)
        sets[i] = i;
}


DisjointSetArray::~DisjointSetArray() {

}

void DisjointSetArray::unionSets(int main, int other) {
    if (sets[main] == sets[other])
        return;
    else {
        int t = sets[other];
        for (int i = 0; i < sets.size(); i++)
            if (sets[i] == t)
                sets[i] = sets[main];
    }
}


int DisjointSetArray::find(int x) {
    return sets[x];
}