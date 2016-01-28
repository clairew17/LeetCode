class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>sol(3,0);
        int n = nums.size();if(n<3)return res;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++){
            
            int j = i+1, k = n-1;
            int sum = -nums[i];
            while(j<k){
                if(nums[j]+nums[k] == sum){
                    sol[0] = nums[i];
                    sol[1] = nums[j];
                    sol[2] = nums[k];
                    res.push_back(sol);
                    //bypass duplicates if it exits in resolt
                    while(j<k && nums[j]==sol[1])j++;
                    while(j<k && nums[k]==sol[2])k--;
                }else{
                    if(nums[j]+nums[k] < sum)j++;
                    else k--;
                }
            }
            //increment to next i
            //bypass duplicated i
            while(i<n-1 && nums[i+1]==nums[i])i++;

        }
        
        return res;
    }
};