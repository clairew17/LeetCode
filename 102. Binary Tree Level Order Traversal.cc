102. Binary Tree Level Order Traversal.cc


class Solution {
public:
//recursion methods
    void helper(map<int, vector<int>>&mm, TreeNode*node, int level){
        if(node==NULL)return;
        mm[level].push_back(node->val);
        if(node->left)helper(mm, node->left, level+1);
        if(node->right)helper(mm, node->right, level+1);
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL)return res;
        
        map<int, vector<int>>mm;
        helper(mm, root, 0);
        for(auto m:mm){
            res.push_back(m.second);
        }
        return res;
    }
};