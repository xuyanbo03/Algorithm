#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "InsertionSort.h"
//#include "MergeSort.h"

using namespace std;

//将arr[l,mid]和arr[mid+1,r]两部分进行归并
template<typename T>
void __merge(T arr[], int l, int mid, int r) {
    T aux[r - l + 1];
    for (int i = l; i <= r; i++) {
        aux[i - l] = arr[i];
    }
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (i > mid) {
            arr[k] = aux[j - l];
            j++;
        } else if (j > r) {
            arr[k] = aux[i - l];
            i++;
        } else if (aux[i - l] < aux[j - l]) {
            arr[k] = aux[i - l];
            i++;
        } else {
            arr[k] = aux[j - l];
            j++;
        }
    }
}

//递归使用归并排序，对arr[l,r]进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r) {
//    if (l >= r) {
//        return;
//    }
    if (r - l <= 15) {
        InsertionSort(arr, l, r);
        return;
    }
    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    if (arr[mid] > arr[mid + 1]) {
        __merge(arr, l, mid, r);
    }
}

template<typename T>
void mergeSortBU(T arr[], int n) {
    for (int sz = 1; sz <= n; sz += sz) {
        for (int i = 0; i + sz < n; i += sz + sz) {
            //对arr[i,i+sz-1]和arr[i+sz,i+sz+sz-1]进行归并
            __merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
        }
    }
}

int main() {
    int n = 50000;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", InsertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSortBU, arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    int swapTimes = 10;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", InsertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSortBU, arr2, n);

    delete[] arr1;
    delete[] arr2;
    return 0;
}