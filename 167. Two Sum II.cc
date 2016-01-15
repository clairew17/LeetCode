167. Two Sum II.cc
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            int a = nums[i];
            int b = find(nums,target-a,i+1);
            if(b != -1){
                res.push_back(i+1);
                res.push_back(b+1);
                break;
            }
        }
        return res;
        
    }
    int find(vector<int>& nums, int target, int start){
        int lo = start, hi =nums.size()-1,mid;
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]>target)hi = mid-1;
            else lo = mid+1;
        }
        return -1;
    }
};