296. Best Meeting Point.cc
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
    if (grid.empty())return 0;
    vector<int> row, col;
    for(int i=0; i<grid.size(); i++)
        for (int j=0; j<grid[0].size(); j++) {
            if (grid[i][j]) {
                row.push_back(i);
                col.push_back(j);
        }
    }
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
    int mid_row = row[row.size()/2];
    int mid_col = col[col.size()/2];
    int res = 0;
    for (auto r: row)
        res += abs(r-mid_row);
    for (auto r: col)
        res += abs(r-mid_col);
    return res;
    }
};