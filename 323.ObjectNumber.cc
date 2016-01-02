//323.ObjectNumber.cc


#include"../CC/header.h"
int find(vector<int>visit, int i){
        if(visit[i]==-1)return i;
        if(visit[i]==i)return i;
        visit[i] = find(visit,visit[i]);
        return visit[i];
    }
    
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int count = 0;
        vector<int>visit(n,-1);
        for(auto edge:edges){
            //find the root of two vertex
            int x = find(visit, edge.first);
            int y = find(visit, edge.second);
            if(x!=y)visit[x]=y;
        }
        
        for(int i=0;i<visit.size();i++){
            if(visit[i]==-1)count++;
        }
        return count;
    }

int main(){
    
    int n = ARRAY_SIZE(arr);

}