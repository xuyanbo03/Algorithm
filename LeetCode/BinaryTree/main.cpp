#include <iostream>
#include <vector>
#include <string>
#include <cassert>

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


    //257. Binary Tree Paths
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> res;
        if (root == NULL) {
            return res;
        }
        if (root->left == NULL && root->right == NULL) {
            res.push_back(to_string(root->val));
            return res;
        }

        vector<string> leftS = binaryTreePaths(root->left);
        for (int i = 0; i < leftS.size(); i++) {
            res.push_back(to_string(root->val) + "->" + leftS[i]);
        }
        vector<string> rightS = binaryTreePaths(root->right);
        for (int i = 0; i < rightS.size(); i++) {
            res.push_back(to_string(root->val) + "->" + rightS[i]);
        }
        return res;
    }

    //437. Path Sum III
public:
    //在以root为根节点的二叉树中，寻找和为sum的路径，返回这样的路径个数
    int pathSum(TreeNode *root, int sum) {
        if (root == NULL) {
            return 0;
        }
        int res = findPath(root, sum);
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);
        return res;
    }

private:
    //在以node为根节点的二叉树中，寻找包含node的路径，和为sum，返回这样的路径个数
    int findPath(TreeNode *node, int num) {
        if (node == NULL) {
            return 0;
        }
        int res = 0;
        if (node->val == num) {
            res += 1;
        }
        res += findPath(node->left, num - node->val);
        res += findPath(node->right, num - node->val);
        return res;
    }


    //235. Lowest Common Ancestor of a Binary Search Tree两个节点在二分搜索树的最近公共祖先
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        assert(p != NULL && q != NULL);
        if (root == NULL) {
            return NULL;
        }
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        /*
         * 三种情况：
         * 1.p->val < root->val && q->val > root->val
         * 2.p为祖先
         * 3.q为祖先
         * */
        return root;
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
 * 2.递归
 * 257
 * 113
 * 129
 *
 * 437
 *
 * 3.二叉搜索树
 * 235
 * 98验证二叉搜索树
 * 450删除节点
 * 108将有序数组转换为平衡二分搜索树
 * 230在二分搜索树找第k小元素
 * 236两个节点在二分树的最近公共祖先LCA
 * */