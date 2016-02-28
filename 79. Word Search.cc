class Solution {
public:
    vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    bool dfs(vector<vector<char>>& board, string word, int ind, int i, int j)
    {
        if(ind == word.size())return true;
        
        //check current point
        if(board[i][j] != word[ind])return false;
        //reach the end of string
        if(ind == word.size()-1)return true;
        
        
        //mark as visited
        char c = board[i][j];
        board[i][j] = '\0';
        
        for(auto d:dir){
            int x = i+d.first, y = j+d.second;
            
            if(x>=0 && x<board.size() && y>=0 && y<board[0].size() && word[ind+1]==board[x][y])
            {
                if(dfs(board, word, ind+1, x, y)==true)return true;
            }
        }
        //recover
        board[i][j] = c;
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();if(m<1)return false;
        int n = board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(word[0]==board[i][j] && dfs(board, word, 0, i, j) == true)return true;
            }
        }
        return false;
    }
};


class Solution {
public:
    vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int ind){
        if(ind==word.size())return true;
        if(word[ind] != board[i][j])return false;
        char c = board[i][j];
        board[i][j] = '\0';
        ind++;
        //check if reach the end of string after incrementing ind
        if(ind==word.size())return true;
        
        for(auto d : dir){
            int x = d.first +i, y = d.second + j;
            if(x>=0 && x<board.size() && y>=0 && y<board[0].size()){
                if( dfs(board, x, y, word, ind) == true)return true;
            }
        }
        //recover
        board[i][j] = c;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();if(row<1)return false;
        int col = board[0].size();
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if( dfs(board, i, j, word, 0) == true)
                    return true;
            }
        }
        return false;
    }
};