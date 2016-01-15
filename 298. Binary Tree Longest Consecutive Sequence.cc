298. Binary Tree Longest Consecutive Sequence.cc
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
    int longestConsecutive(TreeNode* root) {
        return helper(root,NULL,0);
    }
    
    int helper(TreeNode* root, TreeNode*parent, int len){
        if(root==NULL)return len;
        //increment the len if consequetive
        if(parent && root->val == parent->val+1)len = len+1;
        else len = 1;//reset len
        
        return max(len, max(helper(root->left,root,len),helper(root->right,root,len)));
    }
    
};