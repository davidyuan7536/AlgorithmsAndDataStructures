#include "leetcode.h"

int Solution::getMoneyAmount(int n){

	vector<vector<int>> dp(n, vector<int>(n, 0));

	for (int len = 2; len <= n; len++){
		for (int i = 0; i <= n - len; i++){
			int minimum = INT_MAX;
			for (int j = i; j < i + len; j++){
				int curSelection = j + 1;
				int left = j > i ? dp[i][j - 1] : 0;
				int right = j < i + len -1? dp[j + 1][i + len - 1] : 0;
				left = max(left, right);
				minimum = min(minimum, curSelection + left);
			}
			dp[i][i + len - 1] = minimum;
		}
	}

	return dp[0][n - 1];
}