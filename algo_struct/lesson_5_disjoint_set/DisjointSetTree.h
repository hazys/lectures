//
// Created by user on 08.12.2021.
//

#ifndef LESSON_5_DISJOINT_SET_DISJOINTSETTREE_H
#define LESSON_5_DISJOINT_SET_DISJOINTSETTREE_H

#include <vector>

class DisjointSetTree {

    std::vector<int> parents;
    std::vector<int> ranks;
public:
    DisjointSetTree(int size);
    virtual ~DisjointSetTree();

    void unionSets(int x, int y);
    int find(int x);

};


#endif //LESSON_5_DISJOINT_SET_DISJOINTSETTREE_H
