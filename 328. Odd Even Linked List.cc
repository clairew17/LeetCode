//328. Odd Even Linked List.cc


ListNode* oddEvenList(ListNode* head) {
    if(head==NULL || head->next==NULL)return head;
    ListNode *odd = head, *even = head->next, *p1 = odd, *p2 = even, *cur = even->next;
    int flag = 1;
    while(cur){
        if(flag){
            p1->next = cur;
            p1 = p1->next;
        }else{
            p2->next = cur;
            p2 = p2->next;
        }
        cur = cur->next;
        flag = 1-flag;
    }
    p2->next = NULL;
    p1->next = even;
    return odd;
}