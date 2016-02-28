class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string>pp; //pal permutations
        unordered_map<char, int>cnt; //count the freq of each char
        for(auto c:s)cnt[c]++;
        //if pal per exits, its the perm of half chars (half_p) + even char + reverse half_p
        string half; char mid;
        bool odd_found = false;
        for(auto p:cnt){
            if(p.second%2==1){//find a char with odd freq
                if(odd_found == false){
                    mid = p.first;
                    odd_found = true;
                }else{//not pal
                    return pp;
                }
            }
            //get half of the char including the odd char (in case of odd_num>1)
            half += string(p.second/2, p.first);
        }
        pp = getPermutations(half);//get all permuations of half
        
        //use **reference** to modify the vector
        for(string &str:pp){
            string temp = str;
            reverse(temp.begin(), temp.end());
            if(odd_found==true) temp = temp+mid;
            str = temp+str;
        }
        return pp;
    }
private:
    vector<string> getPermutations(string s){//permute with dups
        vector<string>res;
        helper(s, res, 0);
        return res;
    }
    void helper(string s, vector<string>&res, int begin){
        if(begin == s.size()){
            res.push_back(s);
            return;
        }
        
        for(int i=begin;i<s.size();i++){
            if(i!=begin && s[i]==s[begin])continue;
            swap(s[i], s[begin]);
            helper(s, res, begin+1);
        }
    }
};