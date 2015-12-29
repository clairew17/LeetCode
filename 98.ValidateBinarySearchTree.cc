//98.ValidateBinarySearchTree.cc
/*

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
#include"../CC/header.h"

bool isBST(TreeNode* root, long min, long max){
	if(root==NULL)return true;
	if(root->val <= min || root->val >= max)return false;
	return isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
}

bool isValidBST(TreeNode* root){
	if(root==NULL)return true;
	return isBST(root, LONG_MIN, LONG_MAX);
}
