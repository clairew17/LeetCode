266. Palindrome Permutation.cc
class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char,int>m;
        for(auto ss:s){
            m[ss]++;
        }
        int count_odd=0;
        for(auto mm:m){
            if(((mm.second)%2)==1)count_odd++;
        }
        if(count_odd == 1 || count_odd==0)return true;
        return false;
    }
};