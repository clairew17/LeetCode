class Solution {
public:
    bool isValid(string str) {
        map<char, char>m;//map rightP:leftP
        m[')'] = '(';
        m[']'] = '[';
        m['}'] = '{';
        
        stack<char>s;
        for(auto c:str){
            if(m.find(c)==m.end()){//left
                s.push(c);
            }else{//right
                if(s.empty() || s.top()!=m[c])return false;
                else s.pop();
            }
        }
        return s.empty();
    }
};