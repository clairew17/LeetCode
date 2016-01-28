//274. H-Index.cc


/*

 index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each.

*/


class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==0)return 0;
        sort(citations.begin(),citations.end());
        int n =citations.size();
        for(int i=0;i<n;i++){

        	//find the first 
            if(citations[i] >= n-i){
                return n-i;
            }
        }
        return 0;
    }
};