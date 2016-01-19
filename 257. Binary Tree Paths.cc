//257. Binary Tree Paths.cc

#include"../CC/Tree.h"

void helper(TreeNode* root, vector<string> &res, string sol)
{
	if(root==NULL)return;
	if(!sol.empty())sol += "->";
	sol += to_string(root->val);

    //store results if it's leaf
	if(root->left == NULL && root->right == NULL){
		res.push_back(sol);
		return;
	}

    //access its children
	if(root->left)helper(root->left, res, sol);
	if(root->right)helper(root->right, res, sol);

	return;

}

vector<string> binaryTreePaths(TreeNode* root) 
{
    vector<string>res;

    helper(root, res, "");
    return res;
}



int main(int argc, char *argv[])
{
	int n = stoi(argv[1]);
	TreeNode *root = CreateTree(n);
	vector<string>res = binaryTreePaths(root);

	cout << "All root-to-leaf paths:\n";
	for(auto v:res)
	{
		cout << v << endl;
	}

	return 0;
}