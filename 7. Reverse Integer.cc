//corner cases:
#include"../CC/header.h"

//positive, negative
//INT_MAX: 2147483647
//INT_MIN = -2147483648

//overflow after reverse


class Solution {
public:
//take care of the corner cases
    int reverse(int x) {
        if(x==0)return x;
        int flag = x<0?-1:1;
        x = flag*x;
        int res = 0;
        while(x>0){
            //check to avoid overflow
            if(res>INT_MAX/10)return 0;
            res = res*10 + x%10;
            x /= 10;
        }
        
        return flag*res;
    }
};


int main(){

    cout << INT_MAX << endl;
    cout << INT_MIN << endl;
    return 0;
}