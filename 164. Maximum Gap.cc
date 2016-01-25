//164. Maximum Gap.cc

#include"../CC/header.h"

int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if(n<2)return 0;
    int minE = nums[0], maxE = nums[0];
    for(int i=1; i<n;i++){
        minE = min(minE, nums[i]);
        maxE = max(maxE, nums[i]);
    }
    int len = maxE - minE;
    if(len<=1)return len;
    vector<int>buck_min(n, INT_MAX);
    vector<int>buck_max(n, INT_MIN);
    for(auto num:nums){
        
        int index = double(num-minE)*(n-1)/len;
        //update min and max
        //cout << num << ',' << index << endl;
        buck_min[index] = min(buck_min[index], num);
        buck_max[index] = max(buck_max[index], num);
    }
    
    int gap = len/n, pre = buck_max[0];
    for(int i= 1;i<n;i++){
        if(buck_min[i] == INT_MAX)continue;
        gap = max(gap, buck_min[i]-pre);
        pre = buck_max[i];
    }
    return gap;
}
    
int main(){
	//srand(time(NULL));
	int n  = 10;
	vector<int>nums = GenerateRandomVector(n);
	cout << "Maximum Gap = " << maximumGap(nums) << endl;
	sort(nums.begin(), nums.end());
	PrintVector(nums);
	return 0;
}