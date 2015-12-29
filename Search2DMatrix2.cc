//Search2DMatrix2.cc
//Leetcode Search 2D matrix II

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n=matrix[0].size();
        if(m==0 || n==0)return false;
        int firstRow = 0;
        int lastRow = SearchLastRow(matrix,target);
        if(lastRow==-1 || lastRow>=m)return false;
        
        for(int i=firstRow;i<=lastRow;i++){
            if(BinarySearch(matrix[i],target))return true;
        }
        return false;
    }
    //find the last row which satisfies matrix[row][0]<=target
    int SearchLastRow(vector<vector<int>>& matrix, int target){
        int m = matrix.size(),n=matrix[0].size();
        if(m==0 || n==0)return -1;
        int lo=0,hi=m-1,mid;
        while(lo<hi){
            mid = (lo+hi)/2+1;//ceiling to access the right boundary
            if(matrix[mid][0]>target)hi=mid-1;
            else lo = mid;
        }
        if(matrix[lo][0]<=target)return lo;
        else return -1;
        
    }
    
    bool BinarySearch(vector<int>&nums, int target){
        int n = nums.size();
        if(n<1)return false;
        int lo =0,hi=n-1,mid;
        while(lo<hi){
            mid = (lo+hi)/2;
            if(nums[mid]==target)return true;
            if(nums[mid]>target)hi=mid-1;
            else lo=mid+1;
        }
        if(lo==hi)return nums[lo]==target;
        else return false;
        
    }
    
    
};