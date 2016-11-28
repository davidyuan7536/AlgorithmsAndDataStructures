#include "leetcode.h"


bool canPartitionHelper(vector<int> &nums, int index, int target){

	if (target == 0) return true;
	if (target < 0) return false;
	for (int i = index; i < nums.size(); i++)
	if (canPartitionHelper(nums, i + 1, target - nums[i])) 
		return true;
	return false;
}

bool canPartitionHelper2(vector<int> &nums, int target){

	vector<bool>dp(target+1, false);
	dp[0] = true;
	for (int i = 0; i < nums.size(); i++){
		for (int j = target; j >= nums[i]; j--){
			dp[j] = dp[j] || dp[j - nums[i]];
		}

	}
	return dp[target];

}

bool Solution::canPartition(vector<int>& nums){

	int sum = 0;
	for (auto it : nums){
		sum += it;
	}
	if (sum == 0 || sum % 2 != 0){
		return false;
	}
	sum /= 2;
	return canPartitionHelper2(nums, sum);

}