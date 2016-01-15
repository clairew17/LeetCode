267. Palindrome Permutation II.cc


class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> palindromes;
        unordered_map<char, int> counts;
        for (char c : s) counts[c]++;
        int odd = 0; char mid; string half;
        for (auto p : counts) {
            if (p.second & 1) {
                odd++, mid = p.first;
                if (odd > 1) return palindromes;//no pal
            }
            half += string(p.second / 2, p.first);
            //the odd char is not included
            //fill string by copying char by p.second / 2 times
            //construct string with half chars
        }
        palindromes = permutations(half);
        
        for (string& p : palindromes){
            string t(p);
            reverse(t.begin(), t.end());
            if (odd) t = mid + t;//add the odd char to center
            p = p+t;
        }
        return palindromes;
    }
private:
    //return permutations of input string
    //consider the duplicates 
    vector<string> permutations(string& s) {
        vector<string> perms;
        string t(s);
        do {
            perms.push_back(s);
            next_permutation(s.begin(), s.end()); 
        } while (s != t);
        return perms; 
    }
};