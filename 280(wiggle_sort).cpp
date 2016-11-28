#include "leetcode.h"

void swap(vector<int> &nums, int a, int b){
	int temp = nums[a];
	nums[a] = nums[b];
	nums[b] = temp;
}

void Solution::wiggleSort(vector<int>& nums){

	if (nums.size() <= 1){
		return;
	}

	bool reverse = false;
	bool changed = true;

	while (changed){
		changed = false;
		reverse = false;
		for (int i = 0; i < nums.size() - 1; i++){

			if (reverse){
				if (nums[i] < nums[i + 1]){
					swap(nums, i, i + 1);
					changed = true;
				}
			}
			else{
				if (nums[i] > nums[i + 1]){
					swap(nums, i, i + 1);
					changed = true;
				}

			}
			reverse = !reverse;
		}
	}
	

}