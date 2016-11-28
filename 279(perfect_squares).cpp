#include "leetcode.h"

int Solution::numSquares(int n){
	

	vector<int> dp(n+1, 0);

	for (int i = 1; i <= n; i++){

		int cur = 1;
		int mini = INT_MAX;
		while (i >= cur * cur){
			if (i == cur*cur){
				mini = 1;
				break;
			}
			else{
				mini = min(mini, dp[i - (cur * cur)] + 1);
				cur++;
			}
		}
		dp[i] = mini;

	}

	

	return dp[n]; 
}