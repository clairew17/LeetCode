261. Graph Valid Tree.cc

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int>visit(n,-1);
        for(auto edge:edges){
            //find the root of two vertex
            int x = find(visit,edge.first);
            int y = find(visit,edge.second);
            if(x==y)return false;
            //connect two node
            visit[x]=y;
        }
        return edges.size()==n-1;
    }
    int find(vector<int>visit, int i){
        if(visit[i]==-1)return i;
        return find(visit,visit[i]);
    }
};