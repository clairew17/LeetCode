#include"../CC/header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;      
        int profit = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i - 1]) {
                //add profit if price increase
                profit += (prices[i]-prices[i-1]);       
            }
        }
        return profit;
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