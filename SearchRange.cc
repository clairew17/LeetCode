//SearchRange.cc

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res(2,-1);
        int n=nums.size();
        if(n<1)return res;
        res[0] = Left(nums, target);
        if(res[0]==-1)return res;
        else res[1]= Right(nums,target);
        return res;
        
    }
    
    int Left(vector<int>& nums, int target){
        int n=nums.size();
        if(n<1)return -1;//not found
        
        int lo=0,hi=n-1,mid;
        while(lo<hi){
            mid = (lo+hi)/2; //floor
            if(nums[mid]<target)lo=mid+1;
            else hi = mid;
        }
        cout << lo;
        if(nums[lo]==target)return lo;
        else return -1;
    }
    
    int Right(vector<int>& nums, int target){
        int n=nums.size();
        if(n<1)return -1;//not found
        
        int lo=0,hi=n-1,mid;
        while(lo<hi){
            mid = (lo+hi)/2+1; //ceiling
            if(nums[mid]>target)hi=mid-1;
            else lo=mid;
        }
        if(nums[lo]==target)return lo;
        else return -1;
    }
    
    
};