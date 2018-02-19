#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution70 {
    //70. Climbing Stairs
public:
    int climbStairs(int n) {
        //解法1：递归
        //return calcWays1(n);

        //解法2：记忆化搜索
        //memo = vector<int>(n + 1, -1);
        //return calcWays2(n);

        //解法3：动态规划
        vector<int> memo(n + 1, -1);
        memo[0] = 1;
        memo[1] = 1;
        for (int i = 2; i <= n; i++) {
            memo[i] = memo[i - 1] + memo[i - 2];
        }
        return memo[n];
    }

private:
    //解法1：递归
    int calcWays1(int n) {
//        if(n==1){
//            return 1;
//        }
//        if(n==2){
//            return 2;
//        }
        //优化
        if (n == 0 || n == 1) {
            return 1;
        }
        return calcWays1(n - 1) + calcWays1(n - 2);
    }

    //解法2：记忆化搜索
    vector<int> memo;

    int calcWays2(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        if (memo[n] == -1) {
            memo[n] = calcWays2(n - 1) + calcWays2(n - 2);
        }
        return memo[n];
    }
};

class Solution343 {
    //343. Integer Break
    //解法1：回溯遍历将一个数做分割的所有可能性
    //解法2：记忆化搜索
    //解法3：动态规划
private:
    //1
    //将n进行分割（至少分割两部分），可以获得最大乘积
    int breakInteger1(int n) {
        if (n == 1) {
            return 1;
        }
        int res = -1;
        for (int i = 1; i <= n - 1; i++) {
            res = max(res, max(i * (n - i), i * breakInteger1(n - i)));
        }
        return res;
    }

    //2
    vector<int> memo;

    int breakInteger2(int n) {
        if (n == 1) {
            return 1;
        }
        if (memo[n] != -1) {
            return memo[n];
        }
        int res = -1;
        for (int i = 1; i <= n - 1; i++) {
            res = max(res, max(i * (n - i), i * breakInteger2(n - i)));
        }
        memo[n] = res;
        return res;
    }

public:
    int integerBreak(int n) {
        //return breakInteger1(n);

//        assert(n>=2);
//        memo = vector<int>(n + 1, -1);
//        return breakInteger2(n);

        //3
        assert(n >= 2);
        //memo[i]表示将数字i分割（至少分割两部分）后得到的最大乘积
        vector<int> memo(n + 1, -1);
        memo[1] = 1;
        //求解memo[i]
        for (int i = 2; i <= n; i++) {
            //j+(i-j)
            for (int j = 1; j <= i - 1; j++) {
                memo[i] = max(memo[i], max(j * (i - j), j * memo[i - j]));
            }
        }
        return memo[n];
    }
};

class Solution198 {
    //198. House Robber
    //1.暴力解法：检查所有房子的组合，对每个组合，检查是否有相邻的房子，如果没有，记录其价值，找最大值。O((2^n)n)
    //2.递归
    //3.记忆化搜索
    //4.动态规划：注意其中对状态的定义：考虑偷取[x...n-1]范围里的房子（相当于递归函数的定义）；根据对状态的定义，决定状态的转移
    // 状态转移方程f(0)=max{v(0)+f(2),v(1)+f(3)...v(n-3)+f(n-1),v(n-2),v(n-1)}
private:
    //1
    //考虑抢劫nums[index...nums.size())这个范围的所有房子
    int tryRob1(vector<int> &nums, int index) {
        if (index >= nums.size()) {
            return 0;
        }
        int res = 0;
        for (int i = index; i < nums.size(); i++) {
            res = max(res, nums[i] + tryRob1(nums, i + 2));
        }
        return res;
    }

    //2
    //memo[i]表示考虑抢劫nums[i...n)欧能获得的最大收益
    vector<int> memo;

    int tryRob2(vector<int> &nums, int index) {
        if (index >= nums.size()) {
            return 0;
        }
        if (memo[index] != -1) {
            return memo[index];
        }
        int res = 0;
        for (int i = index; i < nums.size(); i++) {
            res = max(res, nums[i] + tryRob2(nums, i + 2));
        }
        memo[index] = res;
        return res;
    }

public:
    int rob(vector<int> &nums) {
        //return tryRob1(nums,0);

        //memo = vector<int>(nums.size(), -1);
        //return tryRob2(nums, 0);

        //3
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        //memo[i]表示考虑抢劫nums[i...n-1]欧能获得的最大收益
        vector<int> memo(n, -1);
        memo[n - 1] = nums[n - 1];
        //memo[i]
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                memo[i] = max(memo[i], nums[j] + (j + 2 < n ? memo[j + 2] : 0));
            }
        }
        return memo[0];
    }
};

class Knapsack01 {
private:
    //1
    //用[0...index]的物品，填充容积为c的背包的最大价值
    int bestValue1(const vector<int> &w, const vector<int> &v, int index, int c) {
        if (index < 0 || c <= 0) {
            return 0;
        }
        int res = bestValue1(w, v, index - 1, c);
        if (c >= w[index]) {
            res = max(res, v[index] + bestValue1(w, v, index - 1, c - w[index]));
        }
        return res;
    }

    //2
    vector<vector<int>> memo;

    int bestValue(const vector<int> &w, const vector<int> &v, int index, int c) {
        if (index < 0 || c <= 0) {
            return 0;
        }
        if (memo[index][c] != -1) {
            return memo[index][c];
        }
        int res = bestValue(w, v, index - 1, c);
        if (c >= w[index]) {
            res = max(res, v[index] + bestValue(w, v, index - 1, c - w[index]));
        }
        memo[index][c] = res;
        return res;
    }

public:
    int knapsack01(const vector<int> &w, const vector<int> &v, int C) {
        //1
        //int n = w.size();
        //return bestValue(w, v, n - 1, C);

        //2
        //int n = w.size();
        //memo = vector<vector<int>>(n, vector<int>(C + 1, -1));
        //return bestValue(w, v, n - 1, C);

        //3动态规划
        //时间复杂度O(n*C),空间复杂的O(n*C)
        assert(w.size() == v.size());
        int n = w.size();
        if (n == 0) {
            return 0;
        }
        //3.1
        //vector<vector<int>> memo(n, vector<int>(C + 1, -1));

        //3.2
        //空间复杂优化为O(2*C)
//        vector<vector<int>> memo(2, vector<int>(C + 1, -1));
//        for (int j = 0; j <= C; j++) {
//            memo[0][j] = (j >= w[0] ? v[0] : 0);
//        }
//        for (int i = 1; i < n; i++) {
//            for (int j = 0; j <= C; j++) {
//                memo[i % 2][j] = memo[(i - 1) % 2][j];
//                if (j >= w[i]) {
//                    memo[i % 2][j] = max(memo[i % 2][j], v[i] + memo[(i - 1) % 2][j - w[i]]);
//                }
//            }
//        }
//        return memo[(n - 1) % 2][C];

        //3.3
        //空间复杂的O(C),二维数组降为一维
        vector<int> memo(C + 1, -1);
        for (int j = 0; j <= C; j++) {
            memo[j] = (j >= w[0] ? v[0] : 0);
        }
        for (int i = 1; i < n; i++) {
            for (int j = C; j >= w[i]; j--) {
                memo[j] = max(memo[j], v[i] + memo[j - w[i]]);
            }
        }
        return memo[C];
    }
};

class Solution416 {
    //416. Partition Equal Subset Sum
    //记忆化搜索
    //动态规划：状态转移方程：F(i,c)=F(i-1,c)||F(i-1,c-w(i))
private:
    //1
    //memo[i][c]表示使用索引[0...i]的这些元素，是否可以完全填充一个容量为c的背包
    //-1表示为未计算，0表示不可以填充，1表示可以填充
    vector<vector<int>> memo;

    //使用nums[0...index]是否可以完全填充一个容量为sum的背包
    bool tryPartition(const vector<int> &nums, int index, int sum) {
        if (sum == 0) {
            return true;
        }
        if (sum < 0 || index < 0) {
            return false;
        }
        if (memo[index][sum] != -1) {
            return memo[index][sum] == 1;
        }
        memo[index][sum] = (tryPartition(nums, index - 1, sum) || tryPartition(nums, index - 1, sum - nums[index])) ? 1
                                                                                                                    : 0;
        return memo[index][sum] == 1;
    }

public:
    bool canPartition(vector<int> &nums) {
        //1
//        int n = nums.size();
//        int sum = 0;
//        for (int i = 0; i < n; i++) {
//            assert(nums[i] > 0);
//            sum += nums[i];
//        }
//        if (sum % 2 != 0) {
//            return false;
//        }
//        memo = vector<vector<int>>(n, vector<int>(sum / 2 + 1, -1));
//        return tryPartition(nums, n - 1, sum / 2);

        //2
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            assert(nums[i] > 0);
            sum += nums[i];
        }
        if (sum % 2) {
            return false;
        }
        int C = sum / 2;
        vector<bool> memo(C + 1, false);
        for (int j = 0; j <= C; j++) {
            memo[j] = (nums[0] == j);
        }
        for (int i = 1; i < n; i++) {
            for (int j = C; j >= nums[i]; j--) {
                memo[j] = memo[j] || memo[j - nums[i]];
            }
        }
        return memo[C];
    }
};

class Solution300 {
    //300. Longest Increasing Subsequence
    //暴力解法：选择所有的子序列进行判断O((2^n)*n)
    //动态规划
    // LIS(i)表示以第i个数字为结尾的最长上升子序列的长度
    // LIS(i)表示[0..i]的范围内，选择数字nums[i]可以获得的最长上升子序列的长度
    // 状态转移方程：LIS(i)=max(1+LIS(j)(if nums[i]>nums[j]))
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        //memo[i]表示以第i个数字为结尾的最长上升子序列的长度
        vector<int> memo(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    memo[i] = max(memo[i], 1 + memo[j]);
                }
            }
        }
        int res = 1;
        for (int i = 0; i < n; i++) {
            res = max(res, memo[i]);
        }
        return res;
    }
};

int main() {
    return 0;
}

/*
 * 动态规划
 * 本质实现：递归问题->重叠子问题->最优子结构->记忆化搜索（自顶向下的解决）->动态规划（自底向上的解决）
 * 1.斐波那契
 * 70
 * 120
 * 64
 *
 * 2。动态规划
 * 343
 * 279
 * 91
 * 62
 * 63
 *
 * 3.状态及状态转移
 * 198
 * 213
 * 337
 * 309
 *
 * 4.0-1背包问题
 * //暴力解法：每一件物品都可以放进背包，也可以不放进背包，求最大价值。O((2^n)*n)
 * //动态规划：状态转移方程：F(i,c)=max(F(i-1,c),v(i)+F(i-1,c-w(i)))。O(n*C)
 *
 * - 变种
 * 完全背包问题：每个物品可以无限使用
 * 多重背包问题：每个物品不止1个，有num[i]个
 * 多维费用背包问题：要考虑物品的体积和重量两个维度
 * 背包物品排斥或依赖问题
 *
 * 416
 * 322
 * 377
 * 474
 * 139
 * 494
 *
 * 5.最长上升子序列
 * 300
 * 376
 *
 * 6.拓展
 * - 最长公共子序列（LCS）
 * 状态转移方程
 * LCS(m,n) S1[0...m]和S2[0...n]的最长公共子序列的长度
 * S1[m]==S2[n]:LCS(m,n)=1+LCS(m-1,n-1)
 * S1[m]!=S2[n]:LCS(m,n)=max(LCS(m-1,n),LCS(m,n-1))
 *
 * - dijkstra单源最短路径算法
 *
 * */