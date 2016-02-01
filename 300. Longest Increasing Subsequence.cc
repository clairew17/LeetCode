//300. Longest Increasing Subsequence.cc


//time: O(N^2)
//space: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n<2)return n;
        vector<int>dp(n,1);//longest subsequence ends and includes ith number
        int maxLen = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            //cout << i << '\t' << dp[i] << endl;
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};


//time: O(NlogN)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> s;
        for (auto a : nums) {
            if (s.find(a) != s.end()) continue;//existed
            s.insert(a);
            auto it = s.upper_bound(a);
            //Returns an iterator pointing to the first element in the container which is considered to go after val.

            if (it != s.end()){
                //cout << "erase " << *it << endl;
                s.erase(it);
            }
            //for(auto i:s)cout << i << ',';
            //cout << endl;
        }
        return s.size();
    }
};