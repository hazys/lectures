//
// Created by user on 06.01.2022.
//

#ifndef LESSON_9_RANGE_TREE_RANGETREEOPERATION_H
#define LESSON_9_RANGE_TREE_RANGETREEOPERATION_H

#include <vector>


class RangeTreeOperation {
private:
    std::vector<int> tree;
    int size;

    int roundUP(int x);

    void _set(int idx, int val, int x, int lx, int rx);
    int _sum(int l, int r, int x, int lx, int rx);

public:
    RangeTreeOperation(int size);
    ~RangeTreeOperation();
    void set(int idx, int value);
    int sum(int from, int to); // [from, to)
    void add(int from, int to, int value);
    int get(int idx);
};


#endif //LESSON_9_RANGE_TREE_RANGETREEOPERATION_H
