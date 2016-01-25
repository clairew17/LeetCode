243. Shortest Word Distance.cc
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int w1 = -1, w2 = -1;
        int dis = n;
        for(int i=0;i<n;i++){
            if(words[i] == word1)w1 = i; 
            if(words[i] == word2)w2 = i;
            if(w1!=-1 && w2!= -1)dis = min(dis, abs(w2-w1));
        }
        return dis;
    }
};