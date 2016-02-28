class Solution {
private:
    vector<unordered_set<int>> buildGraph(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        //graph of pre course: course require this pre course
        vector<unordered_set<int>>graph(numCourses);
        
        for(auto p:prerequisites)
        {
            graph[p.second].insert(p.first);//pre: set of courses require this course
        }
        return graph;
    }
    bool dfs_cycle(vector<unordered_set<int>>&graph, int node, vector<bool>&visited, vector<bool>&onPath, vector<int>&res)
    {
        //if node has been visited: bypass
        if(visited[node]==true)return false;
        //mark node as visited and on the path
        visited[node]=onPath[node]=true;
        for(auto cur:graph[node]){
            //cur is already on path or detect cycle after cur: cycle
            if(onPath[cur] || dfs_cycle(graph, cur, visited, onPath, res)==true){
                return true;
            }
        }
        //remove node from path
        onPath[node]=false;
        //insert node
        res.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        //pre course i : courses require i as pre
        vector<unordered_set<int>>graph = buildGraph(numCourses, prerequisites);
        vector<bool>visited(numCourses, false);//if the node has been visited
        vector<bool>onPath(numCourses, false);//if the node is on current path
        vector<int>res;
        for(int i=0;i<numCourses;i++)
        {   
            if(visited[i]==false && dfs_cycle(graph, i,visited, onPath, res)==true)return {};
        }
        //reverse order
        reverse(res.begin(), res.end());
        return res;
    }
};