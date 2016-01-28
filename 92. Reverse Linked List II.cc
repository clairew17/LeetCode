//92. Reverse Linked List II.cc

#include"../CC/header.h"

//insert 
// ListNode* reverseFirstN_2(ListNode* head, int n){
//     ListNode *dummy = new ListNode(0); dummy->next = head;
//     ListNode *pre = dummy, *cur = dummy;
//     while(cur && n--){
//         ListNode *p = cur->next;
//         cur->next = p->next;
//         //insert right after pre
//         p->next = pre->next;
//         pre->next = p;
//     }
//     return dummy->next;
// }

//reverse the first n nodes
ListNode* reverseFirstN(ListNode* head, int n){
    ListNode*cur = head, *next, *pre=NULL, *tail = head;
    while(cur&&n-->0){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    tail->next = cur;
    return pre;
}

//reverse from mth to nth node
ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(n<1 || m<1){
        throw invalid_argument("invalid m/n!\n");
    }
    n = n-m+1;
    if(n<=0)return head;
    
    ListNode *dummy = new ListNode(0); dummy->next = head;
    ListNode *pre = dummy;
    
    while(--m)pre=pre->next;
    //reverse from cur
    ListNode *cur = pre->next;
    pre->next = reverseFirstN(cur, n);
    return dummy->next;
}

int main(int argc, char *argv[]){
	int len = stoi(argv[1]);
	int m = stoi(argv[2]), n =stoi(argv[3]);
	ListNode* head = GenerateRandomLinkList(len);

    try{
	   ListNode *res = reverseBetween(head, m, n);
	   PrintLinkList(res);
       return 0;
    }catch (invalid_argument &e){
        cout << e.what() << endl;
    }

}