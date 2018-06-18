struct TreeNode{
	int value;
	TreeNode *left;
	TreeNode *right;
};
class Solution{
public:
    int minDepth(TreeNode *root){
    	if(root==0){
    		return 0;
		}
		if(root->left){
			if(root->right){
				return min(minDepth(root->left),minDepth(root->right))+1;
			}else{
				return minDepth(root->left)+1;
			}
		}else if(root->right){
			return minDepth(root->right)+1;
		}else{
			return 1;
		}
    }
}
