59. Spiral Matrix II.cc


vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>>res(n, vector<int>(n,0));
    if(n<1)return res;
    int rb=0, re = n-1, cb = 0, ce = n-1;
    int x=1;
    while(rb<=re && cb <=ce){
        for(int j=cb; rb<=re && j<=ce; j++){
            res[rb][j] = x++;
        }
        rb++;
        for(int i=rb;cb<=ce && i<=re;i++){
            res[i][ce] = x++;
        }
        ce--;
        for(int j=ce; rb<=re && j>=cb; j--){
            res[re][j] = x++;
        }
        re--;
        for(int i=re;cb<=ce && i>=rb;i--){
            res[i][cb] = x++;
        }
        cb++;
    }
    return res;
}