#include "leetcode.h"


int knapsack(vector<int> &nums, int target){

	vector<int> dp(target + 1, 0);

	for (int i = 0; i < nums.size(); i++){
		for (int j = target; j >= nums[i]; j--){

			dp[j] = nums[i] > target ? dp[j] : max(nums[i] + dp[j - nums[i]], dp[j]);
		}

	}

	return dp[target];
}


int Solution::splitArray(vector<int>& nums, int m){

	int sum = accumulate(nums.begin(), nums.end(), 0);
	return sum - knapsack(nums, floor(sum / m));

}