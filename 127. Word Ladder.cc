//127. Word Ladder.cc

#include"../CC/header.h"
class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::unordered_set<std::string> &dict) {
        if (beginWord == endWord)
            return 1;
        std::unordered_set<std::string> words1, words2;
        words1.insert(beginWord);
        words2.insert(endWord);
        dict.erase(beginWord);
        dict.erase(endWord);
        return ladderLengthHelper(words1, words2, dict, 1);
    }

private:
    int ladderLengthHelper(std::unordered_set<std::string> &words1, std::unordered_set<std::string> &words2, std::unordered_set<std::string> &dict, int level) {
        if (words1.empty())
            return 0;
        if (words1.size() > words2.size())
            return ladderLengthHelper(words2, words1, dict, level);

        std::unordered_set<std::string> words3;
        for (auto it = words1.begin(); it != words1.end(); ++it) {
            std::string word = *it;
            for (auto ch = word.begin(); ch != word.end(); ++ch) {
                char tmp = *ch;
                for (*ch = 'a'; *ch <= 'z'; ++(*ch))
                    if (*ch != tmp){
                        if (words2.find(word) != words2.end())
                            return level + 1;
                        else if (dict.find(word) != dict.end()) {
                            dict.erase(word);
                            words3.insert(word);
                        }
                    }
                *ch = tmp;
            }
        }
        return ladderLengthHelper(words2, words3, dict, level + 1);
    }
};


int main(){
	string beginWord = "hit";
	string endWord = "cog";
	unordered_set<string> wordList = {"hot","dot","dog","lot","log"};
	Solution s;
	cout << s.ladderLength(beginWord, endWord, wordList)<<endl;


	return 0;
}