#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <stdexcept>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Command {
    string s;//go,print
    TreeNode *node;

    Command(string s, TreeNode *node) : s(s), node(node) {}
};

class Solution {
    //20. Valid Parentheses
    //符号匹配
public:
    bool isValid(string s) {
        stack<char> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]);
            } else {
                if (stack.size() == 0) {
                    return false;
                }
                char c = stack.top();
                stack.pop();

                char match;
                if (s[i] == ')') {
                    match = '(';
                } else if (s[i] == ']') {
                    match = '[';
                } else {
                    assert(s[i] == '}');
                    match = '{';
                }

                if (c != match) {
                    return false;
                }
            }
        }
        if (stack.size() != 0) {
            return false;
        }
        return true;
    }

    //144. Binary Tree Preorder Traversal
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }

        stack<Command> stack;
        stack.push(Command("go", root));
        while (!stack.empty()) {
            Command command = stack.top();
            stack.pop();
            if (command.s == "print") {
                res.push_back(command.node->val);
            } else {
                assert(command.s == "go");
                if (command.node->right) {
                    stack.push(Command("go", command.node->right));
                }
                if (command.node->left) {
                    stack.push(Command("go", command.node->left));
                }
                stack.push(Command("print", command.node));
            }
        }
        return res;
    }

    //94. Binary Tree Inorder Traversal
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }

        stack<Command> stack;
        stack.push(Command("go", root));
        while (!stack.empty()) {
            Command command = stack.top();
            stack.pop();
            if (command.s == "print") {
                res.push_back(command.node->val);
            } else {
                assert(command.s == "go");
                if (command.node->right) {
                    stack.push(Command("go", command.node->right));
                }
                stack.push(Command("print", command.node));
                if (command.node->left) {
                    stack.push(Command("go", command.node->left));
                }
            }
        }
        return res;
    }

    //145. Binary Tree Postorder Traversal
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }

        stack<Command> stack;
        stack.push(Command("go", root));
        while (!stack.empty()) {
            Command command = stack.top();
            stack.pop();
            if (command.s == "print") {
                res.push_back(command.node->val);
            } else {
                assert(command.s == "go");
                stack.push(Command("print", command.node));
                if (command.node->right) {
                    stack.push(Command("go", command.node->right));
                }
                if (command.node->left) {
                    stack.push(Command("go", command.node->left));
                }
            }
        }
        return res;
    }


    //102. Binary Tree Level Order Traversal
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            TreeNode *node = q.front().first;
            int level = q.front().second;
            q.pop();
            if (level == res.size()) {
                res.push_back(vector<int>());
            }
            res[level].push_back(node->val);
            if (node->left) {
                q.push(make_pair(node->left, level + 1));
            }
            if (node->right) {
                q.push(make_pair(node->right, level + 1));
            }
        }
        return res;
    }


    //279. Perfect Squares寻找最少的完全平方数
    //思路：对问题建模，先转换为图论问题，再求解最短路径
public:
    int numSquares(int n) {
        assert(n > 0);
        queue<pair<int, int> > q;
        q.push(make_pair(n, 0));
        vector<bool> visited(n + 1, false);
        visited[n] = true;

        while (!q.empty()) {
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

//            if (num == 0) {
//                return step;
//            }
//            for (int i = 1; num - i * i >= 0; i++) {
//                if (!visited[num - i * i]) {
//                    q.push(make_pair(num - i * i, step + 1));
//                    visited[num - i * i] = true;
//                }
//            }
            for (int i = 1;; i++) {
                int a = num - i * i;
                if (a < 0) {
                    break;
                }
                if (a == 0) {
                    return step + 1;
                }
                if (!visited[a]) {
                    q.push(make_pair(a, step + 1));
                    visited[a] = true;
                }
            }
        }
    }


    //347. Top K Frequent Elements
    //解法1：扫描一遍统计频率，排序找到前k个出现频率最高的元素
    //解法2：维护一个含有k个元素的优先队列。如果遍历到的元素比队列中的最小频率元素的频率高，则取出队列中最小频率的元素，将新元素入队。最终，队列剩下的就是前k个出现频率最高的元素。
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        assert(k > 0);
        //统计每个元素出现的频率
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        assert(k <= freq.size());

        //扫描freq，维护当前出现频率最高的k个元素
        //在优先队列中，按照频率排序，所以数据对是(频率，元素)的形式
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        for (unordered_map<int, int>::iterator iter = freq.begin(); iter != freq.end(); iter++) {
            if (pq.size() == k) {
                if (iter->second > pq.top().first) {
                    pq.pop();
                    pq.push(make_pair(iter->second, iter->first));
                }
            } else {
                pq.push(make_pair(iter->second, iter->first));
            }
        }

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

int main() {
    return 0;
}

/*
 * 栈、队列、优先队列
 * 1.栈的使用，解决嵌套中最近的匹配
 * 20符号匹配
 * 150逆波兰表达式
 * 71简化Unix系统下的路径
 *
 * 2.栈与递归的联系
 * 二叉树简单算法，前序、中序、后序遍历
 * 144
 * 94
 * 145
 *
 * 341
 *
 * 3.队列的基本应用，广度优先遍历
 * - 树，层序遍历
 * - 图，无权图的最短路径
 *
 * 树的广度优先遍历，层序遍历
 * 102二叉树的层序遍历
 * 107
 * 103
 * 199
 *
 * BFS和图的最短路径
 * 279
 * 127
 * 126
 *
 * 4.优先队列:堆
 * - C++中STL中priority queue默认情况下为最大堆priority_queue<int> pq;
 * - 使用最小堆：priority_queue<int,vector<int>,greater<int> > pq;
 * - 使用自定义Comparator的priority queue：priority_queue<int,vector<int>,function<bool(int,int)> > pq(myCmp);
 * bool myCmp(int a, int b) {
 *   return a % 10 > b % 10;
 * }
 *
 * 347
 * 23 k分归并排序
 *
 * */
