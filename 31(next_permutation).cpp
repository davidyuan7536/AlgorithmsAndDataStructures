#include "leetcode.h"

void Solution::nextPermutation(vector<int>& nums){

	if (nums.size() <= 1){
		return;
	}


	int i = nums.size() - 2;
	vector<int> minIndex;
	minIndex.push_back(nums.size() - 1);

	bool reversed = false;
	for (; i >= 0; i--){
		if (nums[minIndex.back()] > nums[i]){
			while (!minIndex.empty() && nums[minIndex.back()] > nums[i]){
				minIndex.pop_back();
			}
			if (minIndex.empty()){
				int temp = nums[nums.size()-1];
				nums[nums.size()-1] = nums[i];
				nums[i] = temp;
			}
			else{
				int temp = nums[minIndex.back() - 1];
				nums[minIndex.back() - 1] = nums[i];
				nums[i] = temp;
			}
			reversed = true;
			break;
		}
		else{
			minIndex.push_back(i);
		}
	}

	if (!reversed){
		reverse(nums.begin(), nums.end());
	}
	else{
		sort(nums.begin() + i+1, nums.end());
	}

}