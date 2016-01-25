64. Minimum Path Sum.cc

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(); if(m<1)return 0;
    int n = grid[0].size(); if(n<1)return 0;
    vector<vector<int>>dp = grid;
    for(int i=1;i<m;i++)dp[i][0] += dp[i-1][0];
    for(int j=1;j<n;j++)dp[0][j] += dp[0][j-1];
    
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}

