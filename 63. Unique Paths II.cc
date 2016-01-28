63. Unique Paths II.cc
class Solution {
public:
    //vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();if(m<1)return 0;
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)return 0;
        
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;
        
        //initialize first row and first col
        for(int i = 1;i<m;i++){
            if(obstacleGrid[i][0]==0 && obstacleGrid[i-1][0]==0)dp[i][0] = dp[i-1][0];
        }
        for(int j = 1;j<n;j++){
            if(obstacleGrid[0][j]==0 && obstacleGrid[0][j-1]==0)dp[0][j] = dp[0][j-1];
        }
        
        //update other node
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(obstacleGrid[i][j]==0)//if (i,j) is empty space
                    dp[i][j] = dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};