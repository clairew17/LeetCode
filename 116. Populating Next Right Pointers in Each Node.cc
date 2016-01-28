/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)return;
        auto node = root;
        while(node)
        {
            //store the left most node
            auto leftmost = node->left?node->left:node->right;
            //update children of current level
            while(node)
            {
                //update childrend of node
                if(node->left)node->left->next = node->right;
                if(node->right && node->next) node->right->next = node->next->left;
                //level traversal
                node = node->next;
            }
            node = leftmost;
        }
    }
};