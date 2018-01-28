#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        //思路一：暴力
        //思路二：遍历i，对i后续数组进行二分查找
        //思路三：对撞指针
        //时间复杂度O(n)
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            if (numbers[l] + numbers[r] == target) {
                int res[2] = {l + 1, r + 1};
                return vector<int>(res, res + 2);
            } else if (numbers[l] + numbers[r] < target) {
                l++;
            } else {
                r--;
            }
        }
        return vector<int>(-1);
    }
};

int main() {
    return 0;
}