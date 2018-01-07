#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "SelectionSort.h"

using namespace std;

template<typename T>
void InsertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        //优化前
//        for (int j = i; j >0 && arr[j]<arr[j-1]; j--) {
//            swap(arr[j],arr[j-1]);
//        }
        //优化后
        //思路：避免交换赋值所耗的时，先拷贝一份，与j-1元素比较，最后赋值到合适位置
        T e = arr[i];//寻找元素arr[i]合适的插入位值
        int j;//j保存元素e应该插入的位置
        for (j = i; j > 0 && arr[j - 1] > e; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}

int main() {
    int n = 10000;
    int *arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);
    SortTestHelper::testSort("Insertion Sort", InsertionSort, arr, n);

    delete[] arr;
    delete[] arr2;
    return 0;
}