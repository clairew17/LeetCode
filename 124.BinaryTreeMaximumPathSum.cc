//124.BinaryTreeMaximumPathSum.cc

#inlcude"header.h"

int MaxToRoot(TreeNode* root, int &res){
	if(root==NULL)return 0;
	int left_max = MaxToRoot(root->left, res);
	int right_max = MaxToRoot(root->right, res);
	res = max(res, right_max+left_max+root->val);
	//excluding current root; max root including current root
	int MaxToCur = max(0, max(left_max, right_max)+root->val);
	return MaxToCur;
}

int maxPathSum(TreeNode* root) {
	int MaxSum = INT_MIN;
	MaxToRoot(root, MaxSum);
	return MaxSum;
}