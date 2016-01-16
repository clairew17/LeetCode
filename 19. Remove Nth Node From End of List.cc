//19. Remove Nth Node From End of List.cc

#include"../CC/header.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *res = new ListNode(0);
	res->next = head;
	//find the node before the nth node
	auto fast = head, slow = res;

	//fast is n nodes ahead of slow
	while(n--){
		if(fast==NULL)return head;
		fast = fast->next;
	}
	//if(fast)cout << fast->val << endl;

	//find the Nth node from end
	while(fast){
		fast = fast->next;
		slow = slow->next;
	}
	//cout << slow->val << endl;
	//delete node
	if(slow->next)slow->next = slow->next->next;

	return res->next;

}


int main(int argc, char *argv[]){
    int len = stoi(argv[1]);
    int k = stoi(argv[2]);
    ListNode* head = GenerateRandomLinkList(len);

    ListNode *res = removeNthFromEnd(head, k);
    PrintLinkList(res);
    return 0;
}