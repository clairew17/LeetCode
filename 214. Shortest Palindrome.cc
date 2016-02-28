#include "../CC/header.h"
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;

        vector<int> dp(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = dp[i - 1];
            cout << j << endl;
            while (j > 0 && l[i] != l[j]){
                j = dp[j - 1];
            }
            dp[i] = (j += l[i] == l[j]);
        }

        string res = rev_s.substr(0, s.size() - dp[l.size() - 1]) + s;
        cout << res <<endl;
        return res;
    }
};

int main(){
    string str = "aacecaaa";
    Solution s;
    s.shortestPalindrome(str);
}