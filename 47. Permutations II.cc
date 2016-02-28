class Solution {
public:
    //not reference!!
    void helper(vector<int> nums, vector<vector<int>> &res, int begin){
        if(begin == nums.size()){
            res.push_back(nums);
            return;
        }
        //cout << begin << endl;
        for(int i= begin; i<nums.size();i++){
            //by pass the dups
            if(i != begin && nums[i]==nums[begin]) continue;
            //move the ith num to begin
            swap(nums[begin], nums[i]);
            helper(nums, res, begin+1);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        helper(nums, res, 0);
        return res;
    }
};