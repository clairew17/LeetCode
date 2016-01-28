class Solution {
public:

int search(vector<int>& A, int target) {
    int n = A.size();
    if(n<1)return -1;
    
    
    int lo = 0;
    int hi = n - 1;
    
    //only 1 segment is rotated, the other part is sorted
    //find the sorted segement, do binary search
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (A[mid] == target) return mid;

        if (A[lo] <= A[mid]) {//[lo:mid] is not rotated : ordinary binary search
            if (target >= A[lo] && target < A[mid]) {//target falls in [lo:mid]
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        } else {
            if (target > A[mid] && target <= A[hi]) {//target falls in [mid:hi]
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    return A[lo] == target ? lo : -1;
}

};