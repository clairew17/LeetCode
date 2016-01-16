//61. Rotate List.cc

int getLength(ListNode* head){
    int len = 0;
    ListNode*cur = head;
    while(cur){
        len++;
        cur = cur->next;
    }
    return len;
}

ListNode* rotateRight(ListNode* head, int k){
    
    
    int len = getLength(head);if(len>0)k = k%len;
    if(!head || !head->next || k==0)return head;
    
    //fast is k nodes before slow
    ListNode *fast= head, *slow = head;
    while(k--){
        fast = fast->next==NULL?head:fast->next;
    }
    
    //move slow to the begin of rotates node
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    
    //cout<< slow->val <<endl;
    
    ListNode *newHead = slow->next;
    slow->next = NULL;
    fast = newHead;
    while(fast->next)fast=fast->next;
    fast->next = head;
    return newHead;
}