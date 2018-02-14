#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <stack>
#include <queue>

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
 * 102二叉树的层序遍历
 * 107
 * 103
 * 199
 * */