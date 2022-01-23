#include <iostream>
#include "RangeTree.h"
#include "RangeOperation.h"
#include "RangeTreeNoRec.h"
#include "RangeTreeOperation.h"
#include "BinaryIndexedTree.h"
#include "SparseTable.h"

using namespace std;

int main() {

    int n = 5;

    /*
    RangeTree rt(n);
    for(int i=0; i<n; i++)
        rt.set(i, i);

    for(int i=0; i<n; i++)
        cout << rt.sum(0, i) << endl;
    */


    /*
    RangeTreeNoRec rtnr(n);
    for(int i=0; i<n; i++)
        rtnr.set(i, i);

    for(int i=0; i<n; i++)
        cout << rtnr.sum(0, i) << endl;
        */

        /*
    RangeOperation ro(n);
    for(int i = 0; i < n; i++)
        ro.add(0, i, 1);

    for(int i=0; i<n; i++)
        cout << ro.get(i) << endl;
         */


    BinaryIndexedTree bit(6);
    bit.inc(0, 0);
    bit.inc(1, 1);
    bit.inc(2, 2);
    bit.inc(3, 3);
    bit.inc(4, 4);
    bit.inc(5, 5);

    cout << bit.sum(0, 4) << endl;


    int a[] = {1, -1, 3, 4, 5, 6};
    SparseTable spt(a, 6);
    cout << spt.min(0, 3) << endl;





    return 0;
}
