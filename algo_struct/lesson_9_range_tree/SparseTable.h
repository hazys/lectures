//
// Created by user on 20.01.2022.
//

#ifndef LESSON_9_RANGE_TREE_SPARSETABLE_H
#define LESSON_9_RANGE_TREE_SPARSETABLE_H

#include <vector>

using namespace std;

class SparseTable {
private:
    int size;
    vector<vector<int>> table;
public:
    SparseTable(int array[], int size);
    ~SparseTable();
    int min(int from, int to);
};


#endif //LESSON_9_RANGE_TREE_SPARSETABLE_H
