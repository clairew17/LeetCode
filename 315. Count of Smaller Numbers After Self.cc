#include "../CC/hearder.h"

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int>smaller(n, 0);
        vector<pair<int, int>>enums;//index, number
        for(int i=0;i<n;i++){
            enums.push_back(make_pair(i, nums[i]));
        }
        mergeSort(enums, smaller);
        //PrintVector(smaller);
        return smaller;
    }
    void mergeSort(vector<pair<int, int>>&enums, vector<int>& smaller){
        //int n = enums.size();
        int mid = enums.size()/2;

        

        if(mid>0){
            //PrintEnum(enums);
            int m = mid, n = enums.size()-mid;
            vector<pair<int, int>>left(m), right(n);
            
            for(int i =0;i< m;i++){
                left[i] = enums[i];
                
            }
            for(int i = 0; i<n; i++){
                right[i] = enums[i+mid];
            }
            //count and sort each half
            mergeSort(left, smaller);
            mergeSort(right, smaller);
            
            //cache stored the sorted number by merge sort
            vector<pair<int, int>>cache(enums.size());
            int i = 0,  j = 0, k = 0;
            
            //count the number of value from right which are smaller than left[i]
            while(i<m || j<n){
                if(i==m || (j<n && right[j].second < left[i].second)){
                    //when right is maller than left[i]
                    cache[k++] = right[j++];
                }else{
                    //when right > left[i], j is the number of values in the right half for right is sorted
                    smaller[left[i].first] += j;
                    cache[k++] = left[i++];
                }
            }
            
            //sort enums after counting the number
            for(int i=0;i<enums.size();i++){
                enums[i] = cache[i];
            }

            //cout << "--\t";PrintEnum(enums);
        }
    }
};


