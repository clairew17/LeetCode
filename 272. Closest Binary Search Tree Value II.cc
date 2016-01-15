//272. Closest Binary Search Tree Value II.cc
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include"../CC/Tree.h"
void dfs(TreeNode* root, double target, int k, priority_queue<pair<double,int>>&pq){
    if(!root)return;
    pq.push(make_pair(fabs(target-double(root->val)), root->val));
    if(pq.size()>k)pq.pop();//pop top
    dfs(root->left, target, k, pq);
    dfs(root->right, target, k, pq);
}
vector<int> closestKValues(TreeNode* root, double target, int k) {
    priority_queue<pair<double,int>>pq;//res:val, sorted by the diff
    vector<int>res;
    dfs(root, target, k, pq);
    while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}
int main(){
    int n = 1;
    TreeNode*root =  new TreeNode(1);//CreateTree(n);
    double target = 0; int k = 1;
    vector<int>res = closestKValues(root, target, k);
    PrintVector(res);
    return 0;
}