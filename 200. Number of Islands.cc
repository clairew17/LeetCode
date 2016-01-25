//200. Number of Islands.cc
#include"../CC/header.h"

vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};


//BFS Method
void BFS(vector<vector<char>>& grid, int i, int j){
	int m = grid.size(); if(m<1)return;
	int n = grid[0].size();
	queue<pair<int,int>>q;
	//BFS from current point
	q.push(make_pair(i,j));
	//mark as water to avoid loop
	grid[i][j] = '0';

	while(!q.empty()){
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		//access four neighbors
		for(auto d:dir){
			int x = a+d.first;
			int y = b+d.second;

			//if land, mark it as water
			//search until find all connecte land
			if(x>=0 && x<m && y>=0 && y<n && grid[x][y]=='1'){
				q.push(make_pair(x,y));
				grid[x][y] = '0';
			} 
		}
	}
}
//DFS method
void DFS(vector<vector<char>>& grid, int i, int j){
	int m = grid.size(); if(m<1)return;
	int n = grid[0].size();
	//mark as water
	grid[i][j] = '0';
	for(auto d:dir){
		int x = i + d.first;
		int y = j + d.second;
		//DFS all land
		if(x>=0 && x<m && y>=0 && y<n && grid[x][y]=='1'){
			DFS(grid, x, y);
		}
	}
}

int numIslands(vector<vector<char>> &grid){
	int m = grid.size(); if(m<1)return 0;
	int n = grid[0].size();

	int count = 0;
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j]=='1'){

				//start point of a island
				count++;
				DFS(grid, i, j);
			}
		}
	}
	return count;
}


int main(){

	vector<vector<char>> grid={
		{'1','1','0','0','0'},
		{'1','1','0','0','0'},
		{'0','0','1','0','0'},
		{'0','0','0','1','1'}};
	cout << numIslands(grid)<<endl;
	return 0;

}
