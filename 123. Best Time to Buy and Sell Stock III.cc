#include"../CC/header.h"

class Solution {
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

int main()
{
	int arr[] = {6,1,3,2,4,7};
	vector<int>prices;
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)prices.push_back(arr[i]);
	cout << "Input:\t"; PrintVector(prices);

	Solution sol;
	cout << "MaxProfit=\t"<<sol.maxProfit(prices)<<endl;

	return 0;
}