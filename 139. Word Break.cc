class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(dict.size()==0) return false;
        int n = s.size();
        //words including char[i]
        vector<bool>dp(n+1,false);
        //dp[i] is set to true if a valid word (word sequence) ends there
        dp[0]=true;
        
        //check a word exist in dict
        for(int i=1;i<=n;i++)
        {
            //check all preceeding words
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j]==true)
                {
                    //word from j to i, excluding i
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end())
                    {//next i
                        dp[i]=true;
                        break; 
                    }
                }
            }
        }

        return dp[n];
    }
};



class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        
        //buffer is there exits a valid break before pos
        vector<bool>dp(n+1, false);
        //dp[0] means break before pos 0, set true
        dp[0] = true;
        
        for(int i = 1; i<= n; i++)//dp[i]: valid breaks for s[0, i), before i
        {
            for(int pos = i-1; pos >= 0; pos--)//break at pos i
            {
                string word = s.substr(pos, i-pos);
                
                if(dp[pos]==true && wordDict.count(word))// valid breaks before pos && word is valid
                {
                    dp[i] = true;
                    break;//stop searching
                }
            }
        }
        return dp[n];//validness of break before ind n
    }
};