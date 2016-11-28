#include "leetcode.h"

int Solution::maxSubArray(vector<int>& nums){

	if (nums.size() == 0){
		return 0;
	}
	if (nums.size() == 1){
		return nums[0];
	}

	vector<int> dp(nums.size(), 0);
	dp[0] = nums[1] > 0 ? nums[1] : 0;

	int maximum = 0;
	bool noPos = true;
	int negMax = INT_MIN;
	for (int x = 0; x != nums.size(); x++){

		dp[x] = max(dp[x - 1] + nums[x], 0);
		if (maximum < dp[x]){
			maximum = dp[x];
			noPos = false;
		}
		if (noPos && negMax < nums[x]){
			negMax = nums[x];
		}


	}

	if (noPos){
		return negMax;
	}
	return maximum;


}