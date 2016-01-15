317. Shortest Distance from All Buildings.cc

class Solution {
public:
    /*int shortestDistance(vector<vector<int>>& grid) {
        
    }*/

int shortestDistance(vector<vector<int>>& grid) {
    const int row = grid.size();
    if (0 == row) return -1;
    const int col = grid[0].size();

    vector<vector<int> > distance(row, vector<int>(col, 0));
    vector<vector<int>> reach(row, vector<int>(col, 0));
    int building = 0, res = INT_MAX;

    for (int i = 0; i < row; i++) 
        for (int j = 0; j < col; j++) {
        // check from the building node, extend to all 0 node with distance
        if (1 == grid[i][j]) {
            ++building;
            int dist = 0;
            vector<vector<bool>> visited(row, vector<bool>(col, false));
            queue<pair<int, int>> curLevel, nextLevel;
            curLevel.emplace(i, j);
            // bfs search for each current building
            while (!curLevel.empty()) {
                ++dist;
                while (!curLevel.empty()) {
                    pair<int, int> cur = curLevel.front(); 
                    curLevel.pop();
                    int x = cur.first, y = cur.second;
                    ++reach[x][y];
                    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                    for (auto dir : dirs) {
                        int i = x + dir.first, j = y + dir.second;
                        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && 0 == grid[i][j] && !visited[i][j]) 
                        {
                            distance[i][j] += dist;
                            nextLevel.emplace(i, j);
                            visited[i][j] = true;
                        }
                    }
                }
                swap(curLevel, nextLevel);
            }
        }
    }
for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
        if (0 == grid[i][j] && reach[i][j] == building) {
            res = min(res, distance[i][j]);
        }
    }
}
return res == INT_MAX ? -1 : res;
        
    }
};