//148. Sort List.cc
#include"../CC/header.h"
/*
Sort a linked list in O(n log n) time using constant space complexity.

*/

//return the node before mid point of linklist
ListNode* FindMidLinkList(ListNode*head){

	ListNode *slow = head, *fast = head, *pre = head;
	while(fast && fast->next){
		pre = slow;
		fast = fast->next->next;
		slow = slow->next;
	}

	if(fast==NULL){//even number of node 
		//do nothing
	}else{//odd number of node
		slow = slow->next;
	}
	//return the node before mid
	//odd: n/2 th node
	//even n/2 -1 th node
	return pre;

}

//merge two sorted list
ListNode* mergeList(ListNode* head1, ListNode* head2){
	ListNode* dummy = new ListNode(0), *cur = dummy;
	while(head1 && head2){
		if(head1->val < head2->val){
			cur->next = head1;
			head1 = head1->next;
		}else{
			cur->next = head2;
			head2 = head2->next;
		}
		cur = cur->next;
	}

	if(head1==NULL)cur->next = head2;
	if(head2==NULL)cur->next = head1;
	return dummy->next;
}



//merge sort two lists
ListNode* sortList(ListNode* head) {
	//case with <= 1 element
	if(head==NULL || head->next == NULL)return head;

	//find the mid point
	ListNode *mid = FindMidLinkList(head);

	//sort two parts
	ListNode *h2 = sortList(mid->next);
	mid->next = NULL;
	ListNode *h1 = sortList(head);

	//merge two sorted list
	ListNode*res = mergeList(h1, h2);
	return res;
}



int main(int argc, char *argv[]){
	int len = stoi(argv[1]);
	ListNode* head = GenerateRandomLinkList(len);
	//ListNode* head2 = GenerateRandomLinkList(len);

	ListNode* sorted = sortList(head);
	PrintLinkList(sorted);

	return 0;
}