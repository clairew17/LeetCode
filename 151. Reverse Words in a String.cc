//151. Reverse Words in a String.cc

class Solution {
public:

    // function to reverse any part of string from i to j (just one word or entire string)
    void reverseword(string &s, int i, int j){
        while(i<j){
          char t=s[i];
          s[i++]=s[j];
          s[j--]=t;
        } 
    }

    void reverseWords(string &s) {

        int i=0, j=0;
        int l=0;
        int len=s.size();
        int wordcount=0;

        while(true){
            while(i<len && s[i] == ' ') i++;  // skip spaces in front of the word
            if(i==len) break;
            
            if(wordcount>0) s[j++]=' ';
            l=j;
            while(i<len && s[i] != ' ')
            {
                s[j]=s[i]; 
                j++; 
                i++;
            } 
            reverseword(s,l,j-1);                // reverse word in place
            wordcount++;

        }

        s.resize(j);                           // resize result string
        reverseword(s,0,j-1);                  // reverse whole string
    }
};


int  main()
{
	string str = "   ac   bd ";
	reverseWords(str);
	cout << str<<endl;
}