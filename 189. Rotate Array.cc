class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        //small or empty array
        if(n<2)return;
        
        //handle the negarive
        while(k<0)k+=n;
        //k > n
        k = k%n;
        //k == 0
        if(k==0)return;
        
        //reverse the whole arr, to get the last k num to the front of arr
        reverse(nums.begin(),nums.end());
        //reverse first k arr
        reverse(nums.begin(),nums.begin()+k);
        //reverse last n-k arr
        reverse(nums.begin()+k,nums.end());
    }
};