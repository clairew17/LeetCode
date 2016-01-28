//268. Missing Number.cc


//time: O(N)
//space: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i=0;i<n;i++)
        {
            res ^= nums[i];
            res ^= (i+1);
        }
        return res;
    }
};