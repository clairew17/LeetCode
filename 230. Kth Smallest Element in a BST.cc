//230. Kth Smallest Element in a BST.cc



//inorder tranversal
int kthSmallest(TreeNode* root, int k) {
        int kVal;
        int count = 0;
        inorderTraverse(root,k, kVal, count);
        return kVal;
    }
    void inorderTraverse(TreeNode* root, int k, int &kVal, int &count){
        if(root==NULL || count==k)return;
        if(root->left)inorderTraverse(root->left, k, kVal, count);
        if(count == k)return;
        
        //add root
        count++;
        if(count == k){
            kVal = root->val;
            return;
        }
        
        if(root->right)inorderTraverse(root->right, k, kVal, count);
}


//using stack

int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*>s;
    if(root==NULL)return -1;
    TreeNode*node=root;
    while(node){
        s.push(node);
        node = node->left;
    }
    while(k>0 && !s.empty()){
        node = s.top();s.pop();
        k--;
        if(k==0)return node->val;
        
        //access the right tree
        TreeNode *r=node->right;
        while(r){
            s.push(r);
            r = r->left;
        }
    }
    
    return -1;
}



int kthSmallest(TreeNode* root, int k) {
        //inorder tranversal
        TreeNode*node = root;
        stack<TreeNode*>s;
        while(node || !s.empty()){
            //access left tree
            while(node){
                s.push(node);
                node = node->left;
            }
            //access stack top
            node = s.top();s.pop();
            k--;
            if(k==0)return node->val;
            
            //access right tree
            node = node->right;
        }
        return -1;
    }