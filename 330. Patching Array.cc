class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        //vector<int>added;
        int added_num = 0;
        long miss = 1, i = 0; // use long to avoid overflow
        while(miss<=n){
            int patch_num;
            if(i<nums.size() && nums[i]<=miss){//in the range [0, miss), no need to patch
                patch_num = nums[i];//extend the range by adding nums[i]
                i++;
            }else{//out of range
                //patch miss to achieve maximal sum range
                //cout << miss << endl;
                //added.push_back(miss);
                added_num++;
                patch_num = miss;
            }
            miss += patch_num;
        }
        return added_num;
    }
};