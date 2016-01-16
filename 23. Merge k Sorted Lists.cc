//23. Merge k Sorted Lists.cc
struct compare{
    bool operator()(ListNode*l1, ListNode*l2)
    {
        return l1->val > l2->val;
        //ascending order
    }
};


ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare>pq;
    for(auto l:lists){
        if(l)pq.push(l);
    }
    if(pq.empty())return NULL;
    ListNode*res = new ListNode(0), *cur=res;
    
    while(!pq.empty()){
        //insert node of pq top
        auto temp = pq.top();pq.pop();
        cur->next = temp;
        cur = cur->next;
        
        //restore the remaining part of list
        auto next = temp->next;
        if(next)pq.push(next);
    }
    return res->next;
}