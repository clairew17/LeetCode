269. Alien Dictionary.cc

class Solution {
public:

bool dfs(unordered_map<char, unordered_set<char>>& g, unordered_set<char>& visited, unordered_set<char>& rec, string& order, char n){
    if (rec.count(n)) return false;
    if (visited.count(n)) return true;

    visited.insert(n);
    rec.insert(n);

    for (auto iter = g[n].begin(); iter != g[n].end(); ++iter)
        if (dfs(g, visited, rec, order, *iter) == false)
            return false;

    rec.erase(rec.find(n));
    order += string(1, n);

    return true;
}

string topsort(unordered_map<char, unordered_set<char>>& g) {
    unordered_set<char> visited;
    unordered_set<char> rec;
    string order;

    for (auto iter = g.begin(); iter != g.end(); ++iter) {
        if (dfs(g, visited, rec, order, iter->first) == false)
            return "";
    }

    reverse(order.begin(), order.end());
    return order;
}

string alienOrder(vector<string>& words) {
    if (words.size() == 1) return words.front();

    unordered_map<char, unordered_set<char>> g;
    for (int i = 1; i < words.size(); i++) {
        string t1 = words[i - 1];
        string t2 = words[i];           
        bool found = false;
        for (int j = 0; j < max(t1.length(), t2.length()); j++) {
            if (j < t1.length() && g.count(t1[j]) == 0)
                g.insert(make_pair(t1[j], unordered_set<char>()));
            if (j < t2.length() && g.count(t2[j]) == 0)
                g.insert(make_pair(t2[j], unordered_set<char>()));
            if (j < t1.length() && j < t2.length() && t1[j] != t2[j] && !found) {
                g[t1[j]].insert(t2[j]);
                found = true;
            }
        }
    }

    return topsort(g);
}
};