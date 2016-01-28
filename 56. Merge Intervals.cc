/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    //return if two Intervals can be merged
    bool canMerge(Interval x, Interval y)
    {
        if(y.end<x.start || y.start>x.end)return false;
        return true;
    }
    Interval merge2interval(Interval x, Interval y)
    {
        Interval res;
        res.start = min(x.start, y.start);
        res.end = max(x.end, y.end);
        return res;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        //sort by the starting time
        sort(intervals.begin(),intervals.end(),[](Interval a, Interval b){return a.start<b.start;});
        vector<Interval>res;
        for(auto interval:intervals)
        {
            if(res.empty())
                res.push_back(interval);
            else{
                auto temp = res.back();
                //check if this interval can be merged with last interval of result
                if(canMerge(temp, interval) == true){
                    res.pop_back();//pop and store the merged interval
                    res.push_back(merge2interval(temp, interval));
                }else{//add to tail
                    res.push_back(interval);
                }
            }
        }
        return res;
    }
};