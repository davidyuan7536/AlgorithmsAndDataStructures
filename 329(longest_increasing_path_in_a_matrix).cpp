#include "leetcode.h"

int dfs(vector<vector<int>> &matrix, vector<vector<pair<bool, int>>> &dp, vector<int> &directions, int i, int j){

	int maximum = 1;
	for (int t = 0; t < 4; t++){
		int x = i + directions[t];
		int y = j + directions[t + 1];
		if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[i][j] < matrix[x][y]){
			if (dp[x][y].first){
				maximum = max(dp[x][y].second+1, maximum);
			}
			else{
				maximum = max(dfs(matrix, dp, directions, x, y) + 1, maximum);
			}
		}
	}
	dp[i][j].first = true;
	dp[i][j].second = maximum;
	return maximum;
}


int Solution::longestIncreasingPath(vector<vector<int>>& matrix){

	if (matrix.empty() || matrix[0].empty()){
		return 0;
	}
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<pair<bool, int>>> dp(m, vector<pair<bool, int>>(n, make_pair(false, 0)));
	vector<int> directions{ 0, 1, 0, -1, 0 };
	int maximum = 1;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (dp[i][j].first){
				maximum = max(dp[i][j].second, maximum);
			}
			else{
				maximum = max(maximum, dfs(matrix, dp, directions, i, j));
			}
		}
	}
	return maximum;
}