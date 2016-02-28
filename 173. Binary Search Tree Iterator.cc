/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*>Nodes;//store the unaccessed node inorder 
    
    BSTIterator(TreeNode *root) {
        TreeNode *p = root;
        while(p){//left path including root
            Nodes.push(p);
            p = p->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {//all the next nodes are in the stack
        if(Nodes.empty())return false;
        else return true;
    }

    /** @return the next smallest number */
    int next() {
        if(hasNext()){
            //get the next smallest from the stack
            int result = Nodes.top()->val;
            TreeNode *r = Nodes.top()->right;
            Nodes.pop();
            while(r){//push right child and its left path to traverse inorder
                Nodes.push(r);
                r = r->left;
            }
            return result;
        }else return -1;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */