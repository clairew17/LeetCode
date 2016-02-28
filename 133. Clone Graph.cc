/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
#include"../CC/header.h"


class Solution {
public:
    map<UndirectedGraphNode *, UndirectedGraphNode *>hash;//store the nodes
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL)return node;
        if(hash.find(node)==hash.end())//not existed
        {
            hash[node] = new UndirectedGraphNode(node->label);
            for(auto neighbor:node->neighbors){
                //clone neighbor
                auto temp = cloneGraph(neighbor);
                hash[node]->neighbors.push_back(temp);
            }
        }
        //return cloned node
        return hash[node];
    }
};


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {//BFS
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL)return NULL;
        
        map<UndirectedGraphNode *, UndirectedGraphNode *>mymap;//node: cloned node
        queue<UndirectedGraphNode *>q;//q of current layer
        
        UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
        mymap[node] = newnode;
        q.push(node);//node to clone
        
        while(!q.empty()){
            UndirectedGraphNode *p = q.front(); q.pop();
            for(auto n:p->neighbors){//copy neighbors
                if(mymap.find(n) == mymap.end()){
                    UndirectedGraphNode *np = new UndirectedGraphNode(n->label);
                    mymap[n] = np;
                    q.push(n);
                }
                //copy the neighbors
                mymap[p]->neighbors.push_back(mymap[n]);
            }
        }
        return mymap[node];
    }
};