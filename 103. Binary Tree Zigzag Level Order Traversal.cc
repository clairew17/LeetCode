//103. Binary Tree Zigzag Level Order Traversal.cc


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL)return res;
        vector<int>row;
        
        //BFS using queue
        queue<TreeNode*>q;
        q.push(root);
        
        int count = 1;
        int right2left = 0;//from left to right
        
        while(count>0){
            count--;
            
            TreeNode* node = q.front(); q.pop();
    
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
            
            row.push_back(node->val);
            
            if(count==0){
                if(right2left==1)//selectively reverse the order
                    reverse(row.begin(),row.end());
                //reverse direction of next level
                right2left = 1-right2left;
                //store result
                res.push_back(row);
                row.clear();
                //node #of next level
                count = q.size();
            }
        }
        return res;
    }
};