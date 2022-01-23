//
// Created by user on 06.01.2022.
//

#ifndef LESSON_9_RANGE_TREE_RANGETREE_H
#define LESSON_9_RANGE_TREE_RANGETREE_H

#include <vector>



class RangeTree {
private:
    std::vector<int> tree;
    int size;
    int size2;
    void _set(int idx, int val, int x, int lx, int rx);
    int _sum(int l, int r, int x, int lx, int rx);
public:
    RangeTree(int size);
    ~RangeTree();
    void set(int idx, int value);
    int sum(int from, int to); // [from, to)



};


#endif //LESSON_9_RANGE_TREE_RANGETREE_H
