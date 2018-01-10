#ifndef INSERTIONSORTS_INSERTIONSORT_H
#define INSERTIONSORTS_INSERTIONSORT_H

#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"

using namespace std;

//对arr数组中的n个元素排序
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
    return;
}

//对arr[l,r]范围的数组进行插入排序
template<typename T>
void InsertionSort(T arr[], int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        T e = arr[i];//寻找元素arr[i]合适的插入位值
        int j;//j保存元素e应该插入的位置
        for (j = i; j > l && arr[j - 1] > e; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
    return;
}

#endif //INSERTIONSORTS_INSERTIONSORT_H