//324. Wiggle Sort II My Submissions Question
#include"../CC/header.h"
void wiggleSort(vector<int>& nums) {
    vector<int> res(nums);
    sort(nums.begin(), nums.end());
    int sz = ceil(nums.size()*0.5);
    for(int i = 0; i < sz; ++i){
        res[i*2] = nums[i];
        if( 2*i+1 < nums.size() )
            res[i*2+1] = nums[i+sz];
    }
    nums = res;
}

int main(){
    int arr[] = {4,5,5,6};
    vector<int>nums =  Arr2Vec(arr, sizeof(arr)/sizeof(int));
    PrintVector(nums);
    wiggleSort(nums);
    PrintVector(nums);
    return 0;
}