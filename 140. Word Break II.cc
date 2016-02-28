class Solution {
public:
    //string: breaks of substrings
    unordered_map<string, vector<string>>m; 
    
    //extend breaks by appending word after
    void extend(vector<string> &prev, string latter){
        for(int i=0; i<prev.size(); i++)
        {
            prev[i] += (' ' + latter);
        }
    }
    
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        //lookup map to find memorization of existed results
        if(m.count(s)) return m[s];
        
        vector<string> result;//result of all breaks of s
        
        // no existing result, let's compute!
        if(wordDict.count(s))//s is a word as a whole, then s is a break
        {
            result.push_back(s);
        }
        
        //break s
        for(int pos = 1; pos < s.size(); pos++)//break string at pos: [0, pos) and [pos, end)
        {
           string prev = s.substr(0, pos);
           string latter = s.substr(pos);
           
           if(wordDict.count(latter)){//if the latter part is a valid word
               
               //break the prev string
               vector<string>prev_break = wordBreak(prev, wordDict);
               //combine latter with prev_break
               extend(prev_break, latter);
               //insert this breaks of s to result
               result.insert(result.end(), prev_break.begin(), prev_break.end());
           }
        }
        
        m[s] = result;//memorisation
        
        return result; 
    }
};