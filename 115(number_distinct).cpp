#include "leetcode.h"

int Solution::numDistinct(string s, string t){

	if (s.empty() || t.empty())
		return 0;
	if (s.length() < t.length())
		return 0;
	vector<vector<int>> dp(t.length()+1, vector<int>(s.length(), 0));
	for (int x = 0; x < s.length(); x++)
		dp[0][x] = 1;
	for (int i = 1; i <= t.length(); i++){
		for (int j = i-1; j < s.length(); j++){
			if (s[j] == t[i-1])
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i][j - 1];
		}
	}
	return dp[t.length()][s.length()-1];
}