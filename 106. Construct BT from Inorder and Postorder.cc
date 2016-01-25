//106. Construct BT from Inorder and Postorder.cc


TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe){
    if(ps>pe)return NULL;
    TreeNode *node = new TreeNode(postorder[pe]);
    int pos;
    for(int i=is;i<=ie;i++){
        if(inorder[i]==postorder[pe]){
            pos = i;
            break;
        }
    }
    
    node->left = helper(inorder, postorder, is, pos-1, ps, ps+pos-1-is);
    node->right = helper(inorder, postorder, pos+1, ie, pe-ie+pos, pe-1);
    
    return node;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return helper(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
}