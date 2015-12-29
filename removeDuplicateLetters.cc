//removeDuplicateLetters.cc
/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"

*/
#include"header.h"
string RemoveAll(string &str, char ch);
string removeDuplicateLetters(string s){
        //sort(s.begin(),s.end());
        string res;
        vector<int>count(26,0);
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
        }

        //find the first smallest
        int pos=0;
        for(int i=0;i<s.size();i++){
            //index of smallest one
            if(s[i]<s[pos])pos=i;
            //if the last appearance of s[i], break
            if(--count[s[i]-'a']==0)break;
        }


        if(s.size()==0)return res;
        else{
            char c = s[pos];
            s = s.substr(pos+1);
            s = RemoveAll(s,c);
            res = c+removeDuplicateLetters(s);
        }
        return res;
}
string RemoveAll(string &str, char ch){
    string res;
    for(auto iter=str.begin();iter !=str.end();iter++){
        if(*iter != ch){
            res += *iter;
        }
    }
    return res;
}


int main(){

    string str = "cbacdcbc";
    //RemoveAll(str, 'c');
    //cout << RemoveAll(str, 'c') << endl;
    //cout << ("acdb"==removeDuplicateLetters(str)) << end;
    string res = removeDuplicateLetters(str);
    cout << res<< endl;

}