//207. Course Schedule.cc
#include"../CC/header.h"

//BFS method
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>>graph(numCourses);
        vector<int>degree(numCourses);
        
        //graph[pre]:courses which require 'pre'
        for(auto p:prerequisites)
        {
            graph[p.second].insert(p.first);
            
        }
        
        //compute the num of pre of each course
        for(auto courses:graph)
        {
            for(auto course:courses)
            {
                degree[course]++;
            }
        }
        
        //non leaf course with pres
        unordered_set<int>nonLeaf;
        //course without pres
        queue<int>Leaf;
        for (int i = 0; i < numCourses; i++) {
            if(degree[i]==0){
                Leaf.push(i);
            }else{
                nonLeaf.insert(i);
            }
        }
        
        while(!Leaf.empty() && !nonLeaf.empty())
        {
            int l = Leaf.front();Leaf.pop();
            for(auto course:graph[l])
            {
                //take course
                degree[course]--;
                if(degree[course]==0)
                {
                    //update leaf
                    Leaf.push(course);
                    nonLeaf.erase(course);
                    if(nonLeaf.empty())return true;
                }
            }
        }
        return nonLeaf.empty();
    }
};


class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = compute_indegree(graph);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++)
                if (degrees[j]==0) break;//find the first course with no pre
            if (j == numCourses) return false;
            degrees[j] = -1;
            for (int neigh : graph[j])//reduce degree
                degrees[neigh]--;
        }
        return true;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>>graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);//pre:course which require this course
        return graph;
    }
    vector<int> compute_indegree(vector<unordered_set<int>>& graph) {
        vector<int> degrees(graph.size(), 0);
        for (auto neighbors : graph)//courses which require course i
            for (int neigh : neighbors)
                degrees[neigh]++;//pre requisite # of this course
        return degrees;
    }
}; 


//DFS SOLUTION
class Solution {
private:
    vector<unordered_set<int>> buildGraph(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        vector<unordered_set<int>>graph(numCourses);
        for(auto p:prerequisites)
        {
            graph[p.second].insert(p.first);
        }
        return graph;
    }
    bool dfs_cycle(vector<unordered_set<int>>&graph, int node, vector<bool>&visited, vector<bool>&onPath)
    {
        //if node has been visited: bypass
        if(visited[node]==true)return false;
        //mark node as visited and on the path
        visited[node]=onPath[node]=true;
        for(auto cur:graph[node]){
            //cur is already on path or detect cycle after cur: cycle
            if(onPath[cur] || dfs_cycle(graph, cur, visited, onPath)==true)return true;
        }
        //remove node from path
        onPath[node]=false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        //pre course i : courses require i as pre
        vector<unordered_set<int>>graph = buildGraph(numCourses, prerequisites);
        vector<bool>visited(numCourses, false);//if the node has been visited
        vector<bool>onPath(numCourses, false);//if the node is on current path
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i]==false && dfs_cycle(graph, i,visited, onPath)==true)return false;
        }
        return true;
    }
};



int main(){
	int numCourses = 10;
	vector<pair<int, int>> prerequisites = {{5,6},{0,2},{1,7},{5,9},{1,8},{3,4},{0,6},{0,7},{0,3},{8,9}};
	cout << canFinish(numCourses, prerequisites)<<endl;

}