82. Remove Duplicates from Sorted List II.cc

ListNode* deleteDuplicates(ListNode* head) {
    ListNode *dummy = new ListNode(0);
    ListNode *cur = head, *pre = dummy;
    while(cur){
    	if(cur->next && cur->val == cur->next->val){//exist dup
    		int value = cur->val;
    		while(cur && cur->val == value)cur = cur->next;
    	}else{
    		pre->next = cur;
    		pre = pre->next;
    		cur = cur->next;
    	}
    }
    pre->next= NULL;
    return dummy->next;
}