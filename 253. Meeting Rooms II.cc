253. Meeting Rooms II.cc
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
    int minMeetingRooms(vector<Interval>& intervals) {

        sort(intervals.begin(),intervals.end(),[](Interval &a, Interval&b){return a.start < b.start;});
        vector<vector<Interval>>rooms;
        for(auto i:intervals){
            int ind = FindNonOverlap(rooms, i);
            if(rooms.empty() || ind == -1){
                rooms.push_back({i});
            }else{
                rooms[ind].push_back(i);
            }
        }
        return rooms.size();
    
    }
    
    int FindNonOverlap(vector<vector<Interval>>rooms, Interval time){
        for(int i=0;i<rooms.size();i++){
            if(time.start >= rooms[i].back().end)return i;
        }
        return -1;
    }
};



int minMeetingRooms(vector<Interval>& intervals) {
        
        map<int, int>m;
        for(auto it:intervals){
            m[it.start] += 1;
            m[it.end] -= 1;
        }
        int maxRoom = 0, room = 0;
        for(auto mm:m){
            room += mm.second;
            //cout << room << endl;
            maxRoom = max(maxRoom, room);
        }
        return maxRoom;
    }