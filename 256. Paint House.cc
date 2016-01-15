256. Paint House.cc
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.size()<1)return 0;
        int lastR = costs[0][0];
        int lastG = costs[0][1];
        int lastB = costs[0][2];
        for(int i=1;i<costs.size();i++){
            int curR = costs[i][0] + min(lastG,lastB);
            int curG = costs[i][1] + min(lastR,lastB);
            int curB = costs[i][2] + min(lastG,lastR);
            lastR = curR;
            lastB = curB;
            lastG = curG;
        }
        return min(min(lastR, lastB),lastG);
    }
};