class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<2)return s;
        string res;
        for(int i=0;i<n;i++){
            //possible largest length; pruning
            if((n-i)*2+1<res.size())return res;
            
            int ps = i, pe = i;
            //grow center with dups
            while(pe<n-1 && s[pe]==s[pe+1])pe++;
            //extend the pal string
            while(ps>0 && pe<n-1 && s[ps-1]==s[pe+1])ps--,pe++;
            //compute the length of the longest pal string centered with i
            int len = pe-ps+1;
            if(len > res.size())res = s.substr(ps, pe-ps+1);
        }
        return res;
    }
};