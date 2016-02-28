class Solution {
public:

/*
Since the board has ints but only the 1-bit is used, I use the 2-bit to store the new state. 
At the end, replace the old state with the new state by shifting all values one bit to the right.
*/
void gameOfLife(vector<vector<int>>& board) 
{
    int m = board.size(), n = m ? board[0].size() : 0;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            int count = 0;
            for (int I=max(i-1, 0); I<min(i+2, m); ++I)
                for (int J=max(j-1, 0); J<min(j+2, n); ++J)
                    count += board[I][J] & 1;
            if (count == 3 || count - board[i][j] == 3)
                board[i][j] |= 2;//store result at second bit
        }
    }
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            board[i][j] >>= 1;//right shift
}

};