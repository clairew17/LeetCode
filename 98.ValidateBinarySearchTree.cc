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
    //given the root falls in (min_val, max_val)
    bool helper(TreeNode* root, long min_val, long max_val)
    {
        if(root==NULL)return true;
        //check if current node falls in the range
        if(root->val <= min_val || root->val >=max_val)return false;
        //node on the left path should be smaller than root->val: shrink the right boundary of left child
        //right's value should be > root->val; shrink the left boundary 
        return helper(root->left, min_val, root->val) && helper(root->right, root->val, max_val);
        
    }
    bool isValidBST(TreeNode* root) {
        //use LONG type for case of root_val == INT_MIN or INT_MAX
        return helper(root, LONG_MIN, LONG_MAX);
    }
};



class Solution {
public:
    //previous node in inorder traversal
    TreeNode *prev = NULL;
    //inorder traversal, iterative
    bool isValidBST(TreeNode* root) {
        //if(root==NULL)return true;
        if(root){
            if(isValidBST(root->left)==false)return false;
            if(prev!=NULL && root->val <= prev->val)return false;
            prev = root;
            return isValidBST(root->right);
        }
        return true;
    }
};