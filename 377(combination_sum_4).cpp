#include "leetcode.h"

int Solution::combinationSum4(vector<int>& nums, int target){

	vector<int> dp(target + 1, 0);

	for (int i = 1; i <= target; i++){

		int sum = 0;
		for (int j = 0; j < nums.size(); j++){
			if (i - nums[j] >= 0){
				sum += dp[i - nums[j]]; 
			}
		}
		dp[i] = sum; 

	}

	return dp[target];

}