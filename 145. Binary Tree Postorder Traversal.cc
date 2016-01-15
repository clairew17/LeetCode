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


vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> nodeStack;
    vector<int>res;
    if(root==NULL)return res;
    nodeStack.push(root);
    while(!nodeStack.empty()){
        TreeNode *node = nodeStack.top();
        res.push_back(node->val);
        nodeStack.pop();

        if(node->left)nodeStack.push(node->left);
        if(node->right)nodeStack.push(node->right);

    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
	int n = 5;
	TreeNode* root = CreateTree(n);
	vector<int>res = postorderTraversal(root);
	PrintVector(res);
	return 0;
}
//iterative 