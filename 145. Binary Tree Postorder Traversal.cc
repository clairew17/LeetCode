//145. Binary Tree Postorder Traversal.cc
#include"../CC/Tree.h"
//recursive way
void helper(TreeNode* root, vector<int> &res){
    if(root==NULL)return;
    helper(root->left,res);
    helper(root->right,res);
    res.push_back(root->val);
}
vector<int> postorderTraversalRecurse(TreeNode* root) {
        vector<int>res;
        helper(root,res);
        return res;
}



class Solution {//recursion
public:
    void helper(TreeNode* root, vector<int>&res){
        if(root==NULL)return;
        helper(root->left, res);
        helper(root->right, res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        helper(root, res);
        return res;
    }
};

class Solution {//iterative using stack
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        vector<int>res;
        if(root==NULL)return res;
        s.push(root);
        //use stack to access the right path first
        while(!s.empty()){
            //access stack.top: the right most node
            auto p = s.top();s.pop();
            res.push_back(p->val);
            if(p->left)s.push(p->left);
            if(p->right)s.push(p->right);
        }
        //reverse to get post order
        reverse(res.begin(),res.end());
        return res;
    }
};
int main(){
	int n = 5;
	TreeNode* root = CreateTree(n);
	vector<int>res = postorderTraversal(root);
	PrintVector(res);
	return 0;
}
//iterative 