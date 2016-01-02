//322.CoinChange.cc

#include"../CC/header.h"


void helper(vector<int>& coins, int begin, int amount, int count, int &min_num){
	if(begin>=coins.size()){
		return;
	}
	
	if(coins[begin]>amount)return;

	
	int maxnum = amount/coins[begin];
	for(int i=0;i<=maxnum;i++){
		int newcount = count + i;
		int new_amount = amount-i*coins[begin];
		if(new_amount == 0){
			if(min_num==-1 || newcount < min_num)
				min_num = newcount;
			return;
		}
		//cout << amount-i*coins[begin] << '\t' << coins[begin] <<endl;
		helper(coins, begin+1, new_amount, newcount, min_num);
	}
	return;
}
/*
int coinChange(vector<int>& coins, int amount){
	int min_num = -1;
	int count = 0;
	helper(coins, 0, amount, count, min_num);
	return min_num;
}*/
//dp
int coinChange(vector<int>& coins, int amount) {
	vector<int>dp(amount+1,INT_MAX-1);
	dp[0] = 0;
	for(int i=1;i<=amount;i++){
		for(int j =0;j<coins.size();j++){
			if(coins[j]<=i)
				dp[i] = min(dp[i], dp[i-coins[j]]+1);
		}
	}
	//PrintVector(dp);
	return dp[amount]>amount?-1:dp[amount];
}



int main(){
	//int arr[] = {1, 2, 5};
	//int arr[] = {5, 306, 188, 467, 494};
	int arr[] = {3, 7, 405, 436};
	int amount = 11;
	amount = 7047;
	amount= 8839;
	vector<int>coins = Arr2Vec(arr, 4);
	PrintVector(coins);
	int res = coinChange(coins, amount);
	cout << res << endl;
	return 0;
}