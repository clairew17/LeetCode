#include"header.h"

vector<string>result = {"word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"};


void helper(string word, vector<string>&res, int begin, string abbr, bool PrevNum) {
	if(begin == word.size()){
		res.push_back(abbr);
		return;
  	}
  	// not abbrived with number
  	helper(word, res, begin+1, abbr+word[begin],false);
  	if(!PrevNum){
  		for(int len = 1; begin+len<=word.size();len++){
  			helper(word, res, begin+len, abbr+to_string(len),true);
  		}
  	}


}

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