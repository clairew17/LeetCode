class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            //not use i+1!=nums[i] to avoid endless loop for duplicated input like [1,1]
            while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i])//put nums[i] to pos=nums[i]-1
                swap(nums[i], nums[nums[i]-1]);
        }
        
        for(int i=0;i<n;i++){
            if(i+1 != nums[i])return i+1;
        }
        return n+1;
    }
};