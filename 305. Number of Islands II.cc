305. Number of Islands II.cc
class Solution {
private:
    //which island
    vector<int>Parent;
    int getParent(int x){
        if(x != Parent[x]){
            Parent[x] = getParent(Parent[x]);
        }
        return Parent[x];
    }
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int>res;
        vector<vector<int>> mat(m, vector<int>(n, -1));
        int tx[4] = {0, 0, 1, -1},
            ty[4] = {1, -1, 0, 0};
        int island_num = 0;
        for (int i = 0; i < positions.size(); i++){
            int x = positions[i].first, y = positions[i].second;
            mat[x][y] = i;//which island
            Parent.push_back(i);
            island_num++;
            for (int k = 0; k < 4; k++){
                int neighbor_x = x+tx[k];
                int neighbor_y = y+ty[k];
                if (neighbor_x >= 0 && neighbor_x < m && neighbor_y >= 0 && neighbor_y < n && mat[neighbor_x][neighbor_y] != -1)//neighbors are islands
                {
                    if (getParent(mat[neighbor_x][y + ty[k]]) != getParent(mat[x][y]))
                    {
                        Parent[getParent(mat[x][y])] = getParent(mat[neighbor_x][neighbor_y]);
                        island_num--;
                    }
                }
            }
            res.push_back(island_num);
        }
        return res;
    }
};