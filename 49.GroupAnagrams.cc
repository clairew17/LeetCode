//49.GroupAnagrams.cc
/*

Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.

*/
#include"../CC/header.h"




vector<vector<string>> groupAnagrams(vector<string>& strs){
	unordered_map<string,vector<string>>m;
	vector<vector<string>>res;
	string temp;
	//vector<string>sol;
	
	sort(strs.begin(),strs.end());
	for(auto str:strs){
		temp = str;
		sort(temp.begin(), temp.end());
		if(m.find(temp)==m.end()){
			vector<string>sol(1,str);
			m[temp]= sol;
		}else{
			m[temp].push_back(str);
		}
	}
	for(auto mm:m){
		res.push_back(mm.second);
	}
	return res;
}

int main(){
	return 0;
}