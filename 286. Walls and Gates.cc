//286. Walls and Gates.cc
#include"../CC/header.h"

void wallsAndGates(vector<vector<int>>& rooms) {
	int m = rooms.size(); if(m<1)return;
	int n = rooms[0].size(); if(n<1)return;

	queue<pair<int, int>>canReach;
	vector<pair<int, int>>neighbor={{1, 0},{-1, 0},{0, 1},{0, -1}};
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(rooms[i][j]==0){
				canReach.push(make_pair(i, j));
			}
		}
	}

	while(!canReach.empty()){
		int x = canReach.front().first, y = canReach.front().second;
		canReach.pop();
		for(auto nb:neighbor){
			int i = x+nb.first, j = y + nb.second;
			if(i<0 || i>=m || j<0 || j>=n || rooms[i][j]<=rooms[x][y])continue;
			canReach.push(make_pair(i, j));
			rooms[i][j] = rooms[x][y]+1;
		}
	}
}


int main(){

	cout << INT_MAX <<endl;
	return 0;
}