#include "leetcode.h"

int Solution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){

	if (obstacleGrid.empty()){
		return 0;
	}

	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();

	vector<vector<int>> dp(m, vector<int>(n, 0));

	obstacleGrid[0][0] == 1 ? dp[0][0] = 0 : dp[0][0] = 1;

	for (int x = 1; x != m; x++){

		obstacleGrid[x][0] == 1 || dp[x-1][0] == 0 ? dp[x][0] = 0 : dp[x][0] = 1;
	
	}
	for (int y = 1; y != n; y++){
		obstacleGrid[0][y] == 1 ||dp[0][y-1] == 0? dp[0][y] = 0 : dp[0][y] = 1;
	}


	for (int x = 1; x < m; x++){
		for (int y = 1; y < n; y++){
			if (obstacleGrid[x][y] != 1)
				dp[x][y] = dp[x - 1][y] + dp[x][y - 1];
		}
	}

	return dp[m - 1][n - 1];
}