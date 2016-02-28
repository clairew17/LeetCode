class Solution {
public:
    void helper(vector<int>& nums, int begin,vector<vector<int>> &res){
        if(begin == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=begin; i<nums.size();i++){
            //move ith num to begin
            swap(nums[begin], nums[i]);
            helper(nums, begin+1, res);
            swap(nums[begin], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        helper(nums, 0, res);
        return res;
    }
};