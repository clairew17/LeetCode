#include"header.h"

vector<string>result = {"word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"};


class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string>res;
        helper(res, word, "",0,false);
        return res;
    }
    void helper(vector<string>&res, string word, string abbr, int begin, bool PrevNum){
        if(begin == word.size()){
            res.push_back(abbr);
            return;
        }
        //not abbrieve 
        helper(res, word, abbr+word[begin],begin+1,false);
        
        if(!PrevNum){
            for(int len = 1; len+begin<=word.size();len++){        
                helper(res, word, abbr+to_string(len),begin+len,true);
            }
        }
        
    }
};

int main(){

	string word = "word";
	vector<string> res;
	helper(word, res, 0, "",false);
	for(auto s:res){
		cout << s <<',';
	}
	cout << endl;
	for(auto s:result){
		cout << s <<',';
	}
	cout << endl;

	return 0;
}