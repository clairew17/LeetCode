class Solution {
public:
//binary search: pow(x, n) = pow(x*x, n/2) : x *pow(x*x, (n-1)/2)
    double myPow(double x, int n) {
        if(x==0)return 0;
        
        //terminal of recursion: n==0
        if(n==0)return 1;
        if(n==1)return x;
        
        if(n<0){//n<0
            n = -n;
            x = 1/x;
        }
        
        if(n%2==0)//even
        {
            return myPow(x*x, n/2);
        }else{//odd
            return x*myPow(x*x, (n-1)/2);
        }
    }
};


class Solution {
public:
//binary search: pow(x, n) = pow(x*x, n/2) : x *pow(x*x, (n-1)/2)
    double myPow(double x, int n) {
        if(x==0)return 0;
        
        //terminal of recursion: n==0
        if(n==0)return 1;
        if(n==1)return x;
        
        if(n<0){//n<0
            n = -n;
            x = 1/x;
        }
        
        double temp = myPow(x, n/2);
        if(n%2==0)//even
        {
            return temp*temp;
        }else{//odd
            return x*temp*temp;
        }
        
        
    }
};