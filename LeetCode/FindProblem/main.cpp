#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    //349. Intersection of Two Arrays
    //set使用
    //时间复杂度O(nlogn)，空间复杂度O(n)
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
//        set<int> record;
//        for(int i=0;i<nums1.size();i++){
//            record.insert(nums1[i]);
//        }
        //O(nlogn)
        set<int> record(nums1.begin(), nums1.end());
        //O(nlogn)
        set<int> resultSet;
        for (int i = 0; i < nums2.size(); i++) {
            if (record.find(nums2[i]) != record.end()) {
                resultSet.insert(nums2[i]);
            }
        }
        //O(n)
        return vector<int>(resultSet.begin(), resultSet.end());
//        vector<int> resultVector;
//        for(set<int>::iterator iter=resultSet.begin();iter!=resultSet.end();iter++){
//            resultVector.push_back(*iter);
//        }
//        return resultVector;
    }


    //350. Intersection of Two Arrays II
    //map使用
    //时间复杂度O(nlogn)，空间复杂度O(n)
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        //O(nlogn)
        map<int, int> record;
        for (int i = 0; i < nums1.size(); i++) {
            if (record.find(nums1[i]) == record.end()) {
                record.insert(make_pair(nums1[i], 1));
            } else {
                record[nums1[i]]++;
            }
        }
        //O(nlogn)
        vector<int> resultVector;
        for (int i = 0; i < nums2.size(); i++) {
            if (record.find(nums2[i]) != record.end() && record[nums2[i]] > 0) {
                resultVector.push_back(nums2[i]);
                record[nums2[i]]--;
                if (record[nums2[i]] == 0) {
                    record.erase(nums2[i]);
                }
            }
        }
        return resultVector;
    }


    //1. Two Sum
    //时间复杂度O(n)，空间复杂度O(n)
    /*
     * 1.暴力O(n^2)
     * 2.排序后使用双索引对撞O(nlogn)+O(n)=O(nlogn)
     * 3.查找表。将所有元素放入查找表，之后对于每一个元素a，查找target-a是否存在。O(n)
     */
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (record.find(complement) != record.end()) {
                int res[2] = {i, record[complement]};
                return vector<int>(res, res + 2);
            }
            record[nums[i]] = i;
        }
        throw invalid_argument("the input has no solution");
    }


    //454. 4Sum II
    //时间复杂度O(n^2)，空间复杂度O(n^2)
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        assert(A.size() == B.size() && B.size() == C.size() && C.size() == D.size());
        unordered_map<int, int> record;
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < D.size(); j++) {
                record[C[i] + D[j]]++;
            }
        }

        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < D.size(); j++) {
                res += record[0 - A[i] - B[j]];
            }
        }
        return res;
    }


    //447. Number of Boomerangs
    //时间复杂度O(n^2)，空间复杂度O(n)
public:
    int numberOfBoomerangs(vector<pair<int, int>> &points) {
        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> record;
            for (int j = 0; j < points.size(); j++) {
                if (j != i) {
                    record[dis(points[i], points[j])]++;
                }
            }
            for (unordered_map<int, int>::iterator iter = record.begin(); iter != record.end(); iter++) {
                if (iter->second >= 2) {
                    res += (iter->second) * (iter->second - 1);
                }
            }
        }
        return res;
    }

private:
    int dis(const pair<int, int> &pa, const pair<int, int> &pb) {
        return (pa.first - pb.first) * (pa.first - pb.first) + (pa.second - pb.second) * (pa.second - pb.second);
    }


    //219. Contains Duplicate II
    //时间复杂度O(n)，空间复杂度O(k)
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_set<int> record;
        for (int i = 0; i < nums.size(); i++) {
            if (record.find(nums[i]) != record.end()) {
                return true;
            }
            record.insert(nums[i]);
            //保持record中最多k个元素
            if (record.size() == k + 1) {
                record.erase(nums[i - k]);
            }
        }
        return false;
    }


    //220. Contains Duplicate III
    //时间复杂度O(nlogn)，空间复杂度O(k)
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        set<long long> record;
        for (int i = 0; i < nums.size(); i++) {
            if (record.lower_bound((long long) nums[i] - (long long) t) != record.end() &&
                *record.lower_bound((long long) nums[i] - (long long) t) <= (long long) nums[i] + (long long) t) {
                return true;
            }
            record.insert(nums[i]);
            //保持record中最多k个元素
            if (record.size() == k + 1) {
                record.erase(nums[i - k]);
            }
        }
        return false;
    }
};

int main() {
    return 0;
}


/*
 * 查找问题
 *
 * 1.set/map使用
 * 349
 * 350
 * 242
 * 202
 * 290
 * 205
 * 451
 *
 * 2.使用查找表的经典问题
 * 1
 * 15
 * 18
 * 16
 *
 * 3.灵活选择键值
 * 454
 * 49
 *
 * 447
 * 149
 *
 * 4.滑动窗口
 * 219
 * 217
 *
 * 5.二叉搜索树底层实现的顺序性
 * 220
 * */
