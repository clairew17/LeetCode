//24. Swap Nodes in Pairs.cc
#include"../CC/header.h"

ListNode* swapPairs(ListNode* head){
	if(head==NULL || head->next == NULL)return head;
	auto new_head = head->next;
	auto temp = head->next->next;
	new_head->next = head;

	head->next = swapPairs(temp);
	return new_head;
}

int main(int argc, char *argv[]){
    int len = stoi(argv[1]);
    
    ListNode* head = GenerateRandomLinkList(len);

    ListNode *res = swapPairs(head);
    PrintLinkList(res);
    return 0;
}