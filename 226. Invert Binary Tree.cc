226. Invert Binary Tree.cc


//recursion
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)return root;
        TreeNode*left = invertTree(root->left);
        TreeNode*right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)return root;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto p = q.front(); q.pop();
            //swap left & right
            auto r = p->right;
            p->right = p->left;
            p->left = r;
            //access next level
            if(p->left)q.push(p->left);
            if(p->right)q.push(p->right);
        }
        return root;
    }
};