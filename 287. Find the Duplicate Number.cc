//287. Find the Duplicate Number.cc

//time: O(nlogn)+O(n)
//space: O(1);
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 1;
        while(i<n && nums[i]!=nums[i-1])i++;
        return nums[i];
    }
};


//time: O(n)
//similar to find the starting point of loop in linkedlist
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n<2)return -1;
        
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};