class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x!=0 && x%10==0))return false;
        int rev = 0;
        while(x>rev){//reverse half
            rev = rev*10 + x%10;
            x = x/10;
        }
        //cout << x << '\t' << rev << endl;
        return (x==rev) || (x==rev/10);//even||odd digits
    }
};