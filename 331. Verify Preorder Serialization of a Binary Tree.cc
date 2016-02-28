class Solution {
public:
    bool isValidSerialization(string preorder) {
        istringstream ss(preorder);
        string token;
        int diff = 1;//# of children to remove
        while(getline(ss, token, ',')){
            if(--diff < 0)return false; // decrement
            if(token.compare("#")!=0)diff+=2;//not leaf add 2
        }
        return diff==0;
    }
};