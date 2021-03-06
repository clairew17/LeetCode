//when there could be duplicates
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<1)return -1;
        
        int lo = 0, hi = n-1, mid;
        //only 1 segment is rotated, the other part is sorted
        //find the sorted segement, do binary search
        while(lo<hi)//binary search
        {
            //bypass duplicate
            while(lo<hi && nums[lo] == nums[lo+1])lo++;
            while(lo<hi && nums[hi] == nums[hi-1])hi--;
            //check corner case
            if(lo==hi)break;
            
            mid = (lo + hi)/2;
            if(nums[mid]==target)return true;
            //find the unrotated part

            
            if(nums[lo]<=nums[mid]){//[lo:hi]is sorted
                if(target >= nums[lo] && target < nums[mid]){
                    hi = mid-1;
                }else{ 
                    lo = mid+1;
                }
            }else{
                if(target <= nums[hi] && target > nums[mid]){
                    lo = mid+1;
                }else{ 
                    hi = mid-1;
                }
            }
        }
        
        return nums[lo]==target?true:false;
    }
};