#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution455 {
    //455. Assign Cookies
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int si = 0, gi = 0, res = 0;
        while (si < s.size() && gi < g.size()) {
            if (s[si] >= g[gi]) {
                res++;
                si++;
                gi++;
            } else {
                gi++;
            }
        }
        return res;
    }
};


//Definition for an interval.
struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const Interval &a, const Interval &b) {
    if (a.start != b.start) {
        return a.start < b.start;
    }
    return a.end < b.end;
}

bool compare(const Interval &a, const Interval &b) {
    if (a.end != b.end) {
        return a.end < b.end;
    }
    return a.start < b.start;
}

class Solution435 {
    //435. Non-overlapping Intervals
    //暴力解法：找出所有子区间的组合，之后判断它不重叠O((2^n)*n)
    //贪心与动态规划：
    //动态规划：使用原理与最长上升子序列相同
    //贪心：按照区间的结尾排序，每次选择结尾最早的，且和前一个区间不重叠的区间
public:
    int eraseOverlapIntervals(vector<Interval> &intervals) {
        //动态规划
//        if (intervals.size()) {
//            return 0;
//        }
//        sort(intervals.begin(), intervals.end(), cmp);
//
//        //memo[i]表示使用intervals[0...i]的区间能构成的最长不重叠区间序列
//        vector<int> memo(intervals.size(), 1);
//        for (int i = 1; i < intervals.size(); i++) {
//            for (int j = 0; j < i; j++) {
//                if (intervals[i].start >= intervals[j].end) {
//                    memo[i] = max(memo[i], 1 + memo[j]);
//                }
//            }
//        }
//        int res = 0;
//        for (int i = 0; i < memo.size(); i++) {
//            res = max(res, memo[i]);
//        }
//        return intervals.size() - res;

        //贪心
        if (intervals.size() == 0) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), compare);

        int res = 1;
        int pre = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start >= intervals[pre].end) {
                res++;
                pre = i;
            }
        }
        return intervals.size() - res;
    }
};

int main() {
    return 0;
}

/*
 * 贪心算法
 * 1.简单贪心
 * 455
 * 392
 *
 * 2.贪心算法与动态规划的关系
 * 435
 *
 * 贪心选择性质
 * 若不符合贪心，举出反例
 * 证明方法：数学归纳法和反证法
 * 反证法证明：贪心算法为A，最优算法为O，发现A完全能替代O，且不影响求出最优解。
 * */