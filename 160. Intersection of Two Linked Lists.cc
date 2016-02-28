//160. Intersection of Two Linked Lists.cc
#include"../CC/header.h"
/*
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    map<ListNode*,int>m;
    if(headA==NULL||headB==NULL)return NULL;
    ListNode *cur = headA;
    while(cur){
        m[cur]++;
        cur=cur->next;
    }
    cur = headB;
    while(cur){
        if(m.find(cur)!=m.end())return cur;
        cur = cur->next;
    }
    return NULL;
    
}*/


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA==NULL||headB==NULL)return NULL;
    ListNode *p1 = headA, *p2 = headB;
    
    if(p1==NULL||p2==NULL)return NULL;

    while(p1 && p2 && p1!=p2){
        p1 = p1->next;
        p2 = p2->next;
        
        if(p1==p2)return p1;
        //when reaching the tail, assign to the head of the other's head
        //the distance to the joint point would be the same after reassignning twice
        if(p1==NULL) p1 = headB;
        if(p2==NULL) p2 = headA;
    }
    return p1;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //TIME: O(n+m) space O(n);
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>visited;
        ListNode *cur = headA;
        while(cur){
            visited.insert(cur);
            cur = cur->next;
        }
        cur = headB;
        while(cur){
            if(visited.find(cur) != visited.end()){
                break;
            }
            cur = cur->next;
        }
        return cur;
    }
};

int main(){
	srand(time(NULL));
	int m = 5, n =2;
	ListNode *headA = GenerateRandomLinkList(m);
	ListNode *headB = GenerateRandomLinkList(n);
	ListNode *res = getIntersectionNode(headA, headB);

	if(res==NULL)cout << "No Intersection!\n";
	else cout << "Intersection at "<< res->val <<endl;

	return 0;
}