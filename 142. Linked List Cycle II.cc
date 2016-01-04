//142. Linked List Cycle II.cc

#include"../CC/header.h"

//return the head of linklist
ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow=head;
    while(fast &&fast->next){
    	fast = fast->next->next;
    	slow = slow->next;
    	if(fast==slow)break;
    }
    if(fast==NULL || fast->next == NULL)return NULL;//no cycle
    fast = head;
    while(fast!=slow){
    	fast = fast->next;
    	slow = slow->next;
    }
    return slow;
}