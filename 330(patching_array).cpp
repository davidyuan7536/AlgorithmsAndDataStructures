#include "leetcode.h"


int Solution::minPatches(vector<int>& nums, int n){

	long long last = 0;
	int counter = 0;

	for (int i = 0; i < nums.size() && last < n && nums[i] <= n; i++){
	
		if (nums[i] > last + 1){
			while (last < nums[i]-1){
				last = last + last + 1;
				counter++;
			}
			last += nums[i];
		}
		else {
			last += nums[i];
		}
	}

	while (last < n){
		last = last + last + 1;
		counter++;
	}

	return counter; 
}