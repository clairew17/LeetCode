vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    

//BFS all boarder conneted 'O'
void BFS(vector<vector<char>>& board, int i, int j){
    int m = board.size(); if(m<1)return;
    int n = board[0].size();
    queue<pair<int,int>>q;
    board[i][j] = 'B';
    q.push(make_pair(i,j));
    while(!q.empty()){
        int a = q.front().first, b = q.front().second;q.pop();
        for(auto d:dir){
            int x = a+d.first, y = b+d.second;
            if(x>=0 && x<m && y>=0 && y<n && board[x][y]=='O'){
                q.push(make_pair(x,y));
                board[x][y] = 'B';
            }
        }
    }
}

//DFS stack overflow
void DFS(vector<vector<char>>& board, int i, int j){
    int m = board.size(); if(m<1)return;
    int n = board[0].size();

    board[i][j] = 'B';

    for(auto d:dir){
        int x = i+d.first, y = j+d.second;
        if(x>0 && x<m-1 && y>0 && y<n-1 && board[x][y]=='O'){
            DFS(board, x, y);
        }
    }
}


void solve(vector<vector<char>>& board) {
    int m = board.size(); if(m<1)return;
    int n = board[0].size();
    
    //BFS All boarders
    for(int i=0;i<m;i++){
        if(board[i][0]=='O')
            BFS(board, i, 0);
        if(n>1 && board[i][n-1]=='O')
            BFS(board, i, n-1);
    }
    
    for(int j=0;j<n;j++){
        if(board[0][j]=='O')
            BFS(board, 0, j);
        if(m>1 && board[m-1][j]=='O')
            BFS(board, m-1, j);
    }
    
    //flip & recover
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='O')board[i][j]='X';//flip
            else if(board[i][j]=='B')board[i][j]='O';//recover
        }
    }
    
    
}