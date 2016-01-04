#include"../CC/header.h"

//return true if a linklist has cycle
bool hasCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while(fast && fast->next){
    	fast = fast->next->next;
    	slow = slow->next;
    	if(fast==slow)return true;
    }
    return false;
}

int main(){
	return 0;
}