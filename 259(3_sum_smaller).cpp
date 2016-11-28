#include "leetcode.h"

int Solution::threeSumSmaller(vector<int>& nums, int target){

	if (nums.size() < 3){
		return 0; 
	}
	sort(nums.begin(), nums.end());
	
	int counter = 0;
	
	for (int small = 0; small <= nums.size() - 3; small++){
		int i = small + 1;
		int big = nums.size() - 1;
		while(big > i){
			if (nums[small] + nums[i] + nums[big] < target){
				counter += big - i;
				i++;
			}
			else
				big--;
		}
	
	}

	return counter;
}