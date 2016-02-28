class Solution {
public:
    int find(vector<int>&root, int idx){
        while(idx != root[idx]){
            root[idx] = root[root[idx]];//update root
            idx = root[idx];
        }
        return idx;
    }
    
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int>res;
        vector<int>root(m*n, -1);//root
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int islands = 0;
        for(auto pos:positions){
            int x = pos.first, y = pos.second;
            int idx = x*n+y;
            root[idx] = idx;//root is it self
            islands++;//increment island number
            for(auto d : dir){
                int i = x+d.first, j = y+d.second;
                int idx_n = i*n+j;//index of neighbor
                if(i>=0 && i<m && j>=0 && j<n && root[idx_n]!=-1){
                    int root_cur = find(root, idx); //root of current node
                    int root_n = find(root, idx_n); //root of neighbor
                    if(root_cur != root_n){//merge
                        islands--;
                        root[root_n] = root_cur; //change the root of current node to root of neighbors
                    }
                }
            }
            res.push_back(islands);
        }
        return res;
    }
};