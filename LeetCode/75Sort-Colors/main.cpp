#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        //时间复杂度O(n),空间复杂的O(3)
        int count[3] = {0};
        for (int i = 0; i < nums.size(); i++) {
            assert(nums[i] >= 0 && nums[i] <= 2);
            count[nums[i]]++;
        }
        int index = 0;
        for (int i = 0; i < count[0]; i++) {
            nums[index++] = 0;
        }
        for (int i = 0; i < count[1]; i++) {
            nums[index++] = 1;
        }
        for (int i = 0; i < count[2]; i++) {
            nums[index++] = 2;
        }
    }

    void sortColors1(vector<int> &nums) {
        //3路快排，只进行1次partition即可
        //时间复杂度O(n),空间复杂的O(3)
        int zero = -1;//nums[0...zero]==0
        int two = nums.size();//nums[two...n-1]==2
        for (int i = 0; i < two;) {
            if (nums[i] == 1) {
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[--two]);
            } else {
                assert(nums[i] == 0);
                swap(nums[++zero], nums[i++]);
            }
        }
    }
};

int main() {
    return 0;
}