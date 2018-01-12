#include <iostream>

using namespace std;

//二分查找法，在有序的arr中查找target
//如果找到，返回相应索引；没找到，返回-1
template<typename T>
int binarySearch(T arr[], int n, T target) {
    //在arr[l,r]中查找target
    int l = 0, r = n - 1;
    while (l <= r) {
        //int mid=(l+r)/2;
        int mid = l + (r - l) / 2;
        if (target == arr[mid]) {
            return mid;
        }
        if (target < arr[mid]) {
            //在arr[l,mid-1]中查找target
            r = mid - 1;
        } else {
            //在arr[mid+1,r]中查找target
            l = mid + 1;
        }
    }
    return -1;
}

int main() {
    return 0;
}