//
// Created by user on 07.12.2021.
//

#ifndef LESSON_5_DISJOINT_SET_DISJOINTSETARRAY_H
#define LESSON_5_DISJOINT_SET_DISJOINTSETARRAY_H

#include <vector>

class DisjointSetArray {
private:
    std::vector<int> sets;
public:
    DisjointSetArray(int size);
    virtual ~DisjointSetArray();

    void unionSets(int x, int y);
    int find(int x);

};


#endif //LESSON_5_DISJOINT_SET_DISJOINTSETARRAY_H
