class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();if(n<3)return 0;
        int cnt = 0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;){
            //while(i && i<n && nums[i]==nums[i-1])i++;
            int j = i+1, k = n-1;
            while(j < k){
                if(nums[i]+nums[j]+nums[k]<target){
                    //no need to compute num between [j:k]
                    cnt += (k-j);//all the possible ks
                    j++;
                }else{
                    k--;
                }
            }
            int c = nums[i];i++;
            //count the dups
            //while(i<n && nums[i]==c)i++;
        }
        return cnt;
    }
};