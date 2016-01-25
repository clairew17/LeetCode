#include"../CC/header.h"
vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
int shortestDistance(vector<vector<int>>& grid) {
    int m=grid.size(), n=grid[0].size(), mark=0, ans;

    vector<vector<int>> dist(m, vector<int>(n, 0));

    int dx[4] = {0, 1, 0, -1}; // up, right, down, left
    int dy[4] = {1, 0, -1, 0};

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (grid[j][i]==1) {
                queue<pair<int, int>>bfs;
                bfs.push(make_pair(j, i));
                int count = 1;
                int level=1;
                ans=INT_MAX;
                while (count>0){
                    count--;
                    auto p = bfs.front();bfs.pop();
                    int y=p.first, x=p.second;
                    for (int d=0; d<4; d++) {
                        int nx=x+dx[d], ny=y+dy[d];
                        if (0<=nx && nx<n && 0<=ny && ny<m && grid[ny][nx]==mark) {
                            grid[ny][nx] = mark-1;
                            dist[ny][nx] += level;
                            ans = min(ans, dist[ny][nx]);
                            bfs.push(make_pair(ny, nx));
                        }
                    }
                    if(count==0){
                        level++;
                        count = bfs.size();
                    }
                }
                mark--;
            }
        }
    }
    return ans==INT_MAX ? -1 : ans;
}

int main(){
    vector<vector<int>>grid={
        {1 , 0 , 2 , 0 , 1},
        {0 , 0 , 0 , 0 , 0},
        {0 , 0 , 1 , 0 , 0}};
    cout << shortestDistance(grid)<<endl;
    return 0;
}
