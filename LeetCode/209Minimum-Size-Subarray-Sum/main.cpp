#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        //思路一：暴力，三重

        //思路二：双索引，滑动窗口
        //时间复杂度O(n)
        int l = 0, r = -1;
        int sum = 0;
        int res = nums.size() + 1;
        while (l < nums.size()) {
            if (r + 1 < nums.size() && sum < s) {
                r++;
                sum += nums[r];
            } else {
                sum -= nums[l];
                l++;
            }
            if (sum >= s) {
                res = min(res, r - l + 1);
            }
        }
        if (res == nums.size() + 1) {
            return 0;
        }
        return res;
    }
};

int main() {
    return 0;
}