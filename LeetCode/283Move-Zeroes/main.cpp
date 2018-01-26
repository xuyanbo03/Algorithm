#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    //时间复杂度O(n)，空间复杂度O(n)
    void moveZeroes(vector<int> &nums) {
        vector<int> nonZeroElements;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                nonZeroElements.push_back(nums[i]);
            }
        }
        for (int i = 0; i < nonZeroElements.size(); i++) {
            nums[i] = nonZeroElements[i];
        }
        for (int i = nonZeroElements.size(); i < nums.size(); i++) {
            nums[i] = 0;
        }
    }

    //时间复杂度O(n)，空间复杂度O(1)
    void moveZeroes1(vector<int> &nums) {
        int k = 0;//nums中，[0,k)的元素均为0
        //遍历到第i个元素后，保证[0,i)中所有非0元素都按照顺序排列在[0,k)中
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                nums[k++] = nums[i];
            }
        }
        //将nums剩余位置补0
        for (int i = k; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }

    //时间复杂度O(n)，空间复杂度O(1)
    void moveZeroes2(vector<int> &nums) {
        int k = 0;//nums中，[0,k)的元素均为0
        //遍历到第i个元素后,保证[0,i)中所有非0元素都按照顺序排列在[0,k)中,同时[k,i]为0
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                if (i != k) {
                    swap(nums[k++], nums[i]);
                } else {
                    k++;
                }
            }
        }
    }
};

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    Solution().moveZeroes2(vec);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    return 0;
}