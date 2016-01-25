class Solution {
public:
    struct node{
        unordered_set<int>neighbor;//neighbors of current node
        bool isLeaf(){return neighbor.size()==1;}//if current node is a leaf
    };
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int>buffer1, buffer2;
        //two buffers to store leaves of different layer
        if(n==1){
            buffer1.push_back(0);
            return buffer1;
        }
        if(n==2){
            buffer1.push_back(0);
            buffer1.push_back(1);
            return buffer1;
        }
        //build the gragh
        vector<node>nodes(n);
        for(auto p:edges){
            nodes[p.first].neighbor.insert(p.second);
            nodes[p.second].neighbor.insert(p.first);
        }
        //find all leaves
        for(int i=0;i<n;i++){
            if(nodes[i].isLeaf()==true)
                buffer1.push_back(i);
        }
        
        //remove leaves layer by layer
        while(1){
            for(auto i:buffer1){
                for(auto n:nodes[i].neighbor){
                    nodes[n].neighbor.erase(i);
                    //add leaves after removal
                    if(nodes[n].isLeaf()==true)buffer2.push_back(n);
                }
            }
            //access the next layer's leaves
            if(buffer2.empty()){
                return buffer1;
            }
            buffer1.clear();
            swap(buffer1, buffer2);
        }
    }
};