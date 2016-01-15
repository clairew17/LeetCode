//285.InorderSuccessor.cc

#include"header.h"

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
	if(root==NULL || p==NULL)return NULL;
	TreeNode *node = root, *suc;
	while(node){
		if(node->val <= p->val){//find node's val >p
			node = node->right;
		}else{
			suc = node;
			node = node->left;//find the left most
		}
	}
	return suc;
}