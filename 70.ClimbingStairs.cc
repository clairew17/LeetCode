//70.ClimbingStairs.cc
#include"../CC/header.h"
/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

*/


//Method 1:use array to store previous result

/*

    int climbStairs(int n) {
    vector<int>CS(n+1,0);
	CS[0]=CS[1]=1;
	for(int i=2;i<=n;i++){
	    CS[i] = CS[i-1] + CS[i-2];    
	}
	return CS[n];
    }


    int climbStairs(int n) {
	int n1 = 1, n2=1, res = 1;
	for(int i=2;i<=n;i++){
	    res = n1 + n2;
	    n2 = n1;
	    n1 = res;
	}
	return res;
    }

*/




//CS[i] = CS[i-1] + CS[i-2];
//return all possible ways   
void climbStairs(
	vector<vector<int>>&res,
	vector<int>&sol,
	int sum)
{
	
	if(sum == 0){
		res.push_back(sol);
		return;
	}
	
	if(sum>1){
		sol.push_back(2);
		climbStairs(res, sol,sum-2);
		sol.pop_back();
	}

	sol.push_back(1);
	climbStairs(res, sol,sum-1);
	sol.pop_back();
	return;

}

int climbStairs(int n) {
	vector<vector<int>>res;
	vector<int>sol;
	if(n==0)return 1;
	climbStairs(res, sol,n);
	for(auto rr:res){
		PrintVector(rr);
	}
	return res.size();
}



int main(){
	int n = 10;
	int way = climbStairs(n);
	return 0;
}