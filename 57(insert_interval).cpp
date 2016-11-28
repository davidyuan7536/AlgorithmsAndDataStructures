#include "leetcode.h"


int binaryIntervalSearch(vector<Interval> &intervals, Interval &newInterval, int front, int back, bool first){

	if (front == back){
		return front;
	}
	
	if (back < 0){
		return -1;
	}
	if (front >= intervals.size()){
		return intervals.size();
	}

	int mid = front + (back - front) / 2;

	if (first){
		if ((mid > 0 && newInterval.start < intervals[mid].end && newInterval.start > intervals[mid - 1].end) || newInterval.start == intervals[mid].end){
			return mid;
		}
		else if (newInterval.start < intervals[mid].end){
			return binaryIntervalSearch(intervals, newInterval, front, mid - 1, first);
		}
		else if (newInterval.start > intervals[mid].end){
			return binaryIntervalSearch(intervals, newInterval, mid+1, back, first);
		}

	}
	else{
		if ((mid < back && newInterval.end > intervals[mid].start && newInterval.end < intervals[mid+1].start) || newInterval.end == intervals[mid].start){
			return mid;
		}
		else if (newInterval.end > intervals[mid].start){
			return binaryIntervalSearch(intervals, newInterval, mid+1, back, first);
		}
		else if (newInterval.end < intervals[mid].start){
			return binaryIntervalSearch(intervals, newInterval, front, mid-1, first);
		}
	}

	
}


vector<Interval> Solution::insertInterval(vector<Interval>& intervals, Interval newInterval){


	vector<Interval> ret = intervals;
	if (intervals.empty()){
		ret.push_back(newInterval);
		return ret;
	}

	int left = binaryIntervalSearch(intervals, newInterval, 0, intervals.size() - 1, true);
	int right = binaryIntervalSearch(intervals, newInterval, 0, intervals.size() - 1, false);

	if (left == right){
		if (left == -1){
			ret.insert(ret.begin(), newInterval);
		}
		else if (left == intervals.size()){
			ret.push_back(newInterval);
		}
		else{
			ret[left].start = min(ret[left].start, newInterval.start);
			ret[left].end = max(ret[left].end, newInterval.end);
		}
	}
	
	else{
		if (left == -1 && right == intervals.size()){
			ret.clear();
			ret.push_back(newInterval);
			return ret;
		}
		else if (left == -1){
			left = 0;
		}
		else if (right == intervals.size()){
			right = intervals.size() - 1;
		}
		
		ret[left].start = min(ret[left].start, newInterval.start);
		ret[left].end = max(ret[right].end, newInterval.end);
		ret.erase(ret.begin() + left + 1, ret.begin() + right + 1);
	}
	
	for (auto it : ret){
		cout << it.start << " - " << it.end << endl;
	}
	return ret;
}