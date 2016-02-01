270. Closest Binary Search Tree Value.cc

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
    int closestValue(TreeNode* root, double target) {
        if(root==NULL)return 0;
        int a = root->val;
        TreeNode* node = a<target?root->right:root->left;
        if(!node)return a;
        int b = closestValue(node, target);
        return abs(a-target)<abs(b-target)?a:b;
    }
};


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
    int closestValue(TreeNode* root, double target) {
        if(root==NULL)return -1;
        TreeNode *kid = root->val>target? root->left:root->right;
        if(kid == NULL)return root->val;//no available kid to access 
        
        int value = closestValue(kid, target);
        //compare if result from kid node is valid
        if(abs(value-target) < abs(root->val-target))return value;
        else return root->val;
    }
};