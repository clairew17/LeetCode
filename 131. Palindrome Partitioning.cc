//131. Palindrome Partitioning.cc
#include"../CC/header.h"

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string>sol;
        vector<vector<string>>res;
        getPartition(s, 0, sol, res);
        return res;
    }
private:
    bool isPal(string s, int i, int j)//if s[i:j] is pal
    {
        while(i<j && s[i]==s[j])i++,j--;
        if(i>=j)return true;
        else return false;
    }
    //get palindrome from start
    void getPartition(string s, int start, vector<string>&sol, vector<vector<string>>&res)
    {
        int n = s.size();
        if(start == n)
        {
            res.push_back(sol);
            return;
        }
        
        for(int i=start;i<n;i++)
        {
            if(isPal(s, start, i)==true)//if s[start:i] is pal
            {
                sol.push_back(s.substr(start, i-start+1));

                getPartition(s, i+1, sol, res);//get pal from s[i+1:end]
                sol.pop_back();//recover
            }
        }
        
    }
};

int main()
{
	string str;cin>>str;
	cout << "Input:\t"<<str<<endl;

	Solution sol;
	vector<vector<string>>res = sol.partition(str);
	cout << "Result:\n";
	for(auto v:res)
	{
		for(auto r:v)
			cout << r << ',';
		cout <<endl;
	}

	return 0;

}