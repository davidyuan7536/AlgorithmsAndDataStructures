#include "leetcode.h"

int Solution::minimumTotal(vector<vector<int>>& triangle){

	vector<vector<int>> dp(triangle.size(), vector<int>{});

	for (int i = 0; i < triangle.size(); i++){
		for (int j = 0; j < triangle[i].size(); j++){
			dp[i].push_back(0);
		}
	}

	for (int i = 0; i < triangle.size(); i++){
		for (int j = 0; j < triangle[i].size(); j++){
			if (i == 0 && j == 0){
				dp[i][j] = triangle[i][j];
				continue;
			}
			
			if (j == 0){
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}
			else if (j == triangle[i].size() - 1){
				dp[i][j] = dp[i - 1][j-1] + triangle[i][j];
			}
			else{
				dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			}
		}
	}

	int min = INT_MAX;
	for (int x = 0; x < dp.back().size(); x++){
		if (dp.back()[x] < min){
			min = dp.back()[x];
		}
	}
	return min;
}