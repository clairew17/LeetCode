//54. Spiral Matrix.cc


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int>res;
    int m = matrix.size();if(m<1)return res;
    int n = matrix[0].size();if(n<1)return res;
    int rowBegin=0, rowEnd = m-1, colBegin = 0, colEnd = n-1;
    while(rowBegin<=rowEnd && colBegin <= colEnd){
        //row: left->right
        for(int j=colBegin;rowEnd >= rowBegin && j<=colEnd;j++)
        {
            res.push_back(matrix[rowBegin][j]);
        }
        rowBegin++;
        //col: up->down
        for(int i=rowBegin; colEnd>=colBegin && i <= rowEnd;i++)
        {
            res.push_back(matrix[i][colEnd]);
        }
        colEnd--;
        //row: right->left
        for(int j=colEnd; rowEnd >= rowBegin && j>=colBegin;j--)
        {
            res.push_back(matrix[rowEnd][j]);
        }
        rowEnd--;
        //col: down->up
        for(int i=rowEnd; colEnd>=colBegin && i >= rowBegin;i--)
        {
            res.push_back(matrix[i][colBegin]);
        }
        colBegin++;
    }
    return res;
}