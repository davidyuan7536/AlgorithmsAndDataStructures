#include "leetcode.h"

int min3(int &a, int &b, int &c){
	if (a < b){
		return a < c ? a : c;
	}
	else{
		return b < c ? b : c;
	}
}

int Solution::minDistance(string word1, string word2){
	
	int m = word1.size();
	int n = word2.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	for (int x = 0; x <= m; x++){
		for (int y = 0; y <= n; y++){

			if (x == 0){
				dp[x][y] = y;
				continue;
			}
			if (y == 0){
				dp[x][y] = x;
				continue;
			}

			if (word1[x-1] == word2[y-1]){
				dp[x][y] = dp[x - 1][y - 1];
			}
			else{
				dp[x][y] = 1 + min3(dp[x - 1][y - 1], dp[x][y - 1], dp[x - 1][y]);
			}
			
		}
	}
	return dp[m][n]; 
}