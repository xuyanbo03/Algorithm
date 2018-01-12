#include <iostream>
#include <algorithm>
#include "MaxHeap.h"
#include "MergeSort.h"
#include "QuickSort2.h"
#include "SortTestHelper.h"
#include "HeapSort.h"

using namespace std;

template<typename T>
void __shiftDown(T arr[], int n, int k) {
    while (2 * k + 1 < n) {
        int j = 2 * k + 1;
        if (j + 1 < n && arr[j + 1] > arr[j]) {
            j = j + 1;
        }
        if (arr[k] >= arr[j]) {
            break;
        }
        swap(arr[k], arr[j]);
        k = j;
    }
}

template<typename T>
void heapSort(T arr[], int n) {
    //heapify
    for (int i = (n - 1) / 2; i >= 0; i--) {
        __shiftDown(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        __shiftDown(arr, i, 0);
    }
}

int main() {
    int n = 1000000;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    int *arr4 = SortTestHelper::copyIntArray(arr1, n);
    int *arr5 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort 2", quickSort2, arr2, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr3, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr4, n);
    SortTestHelper::testSort("Heap Sort", heapSort, arr5, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    cout << endl;

    int swapTimes = 100;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort 2", quickSort2, arr2, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr3, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr4, n);
    SortTestHelper::testSort("Heap Sort", heapSort, arr5, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    cout << endl;

    arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort 2", quickSort2, arr2, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr3, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr4, n);
    SortTestHelper::testSort("Heap Sort", heapSort, arr5, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    return 0;
}