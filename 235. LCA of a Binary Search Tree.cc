//235. LCA a Binary Search Tree.cc

//method1
bool Cover(TreeNode* root, TreeNode* p)//if root covers node p
{
    if(root==NULL)return false;
    if(root==p || p == NULL)return true;
    return (Cover(root->left,p) ||Cover(root->right,p)); 
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root==NULL)return NULL;
    bool leftCoverP = Cover(root->left, p);
    bool leftCoverQ = Cover(root->left, q);
    bool rightCoverP = Cover(root->right, p);
    bool rightCoverQ = Cover(root->right, q);
    
    if(leftCoverP && leftCoverQ)return lowestCommonAncestor(root->left, p, q);
    if(rightCoverP && rightCoverQ)return lowestCommonAncestor(root->right, p, q);
    return root;
}

//recursion

//recursive
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return root;
        if(p==NULL && q==NULL)return root;
        if(p==NULL && q)return q;
        if(q==NULL && p)return p;
        
        if(p->val < root->val && q->val < root->val)return lowestCommonAncestor(root->left, p, q);
        if(p->val > root->val && q->val > root->val)return lowestCommonAncestor(root->right, p, q);
        return root;
    }

    //iterative
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return root;
        if(p==NULL && q==NULL)return root;
        if(p==NULL && q)return q;
        if(q==NULL && p)return p;
        
        TreeNode* cur = root;
        while(cur){
            if(p->val < cur->val && q->val < cur->val)
            {
                cur = cur->left;   
            }else if(p->val > cur->val && q->val > cur->val){
                cur = cur->right;
            }else return cur;
        }
        return cur;
    }