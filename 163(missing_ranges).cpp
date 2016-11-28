#include "leetcode.h"

vector<string> Solution::findMissingRanges(vector<int>& nums, int lower, int upper){


	vector<string> ret;
	if (nums.empty()){
		if (upper > lower){
			ret.push_back(to_string(lower) + "->" + to_string(upper));
			return ret;
		}
		else{
			ret.push_back(to_string(lower));
			return ret;
		}
	}

	int prev = lower;
	for (int i = 0; i < nums.size(); i++){
		if (i == 0){
			if (prev == INT_MIN && nums[i] == INT_MIN){
				continue;
			}
			if (nums[i] - 1 > prev){
				ret.push_back(to_string(prev) + "->" + to_string(nums[i] - 1));
			}
			else if (nums[i] > prev){
				ret.push_back(to_string(prev));
			}
		}

		else if (nums[i] - 2 > prev){
			ret.push_back(to_string(prev + 1) + "->" + to_string(nums[i] - 1));

		}
		else if (nums[i] - 1 > prev){
			ret.push_back(to_string(prev + 1));

		}
		prev = nums[i];
	}

	if (upper - 1 > prev){
		ret.push_back(to_string(prev + 1) + "->" + to_string(upper));
	}
	else if (upper > prev){
		ret.push_back(to_string(upper));
	}

	return ret;
}