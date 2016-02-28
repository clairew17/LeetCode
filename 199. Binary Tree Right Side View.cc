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
    void bfs(TreeNode* root, vector<int> &res){
        if(root==NULL)return;
        queue<TreeNode*>q;
        q.push(root);
        int cnt = q.size();
        while(cnt>0){
            cnt--;
            auto p = q.front(); q.pop();
            if(p->left)q.push(p->left);
            if(p->right)q.push(p->right);
            
            if(cnt==0){
                res.push_back(p->val);
                cnt = q.size();
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        bfs(root, res);
        return res;
    }
};