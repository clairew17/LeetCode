//92. Reverse Linked List II.cc

#include"../CC/header.h"
//reverse from mth to nth node
ListNode* reverseBetween(ListNode* head, int m, int n) {
    n = n-m;
    if(n<=0)return head;
    
    ListNode *dummy = new ListNode(0); dummy->next = head;
    ListNode *pre = dummy;
    
    while(--m)pre=pre->next;
    
    ListNode *cur = pre->next;
    
    //reverse from nth node
    while(n--){
        ListNode *p = cur->next;
        cur->next = p->next;
        
        //insert after pre
        p->next = pre->next;
        pre->next = p;
    }
    return dummy->next;
}

int main(int argc, char *argv[]){
	int len = stoi(argv[1]);
	int m = stoi(argv[2]), n =stoi(argv[3]);
	ListNode* head = GenerateRandomLinkList(len);

	ListNode *res = reverseBetween(head, m, n);
	PrintLinkList(res);
	return 0;
}