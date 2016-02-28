class Solution {
public:
    void reverse(vector<int>& nums, int s, int e){
        while(s<e){
            swap(nums[s], nums[e]);
            s++;e--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;
        for(i=n-2;i>=0;i--){//find the largest num in ascending order
            if(nums[i]<nums[i+1])
            break;
        }
        //cout << i << endl;
        
        if(i == n-1){//if i==n-1; the input vector is in descending order nums[i] < nums[i+1]
            reverse(nums, 0, n-1);
            return;
        }
        
        int k;
        for(k=n-1;k>i;k--){//find the largest k that nums[k] > nums[i]
            if(nums[k]>nums[i])
                break;
        }
        //cout << k <<endl;
        //swap k & i
        swap(nums[k], nums[i]);
        
        //reverse from k+1 to the end of vector
        if(k<n-1)reverse(nums, k+1, n-1);
    }
};