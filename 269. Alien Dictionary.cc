//269. Alien Dictionary.cc

#include"../CC/header.h"

string alienOrder(vector<string>& words) {
    map<char, set<char>> suc, pre;
    set<char> chars;
    string s;
    for (string t : words) {
        //set to store all chars
        chars.insert(t.begin(), t.end());
        for (int i=0; i<min(s.size(), t.size()); ++i) {
            char a = s[i], b = t[i];
            if (a != b) {
                suc[a].insert(b);
                pre[b].insert(a);
                break;
            }
        }
        s = t;
    }
    set<char> free = chars;
    for (auto p : pre)
        free.erase(p.first);
    string order;
    while (free.size()) {
        char a = *begin(free);
        free.erase(a);
        order += a;
        for (char b : suc[a]) {
            pre[b].erase(a);
            if (pre[b].empty())
                free.insert(b);
        }
    }
    return order.size() == chars.size() ? order : "";
}

int main(){
    vector<string> words = {"wrt", "wrf", "er", "ett","rftt"};
    string str = alienOrder(words);
    cout << str << endl;
    return 0;
}