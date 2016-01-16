//109. Convert Sorted List to Binary Search Tree.cc

#include"../CC/Tree.h"


//convert a linklist from star to end 



TreeNode* sortedListToBST(ListNode* head){
	if(head==NULL)return NULL;
	if(head->next == NULL){
		TreeNode* root = new TreeNode(head->val);
		return root;
	}
	ListNode *NodeBeforeMid = FindMidLinkList(head);
	ListNode *mid = NodeBeforeMid->next;
	NodeBeforeMid->next = NULL;

	cout << mid->val <<endl;

	//PrintLinkList(head);
	//PrintLinkList(mid->next);
	TreeNode* root = new TreeNode(mid->val);
	root->left = sortedListToBST(head);
	root->right = sortedListToBST(mid->next);

	return root;
}


int main(int argc, char *argv[]){
	int len = stoi(argv[1]);
	ListNode* head = GenerateRandomLinkList(len);

	TreeNode*root = sortedListToBST(head);

	PrintTree(root);
	//cout << res->val << endl;

	return 0;
}