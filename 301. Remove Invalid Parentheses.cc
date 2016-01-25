//301. Remove Invalid Parentheses.cc


//BFS solution
class Solution {
private:
    unordered_set<string>visit;//store all possible solutions
    bool validParenthes(string s){
        int cnt = 0;
        for(auto c:s)
        {
            if(c=='(')cnt++;
            if(c==')' && cnt-- ==0)return false;
        }
        return cnt==0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string>res;
        queue<string>q;//BFS queue
        q.push(s);
        //if found valid parenthese
        bool found = false;
        while(!q.empty())
        {
            //check str in queue 
            //1) is the first
            //2) have same length with the found str 
            auto cur = q.front();q.pop();
            if(validParenthes(cur)==true)//valid parentheses
            {
                res.push_back(cur);
                found = true;
            }

            //remove when found == false
            if(found==false)
            {
                for(int i=0;i<cur.size();i++)
                {
                    if(cur[i]=='('||cur[i]==')'){
                        //remove cur[i]
                        auto temp = cur.substr(0,i)+cur.substr(i+1);
                        if(visit.find(temp)==visit.end())
                        {
                            visit.insert(temp);
                            q.push(temp);
                        }
                    }
                }
            }


        }
        
        return res;
    }
};


//DFS solution

class Solution {
public:
    void DFS(int ind, int l, int r, string s, string &path, vector<string>&res)
    {
        if(r>l)return;//invalid parrentheses
        if(ind == s.size()){
            if(r==l && (res.empty() || path.size()>=res[0].size()))//1st path or longest path
            {
                res.push_back(path);
            }
            return;
        }
        //if longest possible path is shorter than existed path, early terminate
        if(!res.empty() && s.size()-ind + path.size()<res[0].size())return;
        char c = s[ind];ind++;
        
        //include c
        path.push_back(c);
        if(c=='(')DFS(ind, l+1, r, s, path, res);
        else if(c==')')DFS(ind, l, r+1, s, path, res);
        else DFS(ind, l, r, s, path, res);
        
        //exclude c
        path.pop_back();
        if(c=='(' || c==')')
        {
            while(c==s[ind])ind++;
            DFS(ind, l, r, s, path, res);
        }
        
    }
    
    vector<string> removeInvalidParentheses(string s)
    {
        vector<string>res;
        string path;
        DFS(0, 0, 0, s, path, res);
        return res;
    }
};
