#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = n - 1; // [l, r]: range of the candidates for kth largest

        while (l <= r) {
            // need randomization to avoid infinite loop
            int pi = l + rand() % (r - l + 1);
            int count = l;

            swap(nums[r], nums[pi]);  // move pivot to the right
            for (int i = l; i < r; ++i) {
                if (nums[i] > nums[r]) {
                    swap(nums[count++], nums[i]); //push elements larger than nums[r] to the right
                }
            }
            swap(nums[r], nums[count]); // move pivot to the correct position in the middle

            if (count < k - 1) {
                l = count + 1;
            } else if (count > k - 1) {
                r = count - 1;
            } else { // found
                return nums[count];
            }
        }
    }
};

int main() {
    return 0;
}