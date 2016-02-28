class Solution {
public:
    vector<string>route;
    map<string, multiset<string>>m;
    void visit(string airport){
        
        while(!m[airport].empty()){
            string next  = *m[airport].begin();
            m[airport].erase(m[airport].begin());
            visit(next);
        }
        //backtracking to add a city after succeed
        route.push_back(airport);

        
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for(auto ticket:tickets){
            m[ticket.first].insert(ticket.second);
        }
        visit("JFK");
        reverse(route.begin(), route.end());
        return route;
    }
};


class Solution {
public:
  vector<string> findItinerary(vector<pair<string, string>> tickets) {
    hash.clear();
    num_airport = tickets.size() + 1;
    for (const auto& p : tickets) 
    ++hash[p.first][p.second];

    path.push_back("JFK");
    
    dfs("JFK");
    return path;
  }

private:
  unordered_map<string, map<string, int>> hash;
  int num_airport;
  vector<string> path;
  
  bool dfs(string from) {
    if (path.size() == num_airport) return true;

    if (hash.find(from) == hash.end()) return false;
    
    map<string, int> to_list = hash[from];
    
    for (const auto& it : to_list) {
      if (it.second == 0) continue;

      string to = it.first;
      path.push_back(to);//add to path
      --hash[from][to];
      
      if (dfs(to)) return true;//if an iteritary found
      
      path.pop_back();//remove
      ++hash[from][to];//recover
    }
    
    return false;
  }


};
