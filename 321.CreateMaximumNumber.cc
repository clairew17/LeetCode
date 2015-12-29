//321.CreateMaximumNumber.cc

#include"../CC/header.h"

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k);
vector<int> Merge(vector<int>nums1, vector<int>nums2, int k);
vector<int>MaxNumLenk(vector<int>nums, int k);

/*
To get the maximal number out of two vector, we can split the problem into:
1) create the maximal number of length i from one vector
2) merge number1 of length(i) and number2 of length(k-i)

*/


//return the maximal number of len k
vector<int>MaxNumLenk(vector<int>nums, int k)
{
	int maxDrop = nums.size()-k;
	vector<int>res;
	for(auto n:nums){
		//insert nums[i] and make sure nums[i] is the smallest 
		while(maxDrop && res.size() && res.back() < n){
			res.pop_back();
			maxDrop--;
		}
		res.push_back(n);
	}
	res.resize(k);
	return res;
}
//merge two vector to get the maximal number of lengtg k
vector<int> Merge(vector<int>nums1, vector<int>nums2)
{
	vector<int>res;
	while(nums1.size() + nums2.size()){
		//lexi compare
		vector<int>& temp = nums1>nums2?nums1:nums2;
		res.push_back(temp[0]);
		temp.erase(temp.begin());
	}
	return res;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
{
	int n1 = nums1.size(), n2 = nums2.size();
	vector<int>maxNum(k,INT_MIN), temp1, temp2, merged;
	for(int i = max(k-n2, 0); i<= min(n1,k); i++){
		// i element from nums1, k-i from nums2
		temp1 = MaxNumLenk(nums1, i);
		temp2 = MaxNumLenk(nums2, k-i);
		merged = Merge(temp1, temp2);
		maxNum = max(maxNum, merged);
	}
	return maxNum;
}

int main(){

	vector<int>nums1 = {3, 4, 6, 5};
	vector<int>nums2 = {9, 1, 2, 5, 8, 3};
	int k = 5;
	vector<int>res = maxNumber(nums1, nums2, k);//maxNumber(res, nums1, nums2, k);
	PrintVector(res);
	return 0;

}