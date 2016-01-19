//236. Lowest Common Ancestor of a Binary Tree.cc


//recursive
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if(left==NULL)return right;
    if(right==NULL)return left;
    if(left && right)return root;
}

