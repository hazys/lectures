//
// Created by user on 04.11.2021.
//

#ifndef ALGO_LECTIONS_LESSON_1_SORT_H
#define ALGO_LECTIONS_LESSON_1_SORT_H

void selectionSort(int* a, int size);
void bubbleSort(int* a, int size);
void insertionSort(int* a, int size);
void mergeSort(int* a, int size);
void quickSort(int* a, int size);
void bucketSort(int* a, int size, int num_buckets, int max_elemet);
void countSort(int* a, int size, int max_elemet);
void mergeSortRecursive(int* a, int size);
void mergeSortIterative(int* a, int size);
void radixSort(int a[], int size);
void bitonicSort(int a[], int size);
void heapSort(int a[], int size);

void _merge1(int* a, int* b, int* res, int size_a, int size_b);
void _merge2(int res[], int a[], int b[], int sizeA, int sizeB);
void _merge3(int a[], int temp[], int l, int m, int r);
void mergeSortDown(int a[], int size);
void  mergeSortAB(int a[], int size);
void mergeSortUP(int a[], int size);
void mergeSortInplace(int a[], int size);
int kStatistic(int a[], int k, int l, int r);



#endif //ALGO_LECTIONS_LESSON_1_SORT_H
