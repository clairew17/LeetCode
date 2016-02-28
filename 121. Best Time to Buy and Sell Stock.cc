//121. Best Time to Buy and Sell Stock.cc

#include"../CC/header.h"

struct trans{
    int profit;
    int sellPrice;
    int buyPrice;
    trans(int s, int b){
        sellPrice = s;
        buyPrice = b;
        profit = s-b;
    }
    void set(int s, int b){
        sellPrice = s;
        buyPrice = b;
        profit = s-b;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 1) return 0;      
        int maxProfit = 0, sell = 0, buy = 0;//day of sell/buy stock
        
        trans t(prices[sell], prices[buy]);

        for(int i = 1; i < prices.size(); i++) {            

            if(maxProfit < prices[i]-prices[buy]){//sell then their is greater profits
                sell = i;//update the sell

                maxProfit = max(maxProfit, prices[i]-prices[buy]);
                if(maxProfit > t.profit){
                    t.set(prices[sell], prices[buy]);
                }
            }


            if(prices[buy] > prices[i]){//possible good buy
                //update the trans
                buy = i;
                if(buy>sell)sell=buy;//keep the sell price updated
            }
               
        }
        cout << "buyPrice" << '\t' << "sellPrice" << '\t' << "maxProfit" <<endl;
        cout << t.buyPrice << '\t' << t.sellPrice << '\t' << t.profit <<endl;
        return maxProfit;
    }
};

int main()
{
	//int arr[] = {5,5,5,5};
    int arr[] = {5,5,5,5,3,3};
    //int arr[] = {5,5,5,5,1,1,4,3};
    //int arr[] = {1,2,3,4,5};
    //int arr[] = {5,4,3,2,1};
    //int arr[] = {6,16,5,7,1,5};
	vector<int>prices;
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)prices.push_back(arr[i]);
	cout << "Input:\t"; PrintVector(prices);

	Solution sol;
	sol.maxProfit(prices);

	return 0;
}