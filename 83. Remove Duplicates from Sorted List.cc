//83. Remove Duplicates from Sorted List.cc

//O(n) space
ListNode* deleteDuplicates(ListNode* head) {
    map<int,int>m;
    ListNode *dummy = new ListNode(0), *pre = dummy, *cur=head;
    while(cur){
        if(m.find(cur->val)==m.end()){
            pre->next = cur;
            pre = pre->next;
        }
        m[cur->val]++;
        cur = cur->next;
    }
    pre->next = NULL;
    return dummy->next;
}