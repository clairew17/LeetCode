class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(len < 2)return 0;
        //simple case: sell when price increases
        if(k>len/2){
            int res = 0;
            for(int i=1; i<len;i++){
                if(prices[i]>prices[i-1])
                    res += (prices[i]-prices[i-1]);
            }
            return res;
        }else{
            //dp
            vector<int>hold(k+1, INT_MIN);//hold at ith trans
            vector<int>rele(k+1, 0);//sell at ith trans
            
            for(int i=0;i<len;i++){
                for(int j=k;j>0;j--){//update from tail: keep data unchanged
                    hold[j] = max(hold[j], rele[j-1]-prices[i]);
                    rele[j] = max(rele[j], hold[j]+prices[i]);
                    //cout << hold[j] <<'\t'<< rele[j] << endl;
                }
            }
            return rele[k];
        }
        
    }
};