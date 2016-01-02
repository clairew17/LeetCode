//288.UniqueWordAbbreviation.cc


class ValidWordAbbr {
private:
	unordered_map<string, unordered_set<string>>mp;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(auto d:dictionary){
        	string abbr = d[0] + to_string(d.size()) + d[d.size()-1];
        	mp[abbr].insert(d);
        }
    }

    bool isUnique(string word) {
        string abbr = word[0] + to_string(word.size()) + word[word.size()-1];
        return mp[abbr].size() == mp[abbr].count(word);
    }
};