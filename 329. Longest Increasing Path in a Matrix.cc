class Solution {
public:
    vector<pair<int, int>>dir{{0,-1},{0,1},{-1,0},{1,0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();if(!m)  return 0;
        int n = matrix[0].size(), maxSum = 0;
        
        //longest path to [i][j]
        vector<vector<int> > pathSum(m, vector<int>(n , 1));
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(pathSum[i][j] == 1)
                    maxSum = max(maxSum, dfs(matrix, pathSum, m, n, i, j));
        return maxSum;
    }

private:
    int dfs(vector<vector<int>>& matrix, vector<vector<int> > &pathSum, int m, int n, int i, int j){
        if(pathSum[i][j] > 1)//visited   
            return pathSum[i][j];
        int res = 1;

        for(auto d:dir){
            int x = i+d.first, y = j+d.second;
            if(x>=0 && x<m && y>=0 && y<n && matrix[i][j] < matrix[x][y])
                res = max(res, 1 + dfs(matrix, pathSum, m, n, x, y));
        }
        
        pathSum[i][j] = res;
        return res;
    }
};