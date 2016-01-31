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