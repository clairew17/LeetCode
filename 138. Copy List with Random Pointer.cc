/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    map<RandomListNode *, RandomListNode *>hash; // node:cloned node
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL)return head;
        
        if(hash.find(head)==hash.end()){
            auto node = new RandomListNode(head->label);//copy node
            hash[head] = node;
            //copy random node
            node->random = copyRandomList(head->random);
            node->next = copyRandomList(head->next);
        }
        return hash[head];
    }
};