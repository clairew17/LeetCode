//113. Path Sum II.cc


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
public:
    void helper(TreeNode* root, int sum, vector<vector<int>>&res, vector<int>&sol)
        {
            if(root==NULL)return;
            
            sol.push_back(root->val);
            int temp = sum - root->val;
            
            //leaf
            if( temp == 0 && root->left==NULL && root->right==NULL)//leaf && path sums to target value
            {
                res.push_back(sol);
            }else{
                //left tree
                helper(root->left, temp, res, sol);
                //right tree
                helper(root->right, temp, res, sol);
            }
            //recover
            sol.pop_back();
        }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>res;
        vector<int>sol;
        helper(root, sum, res, sol);
        return res;
    }
};