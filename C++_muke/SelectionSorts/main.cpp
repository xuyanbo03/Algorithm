#include<iostream>
#include<algorithm>//老版C++中swap函数所需库，C++11中std已包含
#include "SortTestHelper.h"
#include "Student.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        //寻找[i,n)区间里的最小值
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        //swap函数交换
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    //int a[10]={1,23,4,54,324,565,767,6,76,34};
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);

    //selectionSort(arr, n);
//    for(int i=0;i<n;i++){
//        cout << arr[i] << " ";
//    }
//    cout<<endl;
    //SortTestHelper::printArray(arr, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);

    delete[] arr;

//    Student d[4]={{"D",90},{"C",80},{"B",70},{"A",95}};
//    selectionSort(d,4);
//    for (int i = 0; i < 4; i++) {
//        cout<<d[i];
//    }
//    cout<<endl;

    return 0;
}