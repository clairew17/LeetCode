/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
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