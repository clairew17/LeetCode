//121. Best Time to Buy and Sell Stock.cc

#include"../CC/header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 1) return 0;      
        int maxProfit = 0, sellPrice = prices[0], buyPrice = prices[0];

        for(int i = 1; i < prices.size(); i++) {
            if(maxProfit < prices[i] - buyPrice){
                sellPrice = max(sellPrice, prices[i]);
                buyPrice = min(buyPrice, prices[i]);       
                maxProfit = prices[i] - buyPrice;   
            }

        }
        cout << "buyPrice" << '\t' << "sellPrice" << '\t' << "maxProfit" <<endl;
        cout << buyPrice << '\t' << sellPrice << '\t' << maxProfit <<endl;
        return maxProfit;
    }
};

int main()
{
	int arr[] = {5};//{5,5,5,5,5};//{1,2,3,4,5};//{5,4,3,2,1};
	vector<int>prices;
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)prices.push_back(arr[i]);
	cout << "Input:\t"; PrintVector(prices);

	Solution sol;
	sol.maxProfit(prices);

	return 0;
}