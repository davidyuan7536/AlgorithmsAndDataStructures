#include "leetcode.h"

int Solution::maximumGap(vector<int>& nums){


	if (nums.size() < 2){
		return 0;
	}

	int minNum = INT_MAX;
	int maxNum = INT_MIN;
	for (auto it : nums){
		minNum = min(minNum, it);
		maxNum = max(maxNum, it);;
	}

	int gap = (maxNum - minNum) / (nums.size());

	vector<list<int>> table(nums.size(), list<int>{INT_MAX, INT_MIN});

	for (auto it : nums){

		int pos = (it-minNum) / (gap+1);
		if (it < table[pos].front()){
			table[pos].front() = it; 
		}
		if (it > table[pos].back()){
			table[pos].back() = it;
		}

	}

	int previous = minNum;
	gap = INT_MIN;
	for (auto it : table){
		if (it.front() == INT_MAX)
			continue;
		gap = max(gap, it.front() - previous);
		previous = it.back();
	}

	return gap;
}