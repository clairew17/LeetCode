#include"../CC/header.h"

//return true if a linklist has cycle

class Solution {
public:
    //use two pointers
    bool hasCycle(ListNode *head) {
        ListNode *fast=head, *slow = head;
        while(fast&&slow)
        {
            slow = slow->next;
            if(fast->next == NULL)return false;
            else fast = fast->next->next;
            if(fast==slow)return true;
        }
        return false;
    }
};

int main(){
	return 0;
}