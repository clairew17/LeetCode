//125.Valid Palindrome.cc

#include"../CC/header.h"

inline char CaseConvert(char a){
	return (a>='a' && a <='z')?a-'a'+'A':a;
}
 
inline bool isAlphanumeric(char c){
	return ((c>='a'&&c<='z') || (c>='A'&&c<='Z')|| (c>='0'&&c<='9'));
}

bool isPalindrome(string s) {
	int n = s.size();
	if(n==0)return true;
	int i=0, j = n-1;char a,b;
	while(i<j){
		while(i<j && !isAlphanumeric(s[i]))i++;
		while(i<j && !isAlphanumeric(s[j]))j--;

		a = CaseConvert(s[i]) ;
		b = CaseConvert(s[j]);
	
		if(a!=b)return false;
		i++;j--;
	}
	return true;
}

int main(){

	return 0;
}
