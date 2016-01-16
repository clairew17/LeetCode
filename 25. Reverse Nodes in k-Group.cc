//25. Reverse Nodes in k-Group.cc
#include"../CC/header.h"
//reverse from first to last
//reverse from head and before tail
ListNode* reverse(ListNode* head, ListNode* tail)
{
    ListNode* pre = tail;
    while(head!=tail){
        auto temp = head->next;
        head->next = pre;
        pre = head;
        head = temp;
    }
    return pre;
}
ListNode* reverseKGroup(ListNode* head, int k)
{
    auto node = head;
    for(int i=0;i<k;i++)
    {
        if(node==NULL)return head;//if list is too short, return
        node = node->next;
    }
    //node is the k th node
    auto new_head = reverse(head, node);
    
    //reverse the next k group
    head->next = reverseKGroup(node, k);
    
    //return new head
    return new_head;
}

int main(int argc, char *argv[]){
    int len = stoi(argv[1]);
    int k = stoi(argv[2]);
    ListNode* head = GenerateRandomLinkList(len);

    ListNode *res = reverseKGroup(head, k);
    PrintLinkList(res);
    return 0;
}