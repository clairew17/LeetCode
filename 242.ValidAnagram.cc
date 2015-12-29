//242.ValidAnagram.cc

bool isAnagram(string s, string t) {
    if(s.empty() && t.empty() )return true;
	if(s.empty() || t.empty() || s.size() != t.size())return false;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return s==t;
}