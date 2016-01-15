323. Connected Components Num in Graph.cc

class Solution {
public:
    int find(vector<int>visit, int i){
        if(visit[i]==-1)return i;
        if(visit[i]==i)return i;
        visit[i] = find(visit,visit[i]);
        return visit[i];
    }
    
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int count = n;
        vector<int>visit(n,-1);
        vector<int>sz(n,1);
        for(auto edge:edges){
            //find the root of two vertex
            int x = find(visit, edge.first);
            int y = find(visit, edge.second);
            if(x!=y){
                if(sz[x] > sz[y]){
                    sz[x] += sz[y];
                    visit[y] = x;
                }else{
                    sz[y] += sz[x];
                    visit[x] = y;
                }
                count--;
            }
        }
        return count;
    }

};