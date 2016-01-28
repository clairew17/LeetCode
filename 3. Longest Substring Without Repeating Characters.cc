class Solution {
public:
//space: O(1)
//time: O(n)
//use bit map to record the times of  each char
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n<2)return n;
        
        int len = 0;//store the len of current sequence with not repeating char
        int maxlen =0;//max lend
        unordered_set<char>cnt;//store the existed char
        
        int start =0,j=0;
        while(j<n){
            char c = s[j];
            if(cnt.find(c) != cnt.end()){//already exits
                //move start to the char after c 
                while(s[start]!=c){
                    cnt.erase(s[start]);
                    start++;
                }
                //s[start]==c;
                start++;
                
                //update the length of unrepeated sequence
                len = j-start+1;
            }else{
                cnt.insert(c);
                len++;
            }
            //update maxlen
            maxlen = max(maxlen, len);
            j++;
        }
        return maxlen;
    }
};