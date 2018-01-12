//
// Created by Awebone on 2018/1/12.
//

#ifndef MAXHEAP_INDEXMAXHEAP_H
#define MAXHEAP_INDEXMAXHEAP_H

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>
#include <cassert>

using namespace std;

//堆是从1开始索引的
template<typename Item>
class IndexMaxHeap {
private:
    Item *data;
    int *indexes;
    int *reverse;
    int count;
    int capacity;

    void shiftUp(int k) {
        while (k > 1 && data[indexes[k / 2]] < data[indexes[k]]) {
            swap(indexes[k / 2], indexes[k]);
            reverse[indexes[k / 2]] = k / 2;
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while (2 * k <= count) {
            int j = 2 * k;
            if (j + 1 <= count && data[indexes[j + 1]] > data[indexes[j]]) {
                j = j + 1;
            }
            if (data[indexes[k]] >= data[indexes[j]]) {
                break;
            }
            swap(indexes[k], indexes[j]);
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }
    }

public:
    IndexMaxHeap(int capacity) {
        data = new Item[capacity + 1];
        indexes = new int[capacity + 1];
        reverse = new int[capacity + 1];
        for (int i = 0; i <= capacity; i++) {
            reverse[i] = 0;
        }
        count = 0;
        this->capacity = capacity;
    }

    IndexMaxHeap(Item arr[], int n) {
        data = new Item[n + 1];
        indexes = new int[capacity + 1];
        capacity = n;
        for (int i = 0; i < n; i++) {
            data[i + 1] = arr[i];
        }
        count = n;
        for (int i = count / 2; i >= 1; i--) {
            shiftDown(i);
        }
    }

    ~MaxHeap() {
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    //传入的i对用户来说，是从0开始索引，要处理索引间的差异
    void insert(int i, Item item) {
        assert(capacity >= count + 1);
        assert(i + 1 >= 1 && i + 1 <= capacity);
        data[i] = item;
        indexes[count + 1] = i;
        reverse[i] = count + 1;
        count++;
        shiftUp(count);
    }

    Item extractMax() {
        assert(count > 0);
        Item ret = data[indexes[1]];
        swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count--;
        shiftDown(1);
        return ret;
    }

    int extractMaxIndex() {
        assert(count > 0);
        int ret = indexes[1] - 1;
        swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count--;
        shiftDown(1);
        return ret;
    }

    bool contain(int i) {
        assert(i + 1 >= 1 && i + 1 <= capacity);
        return reverse[i + 1] != 0;
    }

    Item getItem(int i) {
        assert(contain(i));
        return data[i + 1];
    }

    void change(int i, Item newItem) {
        //判断数组越界，用户给的i在当前堆中
        assert(contain(i));
        i += 1;
        data[i] = newItem;
        //找到indexes[j]==i,j表示data[i]在堆中的位置
        //之后shiftUp(j);shiftDown(j);
//        for (int j = 1; j <= count; j++) {
//            if (indexes[j] == i) {
//                shiftUp(j);
//                shiftDown(j);
//                return;
//            }
//        }
        //加入反向查找，进行优化后
        int j = reverse[i];
        shiftUp(j);
        shiftDown(j);
        return;
    }
};

#endif //MAXHEAP_INDEXMAXHEAP_H
