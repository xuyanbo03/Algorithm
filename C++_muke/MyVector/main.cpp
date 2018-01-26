#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

template<typename T>
class MyVector {
private:
    T *data;
    int capacity;//存储数组中可以容纳的最大数组个数
    int size;//存储数组中元素个数

    //O(n)
    void resize(int newCapacity) {
        assert(newCapacity >= size);
        T *newData = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    MyVector() {
        data = new T[10];
        capacity = 10;
        size = 0;
    }

    ~MyVector() {
        delete[] data;
    }

    //均摊时间复杂度平均情况下仍为O(1)
    void push_back(T e) {
        //assert(size < capacity);
        if (size == capacity) {
            resize(2 * capacity);
        }
        data[size++] = e;
    }

    //均摊平均情况为O(1)
    T pop_back() {
        assert(size > 0);
        T ret = data[size - 1];
        size--;
        //会产生复杂度震荡,在临界点频繁增加或删除元素
//        if (size == capacity / 2) {
//            resize(capacity / 2);
//        }
        //防止复杂度震荡方法,当capacity / 4时再resize(capacity / 2)，留出一定的空间
        if (size == capacity / 4) {
            resize(capacity / 2);
        }
        return ret;
    }
};

int main() {
    for (int i = 10; i <= 26; i++) {
        int n = pow(2, i);
        clock_t startTime = clock();
        MyVector<int> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back(i);
        }
        for (int i = 0; i < n; i++) {
            vec.pop_back();
        }
        clock_t endTime = clock();

        cout << 2 * n << "operations:\t";
        cout << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }

    return 0;
}