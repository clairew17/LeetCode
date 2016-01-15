23. Merge k Sorted Lists.cc
struct compare{
    bool operator()(const ListNode*l1, const ListNode *l2){
        return l1->val > l2->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;
        for(auto l:lists){
            if(l)pq.push(l);//need to check the status of l
        }
        if(pq.empty())return NULL;
        ListNode *res = pq.top();pq.pop();
        if(res->next)pq.push(res->next);
        ListNode *tail = res;
        while(!pq.empty()){
            tail->next = pq.top();pq.pop();
            tail = tail->next;
            if(tail->next)pq.push(tail->next);
        }
        return res;
    }