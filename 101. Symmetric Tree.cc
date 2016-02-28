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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode *p1, TreeNode *p2){
        if(p1==NULL && p2==NULL)return true;
        if(p1 && p2){
            if(p1->val != p2->val)return false;
            return helper(p1->left, p2->right) && helper(p1->right, p2->left);
        }
        return false;
    }
};