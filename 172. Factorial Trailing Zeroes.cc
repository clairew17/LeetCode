
//number of tailing zeroes equals number of (2*5)
//=# of 5 because 2 appears more than 5
//count # of 5, 25, 125 in n
//use longlong to avoid overflow

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for(long long i = 5;n/i>0;i*=5)
        {
            res += n/i;
        }
        return res;
    }
};