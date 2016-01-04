//297. Serialize and Deserialize Binary Tree.cc

#include"../CC/Tree.h"


string serialize(TreeNode* root) {
	//BFS traversal
    string str;
    queue<TreeNode*> node_q;
    node_q.push(root);

    TreeNode* cur;
    while(!node_q.empty()){
    	cur = node_q.front();
    	node_q.pop();

    	if(cur==NULL){
    		str += "#,";
    	}else{
    		str += (to_string(cur->val)+",");
    		node_q.push(cur->left);
    		node_q.push(cur->right);
    	}
    }

    cout <<"Serialized Tree:\t"<< str << endl;
    return str;
}
TreeNode* deserialize(string str){
	TreeNode *root = NULL, **cur;
	if(str.size()==0)return 0;
	queue<TreeNode**>node_q;
	node_q.push(&root);
	auto found = str.find_first_of(',');
	int val; 
	while(found != string::npos){
		cur = node_q.front();
		node_q.pop();
		if(str[0]=='#'){
			str = str.substr(2);
		}else{
			val = stoi(str.substr(0,found));
			str = str.substr(found+1);
			*cur = new TreeNode(val);
			node_q.push(&((*cur)->left));
			node_q.push(&((*cur)->right));

		}
		found = str.find_first_of(',');
	}
	return root;

}

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