156. Binary Tree Upside Down.cc
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root || !root->left)return root;
        TreeNode* cur_left = root->left;
        TreeNode* cur_right = root->right;
        //reverse left tree
        TreeNode* new_root = upsideDownBinaryTree(cur_left);
        //reverse current tree
        cur_left->right = root;
        cur_left->left = cur_right;
        root->left = NULL;root->right = NULL;
        return new_root;
    }
};