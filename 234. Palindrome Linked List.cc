//234. Palindrome Linked List.cc
#include"../CC/header.h"

//O(N)TIME AND O(N)space
bool isPalindrome(ListNode* head) {
    if(head==NULL)return true;
    stack<int>s;
    ListNode *slow = head, *fast = head, *pre = head;
    //find the mid node
   	while(fast && fast->next){
   		s.push(slow->val);
		pre = slow;
		fast = fast->next->next;
		slow = slow->next;
	}
	if(fast==NULL){//even number of node 
		//do nothing
	}else{//odd number of node
		slow = slow->next;
	}

	while(slow){
		if(s.empty() || s.top() != slow->val)return false;
		slow = slow->next;
		s.pop();
	}
    //compre 

    return s.empty();
}

//reverse the second half list

    bool isPalindrome(ListNode* head) {
    if(head==NULL)return true;

    ListNode *slow = head, *fast = head, *pre = head;
    //find the mid node
   	while(fast && fast->next){
		pre = slow;
		fast = fast->next->next;
		slow = slow->next;
	}
	pre->next = NULL;

	if(fast==NULL){//even number of node 
		//do nothing
	}else{//odd number of node
		slow = slow->next;
		if(slow==NULL)return true;
	}

    //cout << pre->val << '\t' << slow->val <<endl;
    
	ListNode *ReversedSecondHalf = Reverse(slow);
	
	ListNode *p2 = ReversedSecondHalf, *p1 = head; 
	while(p1 && p2){
	    //cout << p1->val << ','<<p2->val<<endl;
		if(p1->val != p2->val)return false;
		p1 = p1->next; 
		p2 = p2->next;
	}

	return (p1==NULL && p2==NULL);

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



int main(int argc, char *argv[]){
	int len = stoi(argv[1]);
	ListNode* head = GenerateRandomLinkList(len);
	ListNode* mid = FindMidLinkList(head);

	cout << "Mid Node is: "<< mid->val<<endl;

	return 0;
}