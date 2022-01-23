//
// Created by user on 19.01.2022.
//

#ifndef LESSON_9_RANGE_TREE_BINARYINDEXEDTREE_H
#define LESSON_9_RANGE_TREE_BINARYINDEXEDTREE_H

#include <vector>

using namespace std;

//Дерево Фенвика

class BinaryIndexedTree {
private:
    vector<int> data;
    int _sum(int right);
public:
    BinaryIndexedTree(int size);
    ~BinaryIndexedTree();
    int sum(int from, int to);
    int inc(int index, int value);
};


#endif //LESSON_9_RANGE_TREE_BINARYINDEXEDTREE_H
