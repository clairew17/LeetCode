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
        return helper(root->left,root->right);
    }
    bool helper(TreeNode* node1, TreeNode* node2){
        if(node1==NULL && node2==NULL)return true;
        
        if(node1 && node2 && node1->val == node2->val){
            //compare the left child of node1 with right of node2
            return helper(node1->left,node2->right) && helper(node1->right, node2->left);
        }
        
        return false;
    }
};