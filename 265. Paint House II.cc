265. Paint House II.cc
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.size() == 0) {
            return 0;
        }
        int n = costs.size();
        int k = costs[0].size();
        vector<int> dp(k, 0);
        //for color k
        int min1 = 0;
        int min2 = 0;
        for(int i = 0 ; i < n ; ++i) {
            int last_min1 = min1;
            int last_min2 = min2;
            min1 = INT_MAX;
            min2 = INT_MAX;
            //FOR HOURSE I try coloer k
            for(int j = 0 ; j < k ; ++j) {
                if(dp[j] == last_min1)
                    dp[j] = last_min2 + costs[i][j];
                else 
                    dp[j] = last_min1 + costs[i][j];
                
                if(min1 <= dp[j]) {
                    min2 = min(min2, dp[j]);
                }
                else {
                    min2 = min1;
                    min1 = dp[j];
                }
            }
        }
        return min1;
    }
};