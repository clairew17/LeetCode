class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res = -1;
        stack<int>nums;
        for(auto t:tokens){
            if(t == "+" || t=="-" || t=="*" || t=="/")
            {
                //int temp;
                if(nums.size()<2)
                {
                    return -1;//not enough inputs
                }
                int b = nums.top(); nums.pop();
                int a = nums.top(); nums.pop();
                if(t == "+") res = a+b;
                else if(t == "-") res = a-b;
                else if(t == "*") res = a*b;
                else if(t == "/") 
                {
                    if(b == -1)return -1;
                    res = a/b;
                }
                nums.push(res);
            }else{
                int n = stoi(t);
                nums.push(n);
            }
        }
        
        if(res==-1 && nums.size()==1){//result stored in stack
            res = nums.top();
            nums.pop();
        }
        
        return res;
    }
};