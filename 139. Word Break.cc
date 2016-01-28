class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(dict.size()==0) return false;
        int n = s.size();
        vector<bool>dp(n+1,false);
        dp[0]=true;
        
        //check a word exist in dict
        for(int i=1;i<=n;i++)
        {
            //check all preceeding words
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j]==true)
                {
                    //word from j to i
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end())
                    {//next i
                        dp[i]=true;
                        break; 
                    }
                }
            }
        }

        return dp[s.size()];
    }
};