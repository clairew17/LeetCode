//138. Copy List with Random Pointer.cc


//recursive method

class Solution {
private:
    //map input:cloned node
    unordered_map<RandomListNode*, RandomListNode*>NodeMap;
public:
	//return the head of cloned linklist
    RandomListNode *copyRandomList(RandomListNode *head){
        if(head==NULL)return NULL;
        if(NodeMap.find(head)!=NodeMap.end()){//return cloned node
            return NodeMap[head];
        }else{
            RandomListNode *node = new RandomListNode(head->label);
            NodeMap[head]=node;
            
            //copy the pointers
            node->next = copyRandomList(head->next);
            node->random = copyRandomList(head->random);
            
            return node;
        }
    }
};