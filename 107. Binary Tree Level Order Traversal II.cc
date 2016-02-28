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
    void dfs(vector<vector<int>>&res, TreeNode* root, int level){
        if(root == NULL)return;
        
        if(res.size() <= level){
            res.push_back({});
        }
        res[level].push_back(root->val);
        
        dfs(res, root->left, level+1);
        dfs(res, root->right, level+1);
    }
    void bfs(vector<vector<int>>&res, TreeNode* root){
        if(root == NULL)return;
        queue<TreeNode *>q;
        q.push(root);
        int cnt = q.size();
        res.push_back({});
        int level = 0;
        while(cnt>0){
            cnt--;
            auto p = q.front();q.pop();
            res[level].push_back(p->val);
            if(p->left)q.push(p->left);
            if(p->right)q.push(p->right);
            if(cnt==0){
                cnt = q.size();
                level++;
                if(cnt>0)res.push_back({});
            }
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;
        //dfs(res, root, 0);
        bfs(res, root);
        reverse(res.begin(), res.end());
        return res;
    }
};