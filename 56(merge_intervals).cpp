#include "leetcode.h"

class IntervalCompare{

public:
	bool operator()(const Interval &a, const Interval &b){

		return a.start < b.start; 
	}
}intervalCompare;

vector<Interval> Solution::mergeInterval(vector<Interval>& intervals){

	if (intervals.size() == 0 || intervals.size() == 1){
		return intervals;
	}

	sort(intervals.begin(), intervals.end(), intervalCompare);

	vector<Interval> ret;
	
	Interval current = intervals[0];

	for (int x = 1; x != intervals.size(); x++){
		
		if (current.end > intervals[x].start){

			if (current.end < intervals[x].end){
				current.end = intervals[x].end;
			}
			else{
				continue;
			}

		}
		else{
			ret.push_back(current);
			current = intervals[x]; 
		}

	}

	return ret;
	

}