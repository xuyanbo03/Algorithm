#include <iostream>
#include <vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    //104. Maximum Depth of Binary Tree求二叉树的最高深度，从根节点到叶子节点的最长路径长度
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    //226. Invert Binary Tree
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }

    //112. Path Sum
    //注意递归终止条件
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) {
            return false;
        }
        if (root->left == NULL && root->right == NULL) {
            return root->val == sum;
        }
        //优化后
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
        //优化前
//        if (hasPathSum(root->left, sum - root->val)) {
//            return true;
//        }
//        if (hasPathSum(root->right, sum - root->val)) {
//            return true;
//        }
//        return false;
    }
};

int main() {
    return 0;
}

/*
 * 二叉树与递归
 * 1.二叉树基础
 * 104
 * 111
 *
 * - 递归
 * 226反转二叉树
 * 100判断二叉树是否一样
 * 101是否左右对称
 * 222求完全二叉树的节点个数
 * 110是否为平衡二叉树
 *
 * - 递归终止条件
 * 112
 * 111
 * 404
 *
 * 2.
 * */