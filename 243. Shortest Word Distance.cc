243. Shortest Word Distance.cc
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        map<string, vector<int>>m;
        if(word1==word2)return 0;
        int pos1=-1, pos2=-1, res= INT_MAX;
        for(int i=0;i<words.size();i++){
            string w = words[i];
            if(w==word1){
                if(pos2!=-1)res = min(res, i-pos2);
                pos1=i;
            }
            if(w==word2){
                pos2=i;
                if(pos1!=-1)res = min(res, i-pos1);
            }
            
        }
       
        return res;
        
    }
};