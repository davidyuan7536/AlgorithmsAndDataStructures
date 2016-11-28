#include "leetcode.h"

int Solution::searchInRotatedSortedArray(vector<int>& nums, int target){

	auto it = is_sorted_until(nums.begin(), nums.end());
	int index = it - nums.begin();


	int left = 0;
	int right = nums.size() - 1;

	int rot = index;

	
	while (left <= right){
		int mid = (left + right) / 2;
		int realmid = (mid + index) % nums.size();
		if (nums[realmid] == target)
			return realmid;
		if (nums[realmid]<target)
			left = mid + 1;
		else right = mid - 1;
	}
	return -1;




}