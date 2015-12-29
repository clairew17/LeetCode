//252.MeetingRooms.cc
#include"header.h"
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
 };

 bool canAttendMeetings(vector<Interval>& intervals) {
 		sort(intervals.begin(), intervals.end(),[](Interval &a, Interval &b){
 			return a.start < b.start;
 		});
 		/*for(auto i:intervals){
 			cout << i.start << ','<<i.end <<endl;
 		}*/
 		for(int i=1;i<intervals.size();i++){
 			if(intervals[i].start < intervals[i-1].end)return false;
 		}
        return true;
 }

int minMeetingRooms(vector<Interval>& intervals) {
	vector<last>MeetingRooms;
	sort(intervals.begin(), intervals.end(),[](Interval &a, Interval &b){
 			return a.start < b.start;});
	for(int i=1;i<intervals.size();i++){
		if(MeetingRooms.empty())MeetingRooms.push_back(intervals[i].end);
		else{
			
		}
	}

}

 int main(){
 	vector<Interval>intervals = {Interval(5, 10),Interval(0, 30),Interval(15, 20)};
 	
 	cout << Result[canAttendMeetings(intervals)];
 	return 0;
 }