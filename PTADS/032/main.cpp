#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
	int left, right;
} tree[14];

int main() {
	int n, i;
	cin >> n;
	string l, r;
	bool isRoot[14];
	memset(isRoot, 1, sizeof(isRoot));
	for (i = 0; i < n; i++) {
		cin >> l >> r;
		if (l[0] != '-') {
			tree[i].left = stoi(l);
			isRoot[tree[i].left] = 0;
		} else
			tree[i].left = -1;
		if (r[0] != '-') {
			tree[i].right = stoi(r);
			isRoot[tree[i].right] = 0;
		} else
			tree[i].right = -1;
	}
	//找到根结点
	int root;
	for (i = 0; i < n; i++) {
		if (isRoot[i]) root = i;
	}
	//cout << "根节点: " << root << endl;
	queue<int> q;
	q.push(root);
	vector<int> v;
	while (!q.empty()) {
		int t = q.front();
		//cout << t << ' ';
		q.pop();
		if (tree[t].left == -1 && tree[t].right == -1)
			v.push_back(t);
		if (tree[t].left != -1)
			q.push(tree[t].left);
		if (tree[t].right != -1)
			q.push(tree[t].right);
	}
	//cout << endl;
	for (i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i != v.size() - 1)
			cout << ' ';
	}
	return 0;
}


//03-树2 List Leaves（25 分）
//Given a tree, you are supposed to list all the leaves in the order of top down, and left to right.
//
//Input Specification:
//Each input file contains one test case. For each case, the first line gives a positive integer N (≤10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N?1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.
//
//Output Specification:
//For each test case, print in one line all the leaves' indices in the order of top down, and left to right. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.
//
//Sample Input:
//8
//1 -
//- -
//0 -
//2 7
//- -
//- -
//5 -
//4 6
//Sample Output:
//4 1 5
