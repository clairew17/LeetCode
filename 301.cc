//301.cc

#include"../CC/header.h"


//return if s is valid parentheses
bool isValidP(string s)
{
    int cnt = 0;
    for(auto c : s)
    {
        if(c=='(')cnt++;
        if(c==')' && cnt--==0)return false;
    }
    return cnt == 0;
}

//complexity: plot tree and count the worst case
//consider the height of shortest path

void BFS(string s, vector<string> &res)
{
	//use queue to implement BFS
	//store str with same length, which also the current possible and longest str
    queue<string>q;
    q.push(s);

    //to record the visited pattern
    unordered_set<string>visit;
    
    while(!q.empty())
    {
        auto cur = q.front();q.pop();
        //check validness
        if(isValidP(cur)==true)
        {
            res.push_back(cur);
        }
        
        //try to remove 1 '(' or ')' when not valid parenthese found yet
        for(int i=0;res.empty() && i<cur.size();i++)
        {
            while(i && cur[i]==cur[i-1])i++;

            //remove only '(' or ')'
            if(cur[i]=='(' || cur[i]==')'){
                auto temp = cur.substr(0,i)+cur.substr(i+1);

                //check if current pattern has been visited
                if(visit.find(temp)==visit.end())
                {
                	q.push(temp);
                	visit.insert(temp);
                }
                
            }
        }
    }
    
}

//DFS methods
void DFS(int ind, int l, int r, string s, string &path, vector<string> &res)
{
	//terminate
	if(ind == s.size())//reach the deepest char
	{
		//if valid and longest, store results
		if(l==r){//valid
			if(res.empty() || path.size() == res[0].size())//the first or longest
			{
				res.push_back(path);
			}
		}
		//terminate
		return;
	}

	//early termination (pruning)
	if(r>l)return;//must be invalid
	if(!res.empty() && path.size() + s.size()-ind < res[0].size())return;//can not be the longest


	char c = s[ind];ind++;

	//include current char
	path.push_back(c);
	if(c=='(')
		DFS(ind, l+1, r, s, path, res);// add '('
	else if(c==')')
		DFS(ind, l, r+1, s, path, res);// add ')'
	else 
		DFS(ind, l, r, s, path, res);// add 'a'-'z'

	//exclude current char
	path.pop_back();
	if(c=='('||c==')')//bypass non letters
	{
		while( c==s[ind] )//bypass duplicates
			ind++;
		DFS(ind, l, r, s, path, res);
	}

}
vector<string> removeInvalidParentheses(string s) {
    vector<string>res;
    string path;
    //BFS(s, res);
    DFS(0,0,0,s,path,res);
    return res;
}

int main(){
	string s = ")()(e()))))))((((";
	vector<string>res = removeInvalidParentheses(s);
	for(auto r:res){
		cout << r << endl;
	}

}