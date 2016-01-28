class Solution {
public:
    //binary search
    int mySqrt(int x) {
        //corner cases
        if(x<0)return -1;
        if(x==0 || x==1)return x;
        
        int lo = 1, hi = x, mid;
        while(lo<hi)
        {
            mid = lo + (hi-lo)/2 + 1;
            //cout << mid << endl;
            if( x/mid == mid)return mid;
            if( mid > x/mid)
            {
                hi = mid-1;
            }else lo = mid;
        }
        return lo;
    }
};