#include <iostream>
#include "lection_0_search.h"
#include "lesson_1_sort.h"
#include <chrono>
#include "galoping_merge.h"
#include <algorithm>
#include "my_merge.h"


#define N 1000
#define M 100


void random_array(int array[], int size, int max_el){
    for (int i=0; i<size; i++){
        array[i] = rand() % max_el;
    }
}

int main() {


    /*
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[] = {1, 2, 5, 7, 8, 10};
    int c[20];

    int pos = my_merge(a, b, c, 10, 6);
    std::cout << pos << std::endl;
    for (int i=0; i<pos; i++)
        std::cout << c[i] << std::endl;
    */




    /*
    int a[N], b[N], c[3*N];
    random_array(a, N, M);
    random_array(b, N, M);
    std::sort(std::begin(a), std::end(a));
    std::sort(std::begin(b), std::end(b));

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    merge(a, b, c, N, N);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Simple merge = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    random_array(a, N, M);
    random_array(b, N, M);
    std::sort(std::begin(a), std::end(a));
    std::sort(std::begin(b), std::end(b));

    begin = std::chrono::steady_clock::now();
    my_merge(a,b,c, N, N);
    end = std::chrono::steady_clock::now();
    std::cout << "My merge = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    */





    /*
    int a[] = {1, 2, 3, 4, 5, 7};
    std::cout << binarySearch(a, 0, 0, 6) << std::endl;
    std::cout << binarySearch(a, 1, 0, 6) << std::endl;
    std::cout << binarySearch(a, 2, 0, 6) << std::endl;
    std::cout << binarySearch(a, 3, 0, 6) << std::endl;
    std::cout << binarySearch(a, 4, 0, 6) << std::endl;
    std::cout << binarySearch(a, 5, 0, 6) << std::endl;
    std::cout << binarySearch(a, 6, 0, 6) << std::endl;
    std::cout << binarySearch(a, 7, 0, 6) << std::endl;
    std::cout << binarySearch(a, 8, 0, 6) << std::endl;
     */

    /*
    int a[] = {1, 2, 3, 4, 5, 7};
    std::cout << galopingBinarySearch(a, 0, 0, 6) << std::endl;
    std::cout << galopingBinarySearch(a, 1, 0, 6) << std::endl;
    std::cout << galopingBinarySearch(a, 2, 0, 6) << std::endl;
    std::cout << galopingBinarySearch(a, 3, 0, 6) << std::endl;
    std::cout << galopingBinarySearch(a, 4, 0, 6) << std::endl;
    std::cout << galopingBinarySearch(a, 5, 0, 6) << std::endl;
    std::cout << galopingBinarySearch(a, 6, 0, 6) << std::endl;
    std::cout << galopingBinarySearch(a, 7, 0, 6) << std::endl;
    std::cout << galopingBinarySearch(a, 8, 0, 6) << std::endl;
     */

    /*
    int a[] = {1, 2, 3, 3, 4, 5, 7};
    int b[] = {2, 3, 3, 3, 10};
    int r[100] = {0};
    galopingMerge(a, b, r, 7, 5);
    for (int i=0; i<10; i++)
        std::cout << r[i] << std::endl;
    */

    /*
    int a[N], b[N], c[3*N], d[N / 2], e[N / 10];
    random_array(a, N, M);
    random_array(b, N, M);
    random_array(d, N / 2, M);
    random_array(e, N / 10, M);
    std::sort(std::begin(a), std::end(a));
    std::sort(std::begin(b), std::end(b));
    std::sort(std::begin(d), std::end(b));
    std::sort(std::begin(e), std::end(b));
     */


    /*
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    merge(a, b, c, N, N);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Simple merge = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    begin = std::chrono::steady_clock::now();
    galopingMerge(a,b,c, N, N);
    end = std::chrono::steady_clock::now();
    std::cout << "Galoping merge = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    begin = std::chrono::steady_clock::now();
    merge(a, d, c, N, N / 2);
    end = std::chrono::steady_clock::now();
    std::cout << "Simple merge different = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    begin = std::chrono::steady_clock::now();
    galopingMerge(a, d, c, N, N / 2);
    end = std::chrono::steady_clock::now();
    std::cout << "Galoping merge different = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;


    begin = std::chrono::steady_clock::now();
    merge(a, e, c, N, N / 10);
    end = std::chrono::steady_clock::now();
    std::cout << "Simple merge different = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    begin = std::chrono::steady_clock::now();
    galopingMerge(a, e, c, N, N / 10);
    end = std::chrono::steady_clock::now();
    std::cout << "Galoping merge different = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    */


    /*
    int a[N];

    random_array(a);
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    selectionSort(a, N);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Selection Sort time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    random_array(a);
    begin = std::chrono::steady_clock::now();
    bubbleSort(a, N);
    end = std::chrono::steady_clock::now();
    std::cout << "Bubble Sort time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    random_array(a);
    begin = std::chrono::steady_clock::now();
    insertionSort(a, N);
    end = std::chrono::steady_clock::now();
    std::cout << "Insertion Sort time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;


    random_array(a);
    begin = std::chrono::steady_clock::now();
    bitonicSort(a, N);
    end = std::chrono::steady_clock::now();
    std::cout << "Bitonic Sort time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;


    random_array(a);
    begin = std::chrono::steady_clock::now();
    mergeSort(a, N);
    end = std::chrono::steady_clock::now();
    std::cout << "Merge Sort time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    random_array(a);
    begin = std::chrono::steady_clock::now();
    mergeSortRecursive(a, N);
    end = std::chrono::steady_clock::now();
    std::cout << "Merge Sort recurcive time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    random_array(a);
    begin = std::chrono::steady_clock::now();
    mergeSortIterative(a, N);
    end = std::chrono::steady_clock::now();
    std::cout << "Merge Sort iteration time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    random_array(a);
    begin = std::chrono::steady_clock::now();
    mergeSortInplace(a, N);
    end = std::chrono::steady_clock::now();
    std::cout << "Merge Sort inplace time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    random_array(a);
    begin = std::chrono::steady_clock::now();
    heapSort(a, N);
    end = std::chrono::steady_clock::now();
    std::cout << "Heap Sort = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;


    random_array(a);
    begin = std::chrono::steady_clock::now();
    quickSort(a, N);
    end = std::chrono::steady_clock::now();
    std::cout << "Quick Sort time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    random_array(a);
    begin = std::chrono::steady_clock::now();
    bucketSort(a, N, N/100, M);
    end = std::chrono::steady_clock::now();
    std::cout << "Bucket Sort time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    random_array(a);
    begin = std::chrono::steady_clock::now();
    radixSort(a, N);
    end = std::chrono::steady_clock::now();
    std::cout << "Radix Sort time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;


    random_array(a);
    begin = std::chrono::steady_clock::now();
    countSort(a, N, M);
    end = std::chrono::steady_clock::now();
    std::cout << "Count Sort time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    */

}
