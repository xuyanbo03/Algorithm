#ifndef SELECTIONSORTS_SELECTIONSORT_H
#define SELECTIONSORTS_SELECTIONSORT_H

#include<iostream>
#include<ctime>
#include<cassert>

using namespace std;

namespace SortTestHelper {
    //生成有n个数组的随机整数,每个元素的随机范围[rangeL,rangeR]
    int *generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);

        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    //打印排序后的数组
    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    //测试排序的正确性
    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

    //测试排序性能
    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
        //测试时间,使用clock()函数,返回clock_t类型
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();

        assert(isSorted(arr, n));
        //endTime - startTime为运行了几个时钟周期
        //每秒钟运行的时钟周期的个数CLOCKS_PER_SEC,宏定义
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

        return;
    }
}

#endif //SELECTIONSORTS_SELECTIONSORT_H
