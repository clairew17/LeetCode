class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        int used1[9][9] = {0}; //used1: check each row
        int used2[9][9] = {0}; //used2: check each column
        int used3[9][9] = {0}; //used2: check each sub-boxes

        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')//number
                {
                    
                    int num = board[i][j] - '0' - 1;//start from 0
                    //cout << board[i][j] << ',' << num <<endl;
                    
                    int k_row = i / 3; //which row of subbox
                    int k_col = j / 3; //which col of subbox
                    int k = k_row *3 + k_col; // which subbox
                    
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    //mark as visited
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }

        return true;
    }
};