//105. Construct BT from Preorder and Inorder.cc


TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

TreeNode* create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
    if(ps > pe){
        return nullptr;
    }
    TreeNode* node = new TreeNode(preorder[ps]);
    int pos;


    for(int i = is; i <= ie; i++){
        if(inorder[i] == node->val){
            //find the node in inorder array
            //after pos: right child
            //before pos: left child
            pos = i;
            break;
        }
    }


    node->left = create(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);//left tree
    node->right = create(preorder, inorder, pe - (ie - pos - 1), pe, pos + 1, ie);//right tree
    return node;
}