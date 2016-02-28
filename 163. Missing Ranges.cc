//163. Missing Ranges.cc


	string get_range(int start, int end)
    {
    	if(start == end)return to_string(start);
        return to_string(start)+"->"+to_string(end);
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        int pre = lower-1;
        for(int i =0; i <= nums.size(); i++)
        {
           int cur = (i==nums.size()? upper+1:nums[i]);
           if(cur-pre>1)result.push_back(get_range(pre+1,cur-1));
            pre = cur;
        }
        return result;
    }


class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string>res;
        long pre = lower-1;
        int ms,me;
        bool is_miss = false;
        for(auto num:nums){
            if(num!=pre+1){//start of missing range
                ms = pre+1;
                me = num-1;
                string range = to_string(ms);
                if(me!=ms) range += ("->"+to_string(me));
                res.push_back(range);
            }
            //record the last num
            pre = num;
        }
        //for the last missing range
        if(pre!=upper){
            ms = pre+1;
            me = upper;
            string range = to_string(ms);
            if(me!=ms) range += ("->"+to_string(me));
            res.push_back(range);
        }
        return res;
    }
};