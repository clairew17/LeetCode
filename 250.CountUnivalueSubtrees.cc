//250.CountUnivalueSubtrees.cc
#include"../CC/header.h"
#include"Tree.h"



int countUnivalSubtrees(TreeNode* root) {
    int count = 0;
    countUnivalSubtrees(root, count);
    return count;
}

bool countUnivalSubtrees(TreeNode* root, int &count){
    if(root==NULL)return true;
    bool isLeftUnival = countUnivalSubtrees(root->left, count);
    bool isRightUnival = countUnivalSubtrees(root->right, count);
    if(
        isLeftUnival && isRightUnival
        && (root->left==NULL || root->left->val == root->val)
        && (root->right==NULL || root->right->val == root->val)
    ){
        count++;
        return true;
    }
    return false;
}

int main(){
    int arr[] = {5,5,5,5,5,null,5};
    int n = ARRAY_SIZE(arr);
    vector<int>vec = Arr2Vec(arr,n);
    PrintVector(vec);
    TreeNode* root = MiniBinaryTree(vec);
    PrintTree(root);
}
