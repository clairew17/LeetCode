//305. Number of Islands II.cc


class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        int sz = positions.size();
        if(sz<1 || m <1 || n<1)return res;
        int neighbor_x[]={0,-1,0,1};
        int neighbor_y[]={1,0,-1,0};
        vector<vector<int>>mat(m,vector<int>(n,-1));
        int islandNum = 0;

        for(int i=0;i<sz;i++){
        	int x = positions[i].first, y = positions[i].second;
        	mat[x][y] = i;
        	Parent.push_back(i);
        	islandNum++;
        	for(int j=0;j<4;j++){
        		int n_x = x+neighbor_x[j], n_y = y + neighbor_y[j];
        		if(n_x>=0 && n_x <m && n_y >=0 && n_y < n && mat[n_x][n_y] != -1)
        		{
        			islandNum--;
        			Parent[getParent(mat[x][y])] = getParent(mat[n_x][n_y]);
        		}
        	}
        	res.push_back(islandNum);
        }
        return res;
    }
private:
    vector<int> Parent;
    int getParent(int c){
        if (Parent[c] != c)
            Parent[c] = getParent(Parent[c]);
        return Parent[c];
    }
};




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
        vector<int> ret;
        vector<vector<int>> mat(m, vector<int>(n, -1));
        int tx[4] = {0, 0, 1, -1},
            ty[4] = {1, -1, 0, 0};
        int island_num = 0;
        for (int i = 0; i < positions.size(); ++ i){
            int x = positions[i].first, y = positions[i].second;
            //which island
            mat[x][y] = i;
            Parent.push_back(i);
            island_num++;
            for (int k = 0; k < 4; ++ k){
                int neighbor_x = x+tx[k];
                int neighbor_y = y+ty[k];
                if (neighbor_x >= 0 && neighbor_y >= 0 && neighbor_x < m && neighbor_y < n && mat[neighbor_x][neighbor_y] != -1)//neighbors are islands
                {
                    if (getParent(mat[neighbor_x][y + ty[k]]) != getParent(mat[x][y]))
                    {
                        Parent[getParent(mat[x][y])] = getParent(mat[neighbor_x][neighbor_y]);
                        island_num--;
                    }
                }
            }
            ret.push_back(island_num);
        }
        return ret;
    }
};