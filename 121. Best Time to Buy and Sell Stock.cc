//121. Best Time to Buy and Sell Stock.cc

#include"../CC/header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;      
        int maxProfit = 0, minPrice = prices[0];

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i - 1]) {
            	//update a maxPrice and maxProfit
                maxProfit = max(maxProfit, prices[i] - minPrice);       
            }else{
            	//day i to buy in
                minPrice = min(minPrice, prices[i]);
            }
        }
        return maxProfit;
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