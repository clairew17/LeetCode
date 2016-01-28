//286. Walls and Gates.cc
#include"../CC/header.h"

//directions to access four-neighbors
    vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

void wallsAndGates(vector<vector<int>>& rooms) {
    int m = rooms.size();if(m<1)return;
    int n = rooms[0].size();
    
    queue<pair<int, int>>canReach;

    //store positions of all gates
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(rooms[i][j]==0){
                canReach.push(make_pair(i,j));
            }
        }
    }
    

    while(!canReach.empty()){
        int x = canReach.front().first;
        int y = canReach.front().second;
        canReach.pop();

        //access the neighbors
        for(auto d:dir){
            int i = x+d[0], j = y+d[1];

            //update the distance to gate if a shorter path is found
            //important: update only when the current distance of(i,j) > distance from (x,y)
            if(i>=0 && i<m && j>=0 && j<n && rooms[i][j]>rooms[x][y]){
                rooms[i][j] = min(rooms[i][j], rooms[x][y]+1);
                //start from the current node
                canReach.push(make_pair(i,j));

            }
        }
        
    }
}

int main(){
	vector<vector<int>>rooms=//{{2147483647,0,2147483647,2147483647,0,2147483647,-1,2147483647}};
	{
		{2147483647,-1,0,2147483647},
		{2147483647,2147483647,2147483647,-1},
		{2147483647,-1,2147483647,-1},
		{0,-1,2147483647,2147483647}};
	wallsAndGates(rooms);
	for(auto r:rooms){
		PrintVector(r);
	}
	//cout << INT_MAX <<endl;
	return 0;
}