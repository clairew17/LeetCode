//2. Add Two Numbers.cc

#include"../CC/header.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode *res = new ListNode(0), *cur = res;
    while(l1 || l2 || carry){
        int x = l1?l1->val:0;
        int y = l2?l2->val:0;
        int sum = x+y+carry;
        carry = sum/10;
        cur->next = new ListNode(sum%10);
        cur = cur->next;

        if(l1)l1 = l1->next;
        if(l2)l2 = l2->next;
    }
    return res->next;
}


int main(int argc, char *argv[]){
    int len1 = stoi(argv[1]);
    int len2 = stoi(argv[2]);
    ListNode* head1 = GenerateRandomLinkList(len1);
    ListNode* head2 = GenerateRandomLinkList(len2);

    ListNode *res = addTwoNumbers(head1,head2);
    PrintLinkList(res);
    return 0;
}