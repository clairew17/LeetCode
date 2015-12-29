//290.WordPattern.cc
#include"header.h"

string Result[2]={"False\n", "True\n"};
bool wordPattern(string pattern, string str){
        map<char,string>m;
        int p=0, found;
        string s = str,word;
        while(!s.empty()){
            found = s.find_first_of(" ");
            if(found!=string::npos){
                word = s.substr(0,found);
                s = s.substr(found+1);
            }else{
                word = s;
                s = "";
            }
            cout <<pattern[p] << '\t'<< word <<endl;
            if(m.find(pattern[p])!=m.end()){
                if(m[pattern[p]] != word)return false;
            }else{
                m[pattern[p]] = word;
            }
            p++;
        }
        return (p==pattern.size() && s.empty());
}

int main(){
    string pattern = "abba", str = "dog cat cat dog";
    //string pattern = "abba", str = "dog cat cat fish";
    cout << Result[wordPattern(pattern,str)];
    return 0;
}