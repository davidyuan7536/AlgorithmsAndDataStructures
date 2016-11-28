#include "leetcode.h"

void permuteHelper(vector<int> &nums, vector<vector<int>> &retVec, int counter){

	if (counter == nums.size()){
		retVec.push_back(nums);
		return;
	}

	for (int x = counter; x != nums.size(); x++){
		swap(nums[counter], nums[x]);
		permuteHelper(nums, retVec, counter+1);
		swap(nums[counter], nums[x]);
	}



}

vector<vector<int>> Solution::permute(vector<int>& nums) {

	vector<vector<int> > ret;
	permuteHelper(nums,ret, 0);
	return ret;

}