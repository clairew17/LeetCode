294. Flip Game II.cc
class Solution {

public:
    int len;
    string ss;
    bool canWin(string s) {
        len = s.size();
        ss = s;
        return canWin();
    }

bool canWin() {
    for (int is = 0; is <= len-2; ++is) {
        if (ss[is] == '+' && ss[is+1] == '+') {
            ss[is] = '-'; ss[is+1] = '-';
            bool wins = !canWin(); 
            ss[is] = '+'; ss[is+1] = '+';
            if (wins) return true;
        }
    }
    return false;
} 
    
};