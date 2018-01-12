//
// Created by Awebone on 2018/1/12.
//

#ifndef MAXHEAP_HEAPSORT_H
#define MAXHEAP_HEAPSORT_H

#include <iostream>
#include <algorithm>
#include "MaxHeap.h"
//#include "MergeSort.h"
//#include "QuickSort2.h"
//#include "SortTestHelper.h"

using namespace std;

template<typename T>
void heapSort1(T arr[], int n) {
    MaxHeap<T> maxheap = MaxHeap<T>(n);
    for (int i = 0; i < n; i++) {
        maxheap.insert(arr[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = maxheap.extractMax();
    }
}

template<typename T>
void heapSort2(T arr[], int n) {
    MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = maxheap.extractMax();
    }
}

#endif //MAXHEAP_HEAPSORT_H
