#include<iostream>
#include<cstdio>
using namespace std;
int n;
char pre[50];
char mid[50];

struct TreeNode{
  char data;
  TreeNode* left;
  TreeNode* right;
};

TreeNode* buildTree(int root, int start, int end) {
    if(start > end) return NULL;
    int i = start;
    while(i < end && mid[i] != pre[root]) i++;
    TreeNode* t = new TreeNode();
    t->left = buildTree(root + 1, start, i - 1);
    t->right = buildTree(root + 1 + i - start, i + 1, end);
    t->data = pre[root];
    return t;
}

int high(TreeNode* t){
    if(!t) return 0;
    int lh = high(t->left);
    int rh = high(t->right);
    if(lh > rh) return ++lh;
    return ++rh;
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>pre[i];
  }
  for(int i=0;i<n;i++){
    cin>>mid[i];
  }
  TreeNode* bt=buildTree(0,0,n);
  cout<<high(bt)<<endl;
  return 0;
}
