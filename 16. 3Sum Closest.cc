//with sorting
//time: O(nlogn) + O(n^2)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<3)return -1;
        sort(nums.begin(), nums.end());
        int closest_sum = nums[0]+nums[1]+nums[2];
        
        for(int i=0;i<n;i++)//start with ith value
        {
            int j = i+1, k = n-1;
            int sum = nums[i]+nums[j]+nums[k];
            while(j<k){
                sum = nums[i]+nums[j]+nums[k];
                if(sum==target)return sum;
                if(abs(sum-target)<abs(closest_sum-target))closest_sum = sum;

                if(sum < target)j++;
                if(sum > target)k--;
            }
            

        }
        return closest_sum;
    }
};

//time O(n^3) brute force
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<3)return -1;
        sort(nums.begin(), nums.end());
        int closest_sum = nums[0]+nums[1]+nums[2];
        
        for(int i=0;i<n-2;i++)//start with ith value
        {
            for(int j = i+1;j<n-1;j++){
                for(int k= j+1; k<n; k++){
                    int sum = nums[i]+nums[j]+nums[k];
                    if(sum==target)return sum;
                    if(abs(sum-target)<abs(closest_sum-target))closest_sum = sum;
                }
            } 
        }
        return closest_sum;
    }
};