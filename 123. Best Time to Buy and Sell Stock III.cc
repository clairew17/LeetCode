#include"../CC/header.h"

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2)return 0;
        int state[2][4]={INT_MIN,0,INT_MIN, 0};
        // 1 BUY; 1BUY 1SELL; 2BUY 1SELL; 2BUY 2SELL
        int cur = 0;
        for(int i=0;i<n;i++)
        {
            int next = 1-cur;
            state[next][0] = max(state[cur][0], -prices[i]);//1buy
            state[next][1] = max(state[cur][1], state[cur][0]+prices[i]);//1buy 1SELL
            state[next][2] = max(state[cur][2], state[cur][1]-prices[i]);//1buy
            state[next][3] = max(state[cur][3], state[cur][2]+prices[i]);//1buy
            cur = next;
        }
        return max(state[cur][1], state[cur][3]);
    }
};

//use state machine k*2 KBuy(K-1)Buy
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 2;
        int n = prices.size();
        if(n<2 || k<1) return 0;
        
        vector<vector<int>>buffer1(k, {INT_MIN, 0});
        vector<vector<int>>buffer2(k, {INT_MIN, 0});
        int maxProfit = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0; j<k; j++){
                if(j==0){//buy 1
                    buffer2[j][0] = max(buffer1[j][0], -prices[i]);
                }else{
                    buffer2[j][0] = max(buffer1[j][0], buffer1[j-1][1]-prices[i]);
                }
                // j buy/j sell = max(last time jBuyjSell, last time jBuy(j-1)Sell + sell Price[i])
                buffer2[j][1] = max(buffer1[j][1], buffer1[j][0]+prices[i]);
                maxProfit = max(maxProfit, buffer2[j][1]);
            }
            swap(buffer2, buffer1);
            //buffer2.clear();
        }

        /*for(int j = 0; j<k; j++){
            cout << buffer1[j][0] <<','<< buffer1[j][1] << endl;
            maxProfit = max(maxProfit, buffer1[j][1]);
        }*/
        return maxProfit;
    }
};



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;//trans number
        
        vector<int>hold(k+1,INT_MIN);
        vector<int>release(k+1, 0);
        int maxProfit = 0;
        for(int i=0;i<n;i++){
            for(int j=k;j>0;j--){
                hold[j] = max(hold[j], release[j-1]-prices[i]);
                release[j] = max(release[j], hold[j]+prices[i]);
                maxProfit = max(maxProfit, release[j]);
            }
        }
        return maxProfit;
        
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int>state(4,0);
        state[0] = state[2] = INT_MIN;
        
        for(int i=0;i<n;i++){
            state[3] = max(state[3], state[2]+prices[i]);
            state[2] = max(state[2], state[1]-prices[i]);
            state[1] = max(state[1], state[0]+prices[i]);
            state[0] = max(state[0], -prices[i]);
            
        }
        
        return max(state[3], state[1]);
        
    }
};

int main()
{
	int arr[] = {6,1,3,2,7,4,5};
	vector<int>prices;
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
        prices.push_back(arr[i]);

	cout << "Input:\t"; PrintVector(prices);

	Solution sol;
	cout << "MaxProfit=\t"<<sol.maxProfit(prices)<<endl;

	return 0;
}