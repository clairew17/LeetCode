15. 3Sum.cc
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>>res;
    int n = nums.size(); if(n<3)return res;

    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++){
        int target = -nums[i];
        int lo = i+1, hi = n-1;
        //convert into two sum
        while(lo<hi){
            if(nums[lo] + nums[hi]==target){
                vector<int>temp = {nums[i], nums[lo],nums[hi]};
                res.push_back(temp);
                //dup
                while(lo<hi && nums[lo]==temp[1])lo++;
                while(lo <hi && nums[hi]==temp[2])hi--;
            }else if(nums[lo] + nums[hi]<target)lo++;
            else hi--;
        }
        //dup
        while(i<n-1 && nums[i]==nums[i+1])i++;
    }
    return res;
}