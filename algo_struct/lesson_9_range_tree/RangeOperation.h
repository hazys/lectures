//
// Created by user on 06.01.2022.
//

#ifndef LESSON_9_RANGE_TREE_RANGEOPERATION_H
#define LESSON_9_RANGE_TREE_RANGEOPERATION_H

#include <vector>

using namespace std;

class RangeOperation {

private:
    vector<int> tree;
    int size;
    int size2;
    int _get(int idx, int val, int x, int lx, int rx);
    void _add(int l, int r, int v, int x, int lx, int rx);

public:
    RangeOperation(int size);
    ~RangeOperation();
    void add(int from, int to, int value);
    int get(int idx);
};


#endif //LESSON_9_RANGE_TREE_RANGEOPERATION_H
