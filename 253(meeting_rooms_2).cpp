#include "leetcode.h"

struct IntervalsSort{
	bool operator()(const Interval &a, const Interval &b)const{
		return a.start < b.start;
	}
};
struct Greater{
	bool operator()(const int &a, const int &b)const{
		return a > b;
	}
};
int Solution::minMeetingRooms(vector<Interval>& intervals){

	sort(intervals.begin(), intervals.end(), IntervalsSort());

	priority_queue<int, vector<int>, Greater > endTimes;
	for (int i = 0; i < intervals.size(); i++){

		if (endTimes.empty()){
			endTimes.push(intervals[i].end);
			continue;
		}
		if (intervals[i].start >= endTimes.top()){
			endTimes.pop();
			endTimes.push(intervals[i].end);
		}
		else{
			endTimes.push(intervals[i].end);
		}
	}

	return endTimes.size();

}