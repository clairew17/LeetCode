//314. Binary Tree Vertical Order Traversal.cc


class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>>res;
        map<int, vector<int>>m;
        //BFS use queue
        queue<pair<int, TreeNode*>>q;
        //helper(root, m, 0);
        if(root==NULL)return res;
        q.push(make_pair(0,root));
        while(!q.empty()){
            int level = q.front().first;
            TreeNode *node = q.front().second;
            q.pop();
            m[level].push_back(node->val);
            
            if(node->left){
                q.push(make_pair(level-1, node->left));
            }
            if(node->right){
                q.push(make_pair(level+1, node->right));
            }
            
        }
        
        
        for(auto v:m){
            res.push_back(v.second);
        }
        return res;
    }
    //recursion: DFS
    void helper(TreeNode* root, map<int, vector<int>> &m, int level){
        if(root==NULL)return;
        m[level].push_back(root->val);
        helper(root->left, m, level-1);
        helper(root->right, m, level+1);
        return;
    }
};