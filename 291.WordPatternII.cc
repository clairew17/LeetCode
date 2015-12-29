//291.WordPatternII.cc
#include"header.h"

map<char,string>PS;
std::set<string>st;

bool wordPattern(string pattern, int i, string str, int j){
        int m = pattern.size(), n = str.size();
        if(i==m && j==n)return true;
        if(i==m || j==n)return false;
        char c = pattern[i];

        if(PS.find(c) != PS.end()){
            string ss = PS[c];
            int l = ss.size();
            if(ss != str.substr(0,l))return false;
            else return wordPattern(pattern,i+1,str,j+l);
        }

       for(int k=i;k<n;k++){
            int l  = k-i+1;
            string ss = str.substr(i,l);
            if(st.find(ss) != st.end())continue;
            st.insert(ss);
            PS[c] = ss;
            if(wordPattern(pattern,i+1,str,k+1))return true;
            st.erase(ss);
            PS.erase(c);
       }
       return false;
}

int main(){
    string pattern = "abba", str = "dog cat cat dog";
    //string pattern = "abba", str = "dog cat cat fish";
    cout << Result[wordPattern(pattern,0,str,0)];
    return 0;
}