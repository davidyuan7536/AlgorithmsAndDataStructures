#include "leetcode.h"

vector<string> Solution::summaryRanges(vector<int>& nums){

	vector<string> ret; 
	if (nums.empty()){
		return ret;
	}

	int prev = nums[0];
	for (int i = 1; i < nums.size(); i++){
		if (nums[i] != nums[i - 1] + 1){
			if(prev == nums[i - 1]){
				ret.push_back(to_string(prev));
			}
			else{
				ret.push_back(to_string(prev) + "->" + to_string(nums[i - 1]));
			}
			prev = nums[i];
		}
	}
	if (prev == nums.back()){
		ret.push_back(to_string(prev));
	}
	else{
		ret.push_back(to_string(prev) + "->" + to_string(nums.back()));
	}
	return ret;
}