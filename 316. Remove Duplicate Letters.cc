//316. Remove Duplicate Letters.cc
#include"../../CC/header.h"
string removeAll(string str, char c){
        string s = str;
        auto found = s.find(c);
        while(found != string::npos){
            s.erase(found, 1);//erase other dup of first_character
            found = s.find(c);
        }
        return s;
    }
    string removeDuplicateLetters(string s) {
        int sz = s.size();
        vector<int>count(26,0);//count frequency of each character
        if(sz<2)return s;
        for(auto c:s)count[c-'a']++;
        int first_pos = 0;
        
        for(int i=0;i<sz;i++){
            if(s[i]<s[first_pos])first_pos=i;
            if(--count[s[i]-'a']==0)break;//found the lexi first
        }
        char first_char = s[first_pos];
        s = s.substr(first_pos+1);
        s = removeAll(s, first_char);
        string res = first_char + removeDuplicateLetters(s);
        //cout << res <<endl;
        return res;
    }

int main(){
    
}



/*
string removeDuplicateLetters(string s) {
    unordered_map<char, int> cnts;
    string ret;
    stack<char> stk;
    vector<bool> isVisited(26, false);
    for (char each : s) cnts[each] ++;
    for (int i = 0; i < s.size(); cnts[s[i]] --, ++ i) {
        if (isVisited[s[i] - 'a'] || (!stk.empty() && stk.top() == s[i])) continue;
        while (!stk.empty() && stk.top() > s[i] && cnts[stk.top()] > 0) {
            isVisited[stk.top() - 'a'] = false;
            stk.pop();
        }
        stk.push(s[i]);
        isVisited[s[i] - 'a'] = true;
    }
    while (!stk.empty()) {
        ret.push_back(stk.top());
        stk.pop();
    }
    reverse(ret.begin(), ret.end());
    return ret;
}*/
