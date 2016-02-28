#include "../CC/header.h"
/*
class Solution{
    public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long>sums(n + 1,0);
        for (int i = 0; i < n; ++i)
            sums[i + 1] = sums[i] + nums[i];
        return countWhileMergeSort(sums, 0, n + 1, lower, upper);
    }

    int countWhileMergeSort(vector<long>& sums, int start, int end, int lower, int upper) {
        if (end - start <= 1) return 0;
        int mid = (start + end)/2;
        int count = countWhileMergeSort(sums, start, mid, lower, upper)
                  + countWhileMergeSort(sums, mid, end, lower, upper);
                  
        int j = mid, k = mid, t = mid;
        
        vector<long>cache(end - start);
        
        for (int i = start, r = 0; i < mid; i++, r++) {
            while (k < end && sums[k] - sums[i] < lower) 
                k++;
            while (j < end && sums[j] - sums[i] <= upper) 
                j++;
            //copy number smaller than sums[i]
            while (t < end && sums[t] < sums[i]) 
                cache[r++] = sums[t++];
            
            cout << "j="<<j << ",k=" <<k <<endl;  
            cache[r] = sums[i];
            count += j - k;
        }
        for(int i = start;i < t;i++){
            sums[i] = cache[i-start];
        }
        return count;
    }
};

*/
class Solution {
public:
    int countMergeSort(vector<long> &sums, int lower, int upper) {
        int mid = sums.size()/2;
        int cnt = 0;
        //cout << enums.size() << endl;
        if(mid>0){
            //PrintVector<long>(sums);

            int m = mid, n = sums.size()-mid;
            vector<long> left(m), right(n);
            for(int i=0;i<m;i++)left[i] = sums[i];
            for(int i=0;i<n;i++)right[i] = sums[i+mid];
            
            cnt = countMergeSort(left, lower, upper) + countMergeSort(right, lower, upper);
            
            vector<long> cache(sums.size(),0);
            cout << "l: ";PrintVector<long>(left); cout << "r: ";PrintVector<long>(right);
            int j =0, k = 0, r = 0;
            int l=0, c = 0;
            //for(int l=0, c = 0; l<m; l++, c++){
            while(l<m){
                //first right in range
                while(l<m && j<n && right[j] - left[l]<lower)
                    j++;
                //last right in range
                while(l<m && k<n && right[k] - left[l] <= upper)
                    k++;

                if(l<m){
                    cout << "=== \tj="<<j << ",k=" <<k <<endl;  
                    cnt += k-j;
                }
                while(l==m || (r<n && right[r] < left[l]))
                    cache[c++] = right[r++];
                cache[c++] = left[l++];
            }
            //continue to merge
            while(r<n)cache[c++] = right[r++];

            //copy after sort
            for(int i = 0; i<sums.size();i++){
                sums[i] = cache[i];
            }
        }
        return cnt;
        
    }

    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long>sums(nums.size()+1, 0);

        for(int i=0;i<nums.size();i++){
            sums[i+1] = sums[i]+nums[i];
        }
        int cnt = countMergeSort(sums, lower, upper);
        return cnt;
    }
};


int main(){
    vector<int>nums = {0,-1,1,2,-3,-3};//{2147483647,-2147483648,-1,0};//{-2147483647,0,-2147483647,2147483647};//{-2, 5, -1};//
    //PrintVector<int>(nums);

    //int lower = -2, upper = 2;
    int lower = -3, upper = 1;

    Solution sol;
    cout << sol.countRangeSum(nums, lower, upper) << endl;
    return 0;
}