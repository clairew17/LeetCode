class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string, vector<string>>m;
        //indexed by sorted anagram
        for(auto s:strs){
            auto t = s;
            sort(t.begin(), t.end());
            if(m.find(t) == m.end()){
                m[t] = {s};
            }else{
                m[t].push_back(s);
            }
        }
        
        for(auto r:m){
            auto temp = r.second;
            sort(temp.begin(), temp.end());
            res.push_back(temp);
        }
        return res;
        
    }
};