//203. Remove Linked List Elements.cc

ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0), *pre = dummy, *cur = head;
    while(cur){
        while(cur && cur->val == val){//bypass all nodes whose val==val
            cur=cur->next;
        }
        pre->next = cur;
        pre = cur;
        //remember to check the valid status of cur
        if(cur)cur = cur->next;
    }
    //pre->next = NULL;
    return dummy->next;
}