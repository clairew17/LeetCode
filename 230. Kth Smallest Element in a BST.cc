//230. Kth Smallest Element in a BST.cc



//inorder tranversal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    
    void InorderTraverse(TreeNode* root, int k, int &val, int &cnt)
    {
        if(root==NULL || cnt==k)return;
        //access left tree
        InorderTraverse(root->left, k, val, cnt);
        if(cnt == k)return;
        
        //access current node 
        cnt++;
        if(cnt == k){
            val=root->val;
            return;
        }
        
        //access right node
        InorderTraverse(root->right, k, val, cnt);
        
    }
    int kthSmallest(TreeNode* root, int k)
    {
        int cnt = 0;
        int val = -1;
        InorderTraverse(root, k, val, cnt);
        return val;
    }
};


//using stack

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>s;
        if(root==NULL)return -1;
        
        //access all left tree
        auto cur = root;
        while(cur)
        {
            s.push(cur);
            cur = cur->left;
        }
        
        while(k>0 && !s.empty())
        {
            auto cur = s.top();s.pop();
            k--;
            if(k==0)return cur->val;
            //access the right child of current node 
            auto r = cur->right;
            while(r){//acces left tree
                s.push(r);
                r = r->left;
            }
        }
        
        return -1;
        
    }
};



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