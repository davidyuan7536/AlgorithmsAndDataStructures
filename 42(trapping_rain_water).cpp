#include "leetcode.h"

int Solution::trap(vector<int>& height){
	

	int left = 0, right = height.size() - 1;
	int leftMax = 0, rightMax = 0;

	int ret = 0;

	while (left <= right){

		if (height[left] > leftMax){
			leftMax = height[left];
		}
		if (height[right] > rightMax){
			rightMax = height[right];
		}

		if (leftMax <= rightMax){
			ret += leftMax - height[left];
			left++;
		}
		else{
			ret += rightMax - height[right];
			right--;
		}
	}

	return ret;

}