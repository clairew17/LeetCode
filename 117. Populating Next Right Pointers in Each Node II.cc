/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
//left 
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

TreeLinkNode *root

class Solution {
public:
    void connect(TreeLinkNode *root) {
        //use dummy node at the left of each level
        TreeLinkNode *dummy = new TreeLinkNode(0);
        auto node = root;
        while(node)
        {
            auto cur = dummy;
            //level traversal
            while(node)
            {
                if(node->left){//append node->left after cur
                    cur->next = node->left;
                    cur = cur->next;
                }
                if(node->right){//append node->right to the list of next level
                    cur->next = node->right;
                    cur = cur->next;
                }
                //traverse to next node of current level
                node = node->next;
            }
            
            //traverse to left most of next level
            node = dummy->next;
            //must set dummy->next to NULL: 
            dummy->next = NULL;
        }
    }
};



int main()
{
    int arr[] = {1,2};
}