//186.ReverseWordString.cc

#include"../CC/header.h"

void reverse(string &s, int begin, int end){
    int i = begin, j = end;
    while(i<j){
        swap(s[i++],s[j--]);
    }
}
void reverseWords(string &s) {
    int n = s.size();
    reverse(s,0,n-1);
    int begin=0;
    for(int i=0;i<n;i++){
        if(s[i] ==' '){
            reverse(s,begin,i-1);
            begin = i+1;
        }
    }
    if(begin != n-1)reverse(s,begin,n-1);
}

int main(){
    string s = "the sky is blue";
    cout << s << endl;
    reverseWords(s);
    cout << s << endl;
    return 0;
}