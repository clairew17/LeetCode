//86. Partition List.cc


ListNode* partition(ListNode* head, int x) {
    ListNode* less = new ListNode(0), *p1 = less;
    ListNode* great = new ListNode(0), *p2 = great;
    ListNode* cur = head; 
    while(cur){
        if(cur->val < x){
            p1->next = cur;
            p1 = p1->next;
        }else{
            p2->next = cur;
            p2 = p2->next;
        }
        cur = cur->next;
    }
    p1->next = great->next;
    p2->next = NULL;
    
    return less->next;
}