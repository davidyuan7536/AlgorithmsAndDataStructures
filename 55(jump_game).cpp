#include "leetcode.h"



bool Solution::canJump(vector<int>& nums){

	int maxPos = 0;
	for (int x = 0; x <= maxPos && maxPos < nums.size()-1; x++){
		if (nums[x] + x > maxPos){
			maxPos = nums[x] + x; 
		}
	}

	return maxPos >= nums.size() - 1 ? true : false;

}