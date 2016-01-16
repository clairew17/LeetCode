//143. Reorder List.cc

#include"../CC/header.h"


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
		slow = slow->next;;
		pre = pre->next;
	}
	//return the node before mid
	//odd: n/2 th node
	//even n/2 -1 th node
	return pre;

}


//reverse linklist
ListNode* Reverse(ListNode *head){
	if(head==NULL)return NULL;
	ListNode *cur = head, *next, *pre = NULL;
	while(cur){
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}
//merge two list in an inverleaving way
void InterleaveMerge(ListNode *head1, ListNode *head2){
	ListNode *p1 = head1, *p2 = head2, *next1, *next2;
	while(p1 && p2){
		//cout << p1->val << ',' << p2->val <<endl;
		next1 = p1->next;
		next2 = p2->next;

		p1->next = p2;
		p2->next = next1;
		
		p2 = next2;
		p1 = next1;
	}
	//return head1;
}


void reorderList(ListNode* head) {
	if(head==NULL || head->next==NULL)return;
	//find the mid point
	ListNode *mid = FindMidLinkList(head);

	//reverse the second part
	ListNode*h2 = Reverse(mid->next);
	mid->next = NULL;

	//interleaving merge
	InterleaveMerge(head, h2);
	
	//if(p2!=NULL)

}


int main(int argc, char *argv[]){
	int len = stoi(argv[1]);
	ListNode* head = GenerateRandomLinkList(len);
	reorderList(head);

	PrintLinkList(head);
	//cout << res->val << endl;

	return 0;
}