//
// Created by user on 08.12.2021.
//

#include "DisjointSetTree.h"

DisjointSetTree::DisjointSetTree(int size) {
    ranks.resize(size);
    parents.resize(size);
    for (int i = 0; i < size; i++){
        parents[i] = i;
        ranks[i] = 0;
    }
}

DisjointSetTree::~DisjointSetTree() {
}


void DisjointSetTree::unionSets(int main, int other) {
    main = find(main);
    other = find(other);
    if (main == other)
        return;
    if (ranks[main] == ranks[other])
        ranks[main]++;
    if (ranks[main] < ranks[other])
        parents[main] = other;
    else
        parents[other] = main;
}



int DisjointSetTree::find(int x) {
    if (parents[x] != x)
        parents[x] = find(parents[x]);
    return parents[x];
}