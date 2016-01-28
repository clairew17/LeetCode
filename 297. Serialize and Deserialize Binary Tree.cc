//297. Serialize and Deserialize Binary Tree.cc

#include"../CC/Tree.h"
/*

297. Serialize and Deserialize Binary Tree




*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    // use BFS, if node is not NULL "val,"; else add "#,"
    string serialize(TreeNode* root) {
        string res;
        //if(root==NULL)return res;
        
        queue<TreeNode*>q;
        q.push(root);
        int cnt = q.size();
        
        while(cnt>0)
        {
            cnt--;
            auto node = q.front();q.pop();
            if(node != NULL){
                res += to_string(node->val)+',';
                q.push(node->left);
                q.push(node->right);
            }else{
                res += "#,";
            }
            
            if(cnt==0)
            {
                cnt = q.size();
            }
        }
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string str){
        cout << str << endl;
	    TreeNode *root = NULL;
	    queue<TreeNode**>q;
	    q.push(&root);
	    
	    
        auto found = str.find_first_of(',');
        while(found != string::npos)
        {
            auto cur = q.front();q.pop();
            if(str[0]!='#')
            {
                int x = stoi(str.substr(0, found));
                *cur = new TreeNode(x);
                q.push(&((*cur)->left));
                q.push(&((*cur)->right));
            }
            str = str.substr(found+1);
            found = str.find_first_of(',');
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(){
	srand(time(NULL));
	int n = 5;
	//TreeNode *root =  CreateTree(n);
	//string str = serialize(root);
	cout <<"Deserialized Tree:\t";
	string str1 = "6,1,8,#,5,#,8,#,#,#,#,";
	TreeNode *de_root =  deserialize(str1);
	PrintTree(de_root);
	cout << endl;


	string str = serialize(de_root);

	return 0;
}