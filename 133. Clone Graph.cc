class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
       if (!node) return node;
       if(hash.find(node) == hash.end()){
           hash[node] = new UndirectedGraphNode(node -> label);//clone node
           for (auto x : node->neighbors) {//clone neighbors
               auto n = cloneGraph(x);
               (hash[node] -> neighbors).push_back( n );
           }
       }
       return hash[node];//return pointer of cloned node
    }
};