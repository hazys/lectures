#include <iostream>
#include "DisjointSetArray.h"
#include "DisjointSetTree.h"

using  namespace  std;


int main() {

    auto dsa = DisjointSetArray(10);
    dsa.unionSets(1, 2);
    dsa.unionSets(2, 3);
    dsa.unionSets(3, 4);
    dsa.unionSets(4, 5);

    cout << dsa.find(0) << endl;
    cout << dsa.find(1) << endl;
    cout << dsa.find(2) << endl;
    cout << dsa.find(3) << endl;
    cout << dsa.find(4) << endl;
    cout << dsa.find(5) << endl;
    cout << dsa.find(6) << endl;
    cout << dsa.find(7) << endl;
    cout << dsa.find(8) << endl;
    cout << dsa.find(9) << endl;

    auto  dst = DisjointSetTree(10);
    dst.unionSets(1, 2);
    dst.unionSets(2, 3);
    dst.unionSets(3, 4);
    dst.unionSets(4, 5);

    cout << dsa.find(0) << endl;
    cout << dsa.find(1) << endl;
    cout << dsa.find(2) << endl;
    cout << dsa.find(3) << endl;
    cout << dsa.find(4) << endl;
    cout << dsa.find(5) << endl;
    cout << dsa.find(6) << endl;
    cout << dsa.find(7) << endl;
    cout << dsa.find(8) << endl;
    cout << dsa.find(9) << endl;



    return 0;
}
