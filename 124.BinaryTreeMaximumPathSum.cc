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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int maxToRoot(TreeNode *root, int &res) {
        if (!root) return 0;
        //dfs
        //maximal path sum including left child
        int l = maxToRoot(root->left, res);
        int r = maxToRoot(root->right, res);
        
        if (l < 0) l = 0;
        if (r < 0) r = 0;
        //path including root
        if (l + r + root->val > res)
            res = l + r + root->val;
        //return max sum including root
        return root->val += max(l, r);
    }
public:
    int maxPathSum(TreeNode *root) {
        int max = INT_MIN;
        maxToRoot(root, max);
        return max;
    }
};