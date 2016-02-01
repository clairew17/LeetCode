class Solution {
public:
    bool isPowerOfTwo(int n) {
        //if n is power of two, n-1 is the complement of n
        return (n>0)&&!(n&(n-1));
    }
};