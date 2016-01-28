class Solution {//recursion
public:
    void helper(TreeNode* root, vector<int>&res){
        if(root==NULL)return;
        res.push_back(root->val);
        helper(root->left, res);
        helper(root->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        helper(root, res);
        return res;
    }
};


class Solution {//non-recursion
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root==NULL)return res;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            //access current node
            auto p = s.top(); s.pop();
            res.push_back(p->val);
            //push right before left to ensure preorder
            if(p->right)s.push(p->right);
            if(p->left)s.push(p->left);
        }
        return res;

    }
};