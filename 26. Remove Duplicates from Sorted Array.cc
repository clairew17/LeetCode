class Solution {
public:
    //two pointers
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)return n;
        int k=0, i=0;
        while(i<n){
            //copy the first unique char
            nums[k++]=nums[i++];
            //by pass latter dups
            while(i<n && nums[i]==nums[i-1])i++;
        }
        nums.resize(k);
        return k;
    }
};