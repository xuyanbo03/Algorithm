#include <iostream>
#include <algorithm>
#include "MergeSort.h"
#include "SortTestHelper.h"

using namespace std;

//对arr[l,r]进行partition操作
//返回p，arr[l,p-1]<arr[p],arr[p+1,r]>arr[p]
template <typename T>
int __partition(T arr[],int l,int r){
    T v=arr[l];
    //arr[l+1,j]<v,arr[j+1,i)>v
    int j=l;
    for(int i=l+1;i<=r;i++){
        if(arr[i]<v){
            swap(arr[j+1],arr[i]);
            j++;
        }
    }
    swap(arr[l],arr[j]);
    return j;
}

//对arr[l,r]进行快速排序
template <typename T>
void __quickSort(T arr[],int l,int r){
    if(l>=r){
        return;
    }
    int p=__partition(arr,l,r);
    __quickSort(arr,l,p-1);
    __quickSort(arr,p+1,r);
}

template <typename T>
void quickSort(T arr[],int n){
    __quickSort(arr,0,n-1);
}

int main() {
    int n = 1000000;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

    delete[] arr1;
    delete[] arr2;
    return 0;
}