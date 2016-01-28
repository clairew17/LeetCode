
#include"../CC/Tree.h"


class Solution {//recursion
public:
    void helper(TreeNode* root, vector<int>&res){
        if(root==NULL)return;
        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        helper(root, res);
        return res;
    }
};


class Solution {//iterative method
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root==NULL)return res;
        stack<TreeNode*>s;
        //access the left path
        auto p = root;
        while(p){
            s.push(p);
            p = p->left;
        }
        
        while(!s.empty()){
        	//access the left and mid node
            auto node = s.top();s.pop();
            res.push_back(node->val);
            //access the right tree of current node
            auto r = node->right;
            while(r){
                s.push(r);
                r = r->left;
            }
        }
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