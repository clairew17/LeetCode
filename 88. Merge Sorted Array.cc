class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)return;
        if(m==0){swap(nums1,nums2);return;}
        
        //copy nums1's value to the latter part of nums1
        int i = 0;
        while(i<m){
            nums1[n+m-1-i]=nums1[m-1-i];
            i++;
        }
        
        int j =0, k = 0;
        i = n;
        while(i<m+n || j<n)
        {
            if(j==n || (i<m+n && nums1[i]<nums2[j]))
            {
                cout << nums1[i] <<endl; 
                nums1[k++]=nums1[i++];
            }else if(i==n+m || (j<n && nums1[i]>=nums2[j])){
                cout << nums2[j] <<endl; 
                nums1[k++]=nums2[j++];
            }
        }
        
    }
};


class Solution {
public:
    //merge from tail
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1;
        int k = m+n-1;
        while(j>=0)
        {
            
            if(i<0 || nums1[i]<nums2[j])
            {
                nums1[k--] = nums2[j--];
            }else{
                nums1[k--] = nums1[i--];
            }
        }
        
    }
};