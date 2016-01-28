//24. Swap Nodes in Pairs.cc
#include"../CC/header.h"

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next==NULL)return head;
        ListNode*temp = head->next->next;
        ListNode *newhead = head->next;
        
        newhead->next = head;
        head->next = swapPairs(temp);
        
        return newhead;
    }
};

int main(int argc, char *argv[]){
    int len = stoi(argv[1]);
    
    ListNode* head = GenerateRandomLinkList(len);

    ListNode *res = swapPairs(head);
    PrintLinkList(res);
    return 0;
}