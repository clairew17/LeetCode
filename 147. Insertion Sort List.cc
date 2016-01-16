//147. Insertion Sort List.cc
#include"../CC/header.h"

ListNode* insertionSortList(ListNode* head) {
    if(head==NULL || head->next == NULL)return head;
    ListNode*res = new ListNode(INT_MIN), *cur = head, *next;
    
    while(cur){
    	//search from head of sorted linklist
        ListNode *p = res;
        while(p && p->next){
        	//search for the first node whose val > cur->val
        	if(p->next->val > cur->val)break;
            p = p->next;
        }
        //record the next of insert point
        next = p->next;

        //insert cur
        p->next = cur;
        cur = cur->next;
        p->next->next = next;
    }

    return res->next;

}



int main(int argc, char *argv[]){
	int len = stoi(argv[1]);
	ListNode* head = GenerateRandomLinkList(len);
	//ListNode* head2 = GenerateRandomLinkList(len);

	ListNode* sorted = insertionSortList(head);
	PrintLinkList(sorted);

	return 0;
}